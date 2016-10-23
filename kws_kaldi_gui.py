#!/usr/bin/python3
# -*- coding: utf-8 -*-

import subprocess
import os
import sys
from PyQt5.QtWidgets import QLabel, QLineEdit, QGridLayout, QApplication, QPushButton, QMainWindow, QPlainTextEdit
from PyQt5 import QtCore

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.statusBar().showMessage('ready')
        self.filename = QLabel(self)
        self.filename.setText('filename')
        self.filename.move(20, 20)

        self.filename_edit = QLineEdit(self)
        self.filename_edit.move(80, 20)

        self.keywords = QLabel(self)
        self.keywords.setText('keyword')
        self.keywords.move(20, 60)

        self.keywords_edit = QLineEdit(self)
        self.keywords_edit.move(80, 60)

        self.button = QPushButton('search', self)
        self.button.move(20, 100)
        self.button.clicked.connect(self.search_keywords)

        self.setWindowModality(QtCore.Qt.ApplicationModal)
        self.setMaximumSize(300, 200)
        self.setMinimumSize(300, 200)
        self.setGeometry(300, 300, 300, 220)
        self.setWindowTitle('kws kaldi')

        self.error_message = QLabel(self)
        self.result = QLabel(self)

    def search_keywords(self):
        filename_text = self.filename_edit.text()
        keywords_text = self.keywords_edit.text()
        if filename_text == '':
            self.statusBar().showMessage('filename is empty!')
            return
        if not os.path.isfile(filename_text):
            self.statusBar().showMessage('incorrect filename!')
            return
        if keywords_text == '':
            self.statusBar().showMessage('keyword is empty!')
            return
        self.statusBar().showMessage('processing')
        process = subprocess.Popen('GST_PLUGIN_PATH=. ./transcribe-audio_TED.sh ' + str(filename_text),
                                   stdout=subprocess.PIPE, shell=True)
        out, err = process.communicate()
        print(out.decode("utf-8"))
        if keywords_text in out.decode("utf-8"):
            self.result.setText('"' + keywords_text + '"' + ' is in speech')
            self.result.adjustSize()
        else:
            self.result.setText('"' + keywords_text + '"' + ' is not in speech')
            self.result.adjustSize()
        self.result.move(20, 140)
        print(self.filename_edit.text())
        self.statusBar().showMessage('ready')


if __name__ == '__main__':

    app = QApplication(sys.argv)
    mw = MainWindow()
    mw.show()
    sys.exit(app.exec_())