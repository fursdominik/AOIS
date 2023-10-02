class Memory:
    memory = []
    #initialization
    def __init__(self, numbers):
        self.memory = []
        for i in range(len(numbers)):
            self.memory.append(self.toBinary(numbers[i]))

    #sort by search to border
    def sort1(self, number, kind):
        number = self.toBinary(number)
        if kind == 'up':
            result = ['1'] * 16
            for i in range(len(self.memory)):
                if self.match(self.memory[i], number) == 'same':
                    return self.memory[i]
                elif self.match(self.memory[i], number) and self.match(result, self.memory[i]):
                    result = self.memory[i]
        else:
            result = ['0'] * 16
            for i in range(len(self.memory)):
                if self.match(self.memory[i], number) == 'same':
                    return self.memory[i]
                if self.match(number, self.memory[i]) and self.match(self.memory[i], result):
                    result = self.memory[i]
        return result

    #sorting by matching input
    def sort2(self, number):
        number = self.toBinary(number)
        result = 0
        res_counter = 0
        for i in range(len(self.memory)):
            counter = 0
            for j in range(len(number)):
                if self.memory[i][j] == number[j]:
                    counter += 1
            if counter >= res_counter:
                result = self.memory[i]
                res_counter = counter
        return result

    #bits matching function
    def match(self, A, B):
        result = 'same'
        for i in range(len(A)):
            if A[i] == '1' and B[i] == '0':
                return True
            elif A[i] == '0' and B[i] == '1':
                return False
        return result

    #change to binary
    def toBinary(self, number):
        result = list(bin(number))
        del result[1]
        del result[0]
        while len(result) < 16:
            result.insert(0, '0')
        return result

    #printing
    def getMatrix(self):
        for i in range(len(self.memory)):
            string = ''.join(self.memory[i])
            for j in range(len(string)):
                print(string[j], end=' ')
            print('')

    #writing elements
def write(row_data: list):

    f = open('data', 'w')
    s = ''
    for i in range(len(row_data)):
        for j in range(len(row_data[i])):
            s += row_data[i][j] + ','
        s = s[0:len(s)-1:1] + '\n'
        f.write(s)
        s = ''
    f.close()
    return 1

def copy_data():
        data = open("newfile.txt", "r")
        new_data = open("datafile.txt", "w")

        k = int(data.readline())
        new_data.write(str(k) + '\n')
        for i in range(0, k):
            new_data.write(str(data.readline()))
            new_data.write(str(data.readline()))
        data.close()
        new_data.close()

def idn(self) -> None:
        self._tab += self._indent
        self._scope.append([])

def udn(self) -> None:
        self._tab -= self._indent
        self._scope.pop()

def insc(self, name: str):
    for i in self._scope:
        for j in i:
            if j == name: return True
    return False

def add_objects(category):
    start_point = input('Start point: ')
    category.append_object(start_point)

def sub_value(self, other: object) -> "Matrix":
        for i in range(self._width):
            for j in range(self._height):
                self.set(i, j, self._matrix[i][j] - other)
        return self

def pow_value(self):
        for i in range(self._width):
            for j in range(self._height):
                self.set(i, j, self._matrix[i][j] ** other)
        return self

if __name__ == '__main__':
    res = Memory([255, 6212, 2341, 23421, 7593, 20, 1234, 8139, 50000, 1, 42690, 15278, 32190, 1313, 24458, 36423])
    input1 = 8000
    result1 = ''.join(res.sort1(input1, 'up'))
    print(f'Enter to search by nearest above: {input1}')
    input1 = ''.join(res.toBinary(input1))
    print(f'Enter to search by nearest above: {input1}')
    print(f'Result to search by nearest above: {result1} or {int(result1, 2)}')

    print('-'*100)

    input2 = 8000
    result2 = ''.join(res.sort1(input2, 'down'))
    print(f'Enter to search by nearest below: {input2}')
    input2 = ''.join(res.toBinary(input2))
    print(f'Enter to search by nearest below: {input2}')
    print(f'Result to search by nearest below: {result2} or {int(result2, 2)}')

    print('-' * 100)

    input3 = 15000
    result3 = ''.join(res.sort2(input3))
    print(f'Enter to search by matching: {input3}')
    input3 = ''.join(res.toBinary(input3))
    print(f'Enter to search by matching: {input3}')
    print(f'Result to search by matching: {result3} or {int(result3, 2)}')
    print('Matrix:')
    res.getMatrix()