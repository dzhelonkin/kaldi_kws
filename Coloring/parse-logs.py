import sys
from path import path

d = path(sys.argv[1])

tim = {}
sol = {}

for i in [0, 1]:
    for f in d.files("*.dom.log"+str(i)+"-14"):
        log = open(f,'r')
        ist = f.split('/')[5].split(".col")[0]
        if ist not in tim:
            tim[ist] = []
            sol[ist] = []
        for line in log:
            l = line.strip().split(' ')
            if l[0] == "Nodes":
                if float(l[3]) > 300.0:
                    tim[ist].append( 300 )
                else:
                    tim[ist].append( l[3] )
            if l[0] == "X(G)":
                sol[ist].append( l[2] )

print "Istance NoSym LDBS"
for d,t in sorted(tim.iteritems()):
    if t:
        if len(t) == 2:
            print d, t[0], t[1]
