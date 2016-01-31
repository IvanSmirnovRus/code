import sys

firstLine = True
noN = True
lines = []
for line in sys.stdin:
    if firstLine:
        if '-n' not in line:
            n = 10
        else:
            noN = False
            n = int(line.rstrip().split()[1])
        firstLine = False
    else:
        lines.append(line.rstrip())


for i, line in enumerate(lines):
    if i >= (len(lines) - n):
        print line
