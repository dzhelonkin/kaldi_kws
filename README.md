# Keyword spotting by Kaldi library

## Подготовка к работе

* Выполнить пункты из инструкции `how_to_install.txt` (установить kaldi и gst-kaldi-nnet2-online, скачать подготовленную нейронную сеть, обученную на англоязычных записях передачи TED).
* Для проверки запустить
```
cd /path/to/gst-kaldi-nnet2-online/demo
GST_PLUGIN_PATH=. ./transcribe-audio_TED.sh bill_gates-TED.mp3
```

в выводе должен быть примерно такой текст(ниже представлен истинный текст):
> When I was a kid, the disaster we worried about most was a nuclear war. That's why we had a barrel like this down in our basement, filled with cans of food and water. When the nuclear attack came, we were supposed to go downstairs, hunker down, and eat out of that barrel.
> Today the greatest risk of global catastrophe doesn't look like this. Instead, it looks like this. If anything kills over 10 million people in the next few decades, it's most likely to be a highly infectious virus rather than a war. Not missiles, but microbes. Now, part of the reason for this is that we've invested a huge amount in nuclear deterrents. But we've actually invested very little in a system to stop an epidemic. We're not ready for the next epidemic.

## Поиск ключевого слова в mp3 файле

Для графического интерфейса выполнить
`python3 kws_kaldi_gui.py`

В программе ввести путь до файла и ключевое слово, которое нужно найти, нажать на кнопку search


## Поиск ключевых слов и их подсчет в онлайн потоке

Для лучшего качества распознавания рекомендуется использовать микрофон.

Необходимо скопировать файл word_count.py в папку gst-kaldi-nnet2-online/demo
Затем запустить его следующей командой:
`GST_PLUGIN_PATH=../src/ ./word_count.py`

В открывшемся окне в поле 'key-word/key-phrase' введите слова, разделенные пробелом, которые нужно искать в тексте.
Нажмите кнопку 'Speak' и произносите слова (используется модель для английского языка). Программа будет искать и 
подсчитывать указанные слова в отдельном окне 'Key-word'. Количество слов указываются для цепочки. Цепочка это слова
разделенные паузой меньше 1c. Обработка будет происходить параллельно вводу, но с отстванием. Что бы закончить 
считывание потока, нужно нажать на кнопку 'stop'. Программа закончит вычисления по цепочкам и все результаты будут 
выведены в окне.


## Эксперимент

Для оценки качества распознования речи и сравнения различных подходов к решению данной проблемы был проведен экперимент по распознованию нескольких звуковых файлов. Детальное описание эксперимента можно найти в файле experiment.txt

С результатами можно ознакомиться в таблице ниже:

   Dataset     | gmm (WRR / WER) | nnet2 (WRR / WER) |  
  :----| :-----: | :----:    | 
  american fairy tales  | 71.494498 % (2014/2817) / 30.280440% (853/2817) | 87.646432% (2469/2817) / 14.625488 % (412/2817) |
  andersens fairy tales (part 1) | 63.936170% (1202/1880) / 40.106383% (754/1880) | 84.361702% (1586/1880) / 19.787234% (372/1880) |
  andersens fairy tales (part 18) | 64.489311% (543/842) / 37.173397% (313/842) | 78.503563% (661/842) / 24.584323% (207/842) |


## Лицензии

Открытым кодом Kaldi можно пользоваться в рамках Apache License v2.0 (http://kaldi-asr.org/doc/about.html)


