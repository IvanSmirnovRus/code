import itertools
import sys
for line in sys.stdin:
    first, second = line.rstrip().split()
A = len(first)
B = len(second)
res = []
for i in xrange(A):
    res.append(1)
for i in xrange(B):
    res.append(2)
n = 0
rr = []
for i in set(itertools.permutations(res)):
	n += 1
	it1 = iter(first)
	it2 = iter(second)
	r = []
	for ii in i:
		if ii == 1:
			r.append(it1.next())
		else:
			r.append(it2.next())
	rr.append(''.join(r))
l = set(rr)
g = sorted(l)
for i in g:
	print i