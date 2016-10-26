import subprocess
import sys
import datetime

if __name__ == "__main__":

    f = open(sys.argv[2], 'r')

    tstr=''
    for line in f:
        tstr += line

    print 'Words in audio file - ' + sys.argv[1]+':'
    orig_words = tstr.split()
    print orig_words

    cmd = './transcribe-audio.sh ' + sys.argv[1]
    PIPE = subprocess.PIPE
    p = subprocess.Popen(cmd, shell=True, stdin=PIPE, stdout=PIPE, stderr=subprocess.STDOUT)
    p.wait()

    print 'ready'

    tstr=''
    pr=False
    find_words = []
    
    while True:
        s = p.stdout.readline()
        
        if not s:
            break

        if(pr is True):
            tstr+= s

        if(s.find('Done') <> -1):
            pr=True
        
    rec_words = tstr.split()

    find_words = []
    unrec_words = []
    
    for word in orig_words:
        if word in rec_words:
            find_words.append(word)
        else:
            unrec_words.append(word)

    print "+++Recognised words+++"
    for word in find_words:
        print word

    print "---Unrecognised words---"
    for word in unrec_words:
       print word

    print "***Unknown words***"
    for word in rec_words:
        if word not in orig_words:
           print word

    print "Percent of recognised words - ", float(len(find_words))/float(len(orig_words))*100.0 




       
