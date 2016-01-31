import collections
import sys 
langs = {}
c = collections.Counter()
results = []
for line in sys.stdin:
    fio, task, time, lang, result = line.rstrip().split('\t')
    if result == 'OK':
        if lang not in langs:
            langs[lang] = [task]
            c[lang] = 1
        else:
            if task not in langs[lang]:
                langs[lang].append(task)
                c[lang] += 1

for k, v in c.most_common():
    results.append((k, v))


def comp(x, y):
    if x[1] < y[1]:
        return 1
    elif x[1] == y[1]:
        if x[0] > y[0]:
            return 1
        else:
            return -1
    else:
        return -1
t = sorted(results, cmp=comp, reverse=False)
for k, v in t:
    print str(k) + ' ' + str(v)