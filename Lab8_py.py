import copy

class Memory:

    def __init__(self, numbers):
        self.memory = []
        self.matrix_vertically = [['x'] * 16 for i in range(16)]
        self.matrix_horisontally = []
        for i in range(len(numbers)):
            self.memory.append(self.toBinary(numbers[i]))
        print('Normal matrix:')
        self.getMatrix(self.memory)
        self.diagonal_addressation_horisontal()
        self.diagonal_addressation_vertical()
        self.v = '011'


    def search(self, number, kind_matrix):
        number = self.toBinary(number)
        result = 0
        res_counter = 0
        if kind_matrix == 'normal':
            for i in range(len(self.memory)):
                counter = 0
                for j in range(len(number)):
                    if self.memory[i][j] == number[j]:
                        counter += 1
                if counter > res_counter:
                    result = self.memory[i]
                    res_counter = counter
        elif kind_matrix == 'horisontal':
            for i in range(len(self.matrix_horisontally)):
                counter = 0
                value = self.read_horisontal(self.matrix_horisontally[i])
                for j in range(len(number)):
                    if value[j] == number[j]:
                        counter += 1
                if counter > res_counter:
                    result = value
                    res_counter = counter
        elif kind_matrix == 'vertical':
            for i in range(len(self.matrix_vertically)):
                counter = 0
                value = self.read_vertical(self.matrix_vertically[i])
                for j in range(len(number)):
                    if value[j] == number[j]:
                        counter += 1
                if counter > res_counter:
                    result = value
                    res_counter = counter
        return result

    def toBinary(self, number):
        result = list(bin(number))
        del result[1]
        del result[0]
        while len(result) < 16:
            result.insert(0, '0')
        return result

    def getMatrix(self, matrix):
        for i in range(len(matrix)):
            string = ''.join(matrix[i])
            for j in range(len(string)):
                print(string[j], end=' ')
            print('')
        print('')

    def get_now_status(self):
        file = open('now_in_process', 'r')
        line = file.read()
        if line.stat('now_in_process').st_size == 0:
            return False
        return bool(line.split('\n')[0])

    def diagonal_addressation_vertical(self):
        self.matrix_vertically = [['x']*16 for i in range(16)]
        for y in range(len(self.memory)):
            for x in range(len(self.memory[0])):
                if y+x <= 15:
                    self.matrix_vertically[y + x][x] = self.memory[y][x]
                else:
                    value_y = (y + x)-16
                    value_x = -abs(16-x)
                    self.matrix_vertically[value_y][value_x] = self.memory[y][x]
        print('Matrix in vertical diagonal addressation:')
        self.getMatrix(self.matrix_vertically)

    def diagonal_addressation_horisontal(self):
        for y in range(len(self.memory)):
            self.matrix_horisontally.append([])
            for x in range(len(self.memory[y])):
                if x < y:
                    self.matrix_horisontally[-1].append(self.memory[y][x])
                else:
                    self.matrix_horisontally[-1].insert(x-y, self.memory[y][x])
        print('Matrix in horisontal diagonal addressation:')
        self.getMatrix(self.matrix_horisontally)

    def update_value(self, inst):
        self.text = '$s.%s.%s'%tuple(self.cal.active_date)
        self.focus=False

    def read_vertical(self, address):
        result = []
        for x in range(len(self.memory[0])):
            if address + x <= 15:
                result.append(self.matrix_vertically[address + x][x])
            else:
                value_y = (address + x)-16
                value_x = -abs(16-x)
                result.append(self.matrix_vertically[value_y][value_x])
        return result

    def read_horisontal(self, address):
        result = []
        for x in range(len(self.matrix_horisontally[address])):
            if x >= 16-address:
                result.insert(0, self.matrix_horisontally[address][x])
            else:
                result.append(self.matrix_horisontally[address][x])
        return result

    def constant(self):
        print('Constant: ', end='')
        print(''.join(['0']*16))

    def constant1(self):
        print('Constant 1: ', end='')
        print(''.join(['1']*16))

    def repeat_argument(self, address, kind_matrix):
        if kind_matrix == 'normal':
            print('Repeat argument: ', end='')
            print(''.join(self.memory[address - 1]))
        elif kind_matrix == 'vertical':
            value = self.read_vertical(address)
            print('Repeat argument: ', end='')
            print(''.join(value))
        elif kind_matrix == 'horisontal':
            value = self.read_horisontal(address)
            print('Repeat argument: ', end='')
            print(''.join(value))

    def negating_argument(self, address, kind_matrix):
        value = 0
        if kind_matrix == 'normal':
            value = self.memory[address]
        elif kind_matrix == 'vertical':
            value = self.read_vertical(address)
        elif kind_matrix == 'horisontal':
            value = self.read_horisontal(address)

        for i in range(len(value)):
            if value[i] == '1':
                value[i] = '0'
            else:
                value[i] = '1'

        print('Negating argument: ', end='')
        print(''.join(value))

    def sum(self):
        for i in range(len(self.memory)):
            vj = []
            for j in range(3):
                vj.append(self.memory[i][j])

            if ''.join(vj) == self.v:
                aj = []
                bj = []
                sj = []
                j = 3
                while j < 7:
                    aj.append(self.memory[i][j])
                    j += 1
                while j < 11:
                    bj.append(self.memory[i][j])
                    j += 1
                carry = False
                j = 3
                while j >= 0:
                    if aj == '1' and bj == '0' and carry is False:
                        sj.insert(0, '1')
                        j -= 1
                    elif aj == '0' and bj == '1' and carry is False:
                        sj.insert(0, '1')
                        j -= 1
                    elif aj == '1' and bj == '1' and carry is True:
                        sj.insert(0, '1')
                        j -= 1
                    elif aj == '0' and bj == '0' and carry is True:
                        sj.insert(0, '1')
                        carry = False
                        j -= 1
                    else:
                        sj.insert(0, '0')
                        j -= 1
                if carry:
                    sj.insert(0, '1')
                else:
                    sj.insert(0, '0')
                j = 11
                result = copy.deepcopy(self.memory[i])
                while j < 16:
                    result[j] = sj[j - 11]
                    j += 1
                print('Sum: ', end='')
                print(''.join(result))

if __name__ == '__main__':
    res = Memory([255, 6212, 2341, 23421, 7593, 20, 1234, 8139, 50000, 1, 42690, 15278, 32190, 1313, 24458, 36423])
    enter = 6
    res.constant()
    res.constant1()
    print('From normal matrix: ', end='')
    print(''.join(res.memory[enter]))
    print(f'Read horisontal: {res.read_horisontal(enter)}')
    print(f'Read vertical: {res.read_vertical(enter)}')
    res.negating_argument(enter, 'vertical')
    res.negating_argument(enter, 'horisontal')
    res.repeat_argument(enter, 'vertical')
    res.repeat_argument(enter, 'horisontal')
    res.sum()