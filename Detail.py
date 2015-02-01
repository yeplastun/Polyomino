class Detail:

    def __init__(self, number):
        self.data = []
        if number == 1:
            self.color = 0
            self.num = number
            self.height = 3
            self.length = 3
            self.before = 0
            self.after = -1
            self.data.append([0, 1])
            self.data.append([1, 0])
            self.data.append([1, 1])
            self.data.append([1, 2])
            self.data.append([2, 1])
        elif number == 2:
            self.color = 0
            self.num = number
            self.height = 1
            self.length = 5
            self.before = 1
            self.after = -1
            self.data.append([0, 0])
            self.data.append([0, 1])
            self.data.append([0, 2])
            self.data.append([0, 3])
            self.data.append([0, 4])
        elif number == 3:
            self.color = 1
            self.num = number
            self.height = 2
            self.length = 2
            self.before = 1
            self.after = -1
            self.data.append([0, 0])
            self.data.append([0, 1])
            self.data.append([1, 0])
            self.data.append([1, 1])
        elif number == 4:
            self.color = 1
            self.num = number
            self.height = 3
            self.length = 3
            self.before = 3
            self.after = -1
            self.data.append([0, 0])
            self.data.append([0, 1])
            self.data.append([0, 2])
            self.data.append([1, 0])
            self.data.append([2, 0])
        elif number == 5:
            self.color = 1
            self.num = number
            self.height = 3
            self.length = 3
            self.before = 1
            self.after = 1
            self.data.append([0, 0])
            self.data.append([0, 1])
            self.data.append([1, 1])
            self.data.append([2, 1])
            self.data.append([2, 2])
        elif number == 6:
            self.color = 0
            self.num = number
            self.height = 3
            self.length = 3
            self.before = 3
            self.after = -1
            self.data.append([0, 0])
            self.data.append([1, 0])
            self.data.append([1, 1])
            self.data.append([1, 2])
            self.data.append([2, 0])
        elif number == 7:
            self.color = 0
            self.num = number
            self.height = 3
            self.length = 3
            self.before = 3
            self.after = -1
            self.data.append([0, 1])
            self.data.append([0, 2])
            self.data.append([1, 0])
            self.data.append([1, 1])
            self.data.append([2, 0])
        elif number == 8:
            self.color = 1
            self.num = number
            self.height = 2
            self.length = 3
            self.before = 3
            self.after = -1
            self.data.append([0, 0])
            self.data.append([0, 1])
            self.data.append([0, 2])
            self.data.append([1, 0])
            self.data.append([1, 2])
        elif number == 9:
            self.color = 0
            self.num = number
            self.height = 4
            self.length = 2
            self.before = 3
            self.after = 3
            self.data.append([0, 0])
            self.data.append([1, 0])
            self.data.append([2, 0])
            self.data.append([2, 1])
            self.data.append([3, 0])
        elif number == 10:
            self.color = 1
            self.num = number
            self.height = 4
            self.length = 2
            self.before = 3
            self.after = 3
            self.data.append([0, 0])
            self.data.append([1, 0])
            self.data.append([2, 0])
            self.data.append([3, 0])
            self.data.append([3, 1])
        elif number == 11:
            self.color = 1
            self.num = number
            self.height = 4
            self.length = 2
            self.before = 3
            self.after = 3
            self.data.append([0, 1])
            self.data.append([1, 0])
            self.data.append([1, 1])
            self.data.append([2, 0])
            self.data.append([3, 0])
        elif number == 12:
            self.color = 1
            self.num = number
            self.height = 3
            self.length = 3
            self.before = 3
            self.after = 3
            self.data.append([0, 1])
            self.data.append([1, 0])
            self.data.append([1, 1])
            self.data.append([1, 2])
            self.data.append([2, 2])
        elif number == 13:
            self.color = 0
            self.num = number
            self.height = 2
            self.length = 3
            self.before = 3
            self.after = 3
            self.data.append([0, 0])
            self.data.append([0, 1])
            self.data.append([0, 2])
            self.data.append([1, 0])
            self.data.append([1, 1])

    def turn(self):
        for i in range(len(self.data)):
            self.data[i][0] = self.height - 1 - self.data[i][0]
            self.data[i][0], self.data[i][1] = self.data[i][1], self.data[i][0]
        if self.height % 2 == 0:
            if self.color == 1:
                self.color = 0
            if self.color == 0:
                self.color = 1
        self.length, self.height = self.height, self.length

    def reflect(self):
        for i in range(len(self.data)):
            self.data[i][1] = self.length - self.data[i][1] - 1
        if self.length % 2 == 0:
            if self.color == 1:
                self.color = 0
            if self.color == 0:
                self.color = 1

    def show(self):
        for i in range(self.height):
            s = ""
            for j in range(self.length):
                b = [item for item in range(len(self.data)) if self.data[item] == [i, j]]
                if len(b) > 0:
                    if self.num > 9:
                        s += ' ' + str(self.num)
                    else:
                        s += '  ' + str(self.num)
                else:
                    s += '  ' + str(0)
            print s
