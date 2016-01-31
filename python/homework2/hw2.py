import sys
import collections


class Ocean(object):
    def __init__(self, length, width):
        self.length = length
        self.width = width
        self.ocean = [[0 for i in xrange(width)] for i in xrange(length)]

    def fill(self, y, x, obj):
        self.ocean[y][x] = obj

    def get_neighbors(self, y, x):
        neighbors = collections.Counter()
        for i in range(-1, 2):
            for j in range(-1, 2):
                if 0 <= y + i < self.length and 0 <= x + j < self.width and \
                   (i != 0 or j != 0):
                    neighbors[self.ocean[y + i][x + j]] += 1
        return neighbors

    def get_object(self, y, x):
        return self.ocean[y][x]

    def __str__(self):
        lines = []
        for i in xrange(self.length):
            line = []
            for j in xrange(self.width):
                line.append(str(self.get_object(i, j)))
            lines.append(' '.join(line))
        return '\n'.join(lines)


def read_input():
    y, x = map(int, sys.stdin.readline().rstrip('\n').split())
    my_ocean = Ocean(y, x)
    for i, line in enumerate(sys.stdin):
        for j, column in enumerate(line.rstrip('\n').split()):
            my_ocean.fill(i, j, int(column))
    return my_ocean


def make_step(ocean):
    new_ocean = Ocean(ocean.length, ocean.width)
    for i in xrange(ocean.length):
        for j in xrange(ocean.width):
            neighbors = ocean.get_neighbors(i, j)
            obj = ocean.get_object(i, j)
            if obj == 1:
                new_ocean.fill(i, j, 1)
            elif obj == 0:
                if neighbors[2] == 3:
                    new_ocean.fill(i, j, 2)
                elif neighbors[2] != 3 and neighbors[3] == 3:
                    new_ocean.fill(i, j, 3)
            else:
                if neighbors[obj] > 3 or neighbors[obj] < 2:
                    new_ocean.fill(i, j, 0)
                else:
                    new_ocean.fill(i, j, obj)
    return new_ocean


def main():
    steps = int(sys.stdin.readline().rstrip('\n'))
    my_ocean = read_input()
    while(steps > 0):
        my_ocean = make_step(my_ocean)
        steps -= 1
    print my_ocean

if __name__ == '__main__':
    main()
