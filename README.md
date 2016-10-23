### Keyword spotting by Kaldi library

## Подготовка к работе

* Выполнить пункты из инструкции `how_to_install.txt` установить kaldi и gst-kaldi-nnet2-online, скачать подготовленную нейронную сеть, обученную на англоязычных записях передачи TED.
* Для проверки запустить
```
cd /path/to/rep/
GST_PLUGIN_PATH=. ./transcribe-audio_TED.sh bill_gates-TED.mp3
```

в выводе должен быть примерно такой текст(ниже представлен истинный текст):
```
When I was a kid, the disaster we worried about most was a nuclear war. That's why we had a barrel like this down in our basement, filled with cans of food and water. When the nuclear attack came, we were supposed to go downstairs, hunker down, and eat out of that barrel. Today the greatest risk of global catastrophe doesn't look like this. Instead, it looks like this. If anything kills over 10 million people in the next few decades, it's most likely to be a highly infectious virus rather than a war. Not missiles, but microbes. Now, part of the reason for this is that we've invested a huge amount in nuclear deterrents. But we've actually invested very little in a system to stop an epidemic. We're not ready for the next epidemic.
```

## Поиск ключевого слова в mp3 файле

Для запуска выполнить
`python3 kws_kaldi_gui.py`

В программе ввести путь до файла и ключевое слово, которое нужно найти, нажать на кнопку search





