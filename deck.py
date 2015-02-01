# coding=utf-8

class Cell(object):
    def __init__(self, v, c):
        self.value = v
        self.color = c


class Deck(object):
    def __init__(self):
        self.deck_size = 8
        self._deck = []
        self._clean()

    def solve(self):
        pass

    def _clean(self):
        self._deck = []
        for i in range(self.deck_size):
            self._deck.append([Cell(0, 1 - (i + j % 2)) for j in range(self.deck_size)])

    def show(self):
        print "/---------------------/"
        for i in range(self.deck_size):
            for j in range(self.deck_size):
                if self._deck[i][j].value / 10 != 0:
                    print "%s " % self._deck[i][j].value,
                else:
                    print " * " if not self._deck[i][j].value else " %s " % self.deck_size[i][j].value,
            print
        print "/---------------------/"

    def bust(self):
        pass

    def attach(self, x, y, detail):
        pass
