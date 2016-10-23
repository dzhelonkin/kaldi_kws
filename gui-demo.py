#!/usr/bin/env python3
#
# Copyright (c) 2013 Tanel Alumae
# Copyright (c) 2008 Carnegie Mellon University.
#
# Inspired by the CMU Sphinx's Pocketsphinx Gstreamer plugin demo (which has BSD license)
#
# Licence: BSD

import sys
import os
import gi
from json import loads as j_loads
from json import load as j_load
from tkinter import *
from tkinter import ttk
from tkinter import filedialog, messagebox

gi.require_version('Gst', '1.0')
from gi.repository import GObject, Gst, Gtk, Gdk
GObject.threads_init()
Gdk.threads_init()

Gst.init(None)

class DemoApp(object):
    """GStreamer/Kaldi Demo Application"""
    def __init__(self):
        """Initialize a DemoApp object"""
        self.init_gui()
        self.init_gst()

    def init_gui(self):
        """Initialize the GUI components"""
        self.window = Gtk.Window()
        self.window.connect("destroy", self.quit)
        self.window.set_default_size(600,400)
        self.window.set_border_width(10)
        self.window.set_title("Online key-word finding")
        vbox1 = Gtk.VBox()
        vbox2 = Gtk.VBox()
        hbox  = Gtk.HBox()
        self.text_label = Gtk.Label("Recognized text")
        vbox1.pack_start(self.text_label, False, False, 1)
        self.text = Gtk.TextView()
        self.textbuf = self.text.get_buffer()
        self.text.set_wrap_mode(Gtk.WrapMode.WORD)
        vbox1.pack_start(self.text, True, True, 1)
        self.button = Gtk.Button("Speak")
        self.button.connect('clicked', self.button_clicked)
        vbox1.pack_start(self.button, False, False, 5)
        phrase_label = Gtk.Label("Key-word/key-phrase")
        vbox2.pack_start(phrase_label, False, False, 1)
        self.keywords_field = Gtk.Entry()
        vbox2.pack_start(self.keywords_field, False, False, 1)
        phrase_label = Gtk.Label("Key-word(number of occurences)")
        vbox2.pack_start(phrase_label, False, False, 1)
        self.phrase = Gtk.TextView()
        self.phrasebuf = self.phrase.get_buffer()
        self.phrase.set_wrap_mode(Gtk.WrapMode.WORD)
        vbox2.pack_start(self.phrase, True, True, 1)
        hbox.pack_start(vbox1, True, True, 1)
        hbox.pack_start(vbox2, True, True, 1)
        self.window.add(hbox)
        self.window.show_all()
        
    def quit(self, window):
        Gtk.main_quit()

    def init_gst(self):
        """Initialize the speech components"""
        self.pulsesrc = Gst.ElementFactory.make("pulsesrc", "pulsesrc")
        if self.pulsesrc == None:
            print >> sys.stderr, "Error loading pulsesrc GST plugin. You probably need the gstreamer1.0-pulseaudio package"
            sys.exit()	
        self.audioconvert = Gst.ElementFactory.make("audioconvert", "audioconvert")
        self.audioresample = Gst.ElementFactory.make("audioresample", "audioresample")    
        self.asr = Gst.ElementFactory.make("kaldinnet2onlinedecoder", "asr")
        self.fakesink = Gst.ElementFactory.make("fakesink", "fakesink")
        
        if self.asr:
          model_file = "final.mdl"
          if not os.path.isfile(model_file):
              print >> sys.stderr, "Models not downloaded? Run prepare-models.sh first!"
              sys.exit(1)
          self.asr.set_property("fst", "HCLG.fst")
          self.asr.set_property("model", "final.mdl")
          self.asr.set_property("word-syms", "words.txt")
          self.asr.set_property("feature-type", "mfcc")
          self.asr.set_property("mfcc-config", "conf/mfcc.conf")
          self.asr.set_property("ivector-extraction-config", "conf/ivector_extractor.fixed.conf")
          self.asr.set_property("max-active", 7000)
          self.asr.set_property("beam", 10.0)
          self.asr.set_property("lattice-beam", 6.0)
          self.asr.set_property("do-endpointing", True)
          self.asr.set_property("do-phone-alignment", True)
          self.asr.set_property("num-nbest", 10)
          self.asr.set_property("endpoint-silence-phones", "1:2:3:4:5:6:7:8:9:10")
          self.asr.set_property("use-threaded-decoder", False)
          self.asr.set_property("chunk-length-in-secs", 1.0)
        else:
          print >> sys.stderr, "Couldn't create the kaldinnet2onlinedecoder element. "
          if os.environ.has_key("GST_PLUGIN_PATH"):
            print >> sys.stderr, "Have you compiled the Kaldi GStreamer plugin?"
          else:
            print >> sys.stderr, "You probably need to set the GST_PLUGIN_PATH envoronment variable"
            print >> sys.stderr, "Try running: GST_PLUGIN_PATH=../src %s" % sys.argv[0]
          sys.exit();
        
        # initially silence the decoder
        self.asr.set_property("silent", True)
        
        self.pipeline = Gst.Pipeline()
        for element in [self.pulsesrc, self.audioconvert, self.audioresample, self.asr, self.fakesink]:
            self.pipeline.add(element)         
        self.pulsesrc.link(self.audioconvert)
        self.audioconvert.link(self.audioresample)
        self.audioresample.link(self.asr)
        self.asr.link(self.fakesink)    
  
        self.asr.connect('partial-result', self._on_partial_result)
        self.asr.connect('final-result', self._on_final_result) 
        self.asr.connect('full-final-result', self._on_full_final_result)       
        self.pipeline.set_state(Gst.State.PLAYING)

    def _on_partial_result(self, asr, hyp):
        """Delete any previous selection, insert text and select it."""
        Gdk.threads_enter()
        # All this stuff appears as one single action
        self.textbuf.begin_user_action()
        self.textbuf.delete_selection(True, self.text.get_editable())
        self.textbuf.insert_at_cursor(hyp)
        ins = self.textbuf.get_insert()
        iter = self.textbuf.get_iter_at_mark(ins)
        iter.backward_chars(len(hyp))
        self.textbuf.move_mark(ins, iter)
        self.textbuf.end_user_action()    
        Gdk.threads_leave()
                
    def _on_final_result(self, asr, hyp):
        Gdk.threads_enter()
        """Insert the final result."""
        # All this stuff appears as one single action
        self.textbuf.begin_user_action()
        self.textbuf.delete_selection(True, self.text.get_editable())
        self.textbuf.insert_at_cursor(hyp)
        if (len(hyp) > 0):
            self.textbuf.insert_at_cursor(" ")
        self.textbuf.end_user_action()
        Gdk.threads_leave()

    def _on_full_final_result(self, _, json_str):
        Gdk.threads_enter()
        if self.keywords != "":
            #prev_text = self.phrasebuf.get_text()
            string = "----------------------------\n"
            json_data = j_loads(json_str)
            transcript = json_data["result"]["hypotheses"][0]['transcript']
            for word in self.keywords.split():
                cnt = transcript.count(word)
                substring = word + " (" + str(cnt) + ")\n"
                string += substring

            self.phrasebuf.begin_user_action()
            self.phrasebuf.insert_at_cursor(string)
            self.phrasebuf.end_user_action() 
        Gdk.threads_leave()
        
    def button_clicked(self, button):
        """Handle button presses."""
        if button.get_label() == "Speak":
            button.set_label("Stop")
            self.asr.set_property("silent", False)
            self.keywords = self.keywords_field.get_text()
            self.textbuf.set_text("")
            self.phrasebuf.set_text("")
        else:
            button.set_label("Speak")
            #self.asr.emit("full-final-result",string)
            self.asr.set_property("silent", True)
            

if __name__ == '__main__':
  app = DemoApp()
  Gdk.threads_enter()
  Gtk.main()
  Gdk.threads_leave()

