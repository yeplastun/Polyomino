# coding=utf-8

class Detail:
    pass

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
    	detail = Detail(1);
    	attach(self, 0, 0,  detail)
    	bust(self, 1)
    	_clean(self)
    	attach(self, 0, 1, detail)
    	bust(self, 1)
    	_clean(self)
    	attach(self, 1, 1, detail)
    	bust(self, 1)
    	_clean(self)
    	attach(self, 0, 2, detail)
    	bust(self, 1)
    	_clean(self)
    	attach(self, 1, 2, detail)
    	bust(self, 1)
    	_clean(self)
    	attach(self, 2, 2, detail)
    	bust(self, 1)
    	_clean(self)

    def _clean(self):
        self._deck = []
        for i in range(self.deck_size):
            self._deck.append([Cell(0, 1 - (i + j % 2)) for j in range(self.deck_size)])

    def show(self):
        print "/---------------------/"
        for i in range(self.deck_size):
            for j in range(self.deck_size):
                if self._deck[i][j].value / 10 != 0:
                    print "%s " % self._deck[i][j].value, # why coma? and what's is %s
                else:
                    print " * " if not self._deck[i][j].value else " %s " % self.deck_size[i][j].value,
            print
        print "/---------------------/"

    def bust(self, used):
        det = Detail(used+1)
        for i in range(det.before+1):
            for k in range(deck_size-det.height+1):
                for l in range(deck_size-det.length+1):
                    if attach(self, k, l, det):
                        if used == 12:
                            show(self)
                            return 1
                        else:
                            if bust(used+1):
                                return 1
                        for i in range(self.deck_size):
                            for j in range(self.seck_size):
                                if self._deck[i][j].value == det.color:
                                    self._deck[i][j].value = 0
        if det.after > -1:
            reflect(det)
            for i in range(det.after+1):
                for k in range(deck_size-det.height+1):
                    for l in range(deck_size-det.length+1):
                        if attach(self, k, l, det):
                            if used == 12:
                                show(self)
                                return 1
                            else:
                                if bust(used+1):
                                    return 1
                            for i in range(self.deck_size):
                                for j in range(self.seck_size):
                                    if self._deck[i][j].value == det.color:
                                        self._deck[i][j].value = 0
            turn(det)


    def attach(self, x, y, detail):
        if self._deck[x][y].color != detail.color:
            return 0
        for i in range(detail.data.size()):
            if self._deck[x+detail.data[i][0]][y+detail.data[i][1]].value == 0:
                self._deck[x+detail.data[i][0]][y+detail.data[i][1]].value = detail.num
            else:
                for j in range(i):
                    data[x+detail.data[j][0]][y+detail.data[j][1]] = 0
                return 0
        return 1