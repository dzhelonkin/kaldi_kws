#!/bin/bash

audio=$1

path=/home/dzhelonkin/kaldi/gst-kaldi/gst-kaldi-nnet2-online/models/english/tedlium_nnet_ms_sp_online

GST_PLUGIN_PATH=../src gst-launch-1.0 --gst-debug="" -q filesrc location=$audio ! decodebin ! audioconvert ! audioresample ! \
kaldinnet2onlinedecoder \
  use-threaded-decoder=true \
  model=$path/final.mdl \
  fst=$path/HCLG.fst \
  word-syms=$path/words.txt \
  feature-type=mfcc \
  mfcc-config=$path/conf/mfcc.conf \
  ivector-extraction-config=$path/conf/ivector_extractor.conf \
  max-active=10000 \
  beam=10.0 \
  lattice-beam=6.0 \
  acoustic-scale=0.083 \
  traceback-period-in-secs=0.25 \
  do-endpointing=true \
  endpoint-silence-phones="1:2:3:4:5:6:7:8:9:10" \
  chunk-length-in-secs=0.25 \
! filesink location=/dev/stdout buffer-mode=2
