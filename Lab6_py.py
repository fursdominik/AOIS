class Node:
	def __init__(self, name, info, value, hash):
		self.info = info
		self.name = name
		self.value = value
		self.next = None
		self.hash = hash


class HashTable:
	def __init__(self, content):
		self.content = content
		self.size = 0
		self.table = [None] * content

	def _hash(self, key):
		return hash(key) % self.content

	def get_value(self, name):
		a = ord('a')
		alphabet = ''.join([chr(i) for i in range(a, a + 25)])
		alphabet = list(alphabet)
		return alphabet.index(name[0].lower()) * 26 + alphabet.index(name[1].lower())

	def get_hash(self, value):
		result = value % self.content
		return result

	def show(self):
		for i in range(len(self.table)):
			if self.table[i] != None:
				if self.table[i].next is None:
					print(f'Hash-address: {self.table[i].hash} name: {self.table[i].name}')
				elif self.table[i].next != None:
					print(f'Hash-address: {self.table[i].hash} name: ', end='')
					current = self.table[i]
					while True:
						if current.next is None:
							print(f'{current.name}')
							break
						else:
							print(f'{current.name} ', end='')
							current = current.next
						
	def insert(self, name, info):
		value = self.get_value(name)
		hash = self.get_hash(value)
		index = self.search_hash(hash)
		if self.table[index] is None:
			self.table[index] = Node(name, info, value, hash)
			self.size += 1
		else:
			current = self.table[index]
			while current:
				if current.name == name:
					current.value = info
					return
				current = current.next
			new_node = Node(name, info, value, hash)
			new_node.next = self.table[index]
			self.table[index] = new_node
			self.size += 1

	def search(self, name):
		for i in range(len(self.table)):
			if self.table[i] != None:
				if self.table[i].name == name:
					print(f' name: {self.table[i].name}\n Hash-address: {self.table[i].hash}\n numeric value: {self.table[i].value}\n collision: {1 if self.table[i].next != None else 0}\n info: {self.table[i].info}')
					return
				elif self.table[i].next != None:
					current = self.table[i]
					while True:
						if current.name == name:
							print(f' name: {current.name}\n Hash-address: {current.hash}\n numeric value: {current.value}\n collision: 1\n info: {current.info}')
							return
						elif current.next is None:
							break
						else:
							current = current.next

	def search_hash(self, hash):
		index = 0
		for i in range(len(self.table)):
			current = self.table[i]
			if current is None:
				index = i
			elif current.hash == hash:
				return i
		return index
	
	def remove(self, name):
		for i in range(len(self.table)):
			if self.table[i] != None:
				if self.table[i].name == name:
					if self.table[i].next != None:
						self.table[i] = self.table[i].next
						return
					else:
						self.table[i] = None
						return
				else:
					if self.table[i].next != None:
						previous = None
						current = self.table[i]
						while current:
							if current.name == name:
								previous.next = current.next
								self.size -= 1
								return
							elif current.next is None:
								break
							else:
								previous = current
								current = current.next

	def __len__(self):
		return self.size

	def __contains__(self, key):
		try:
			self.search(key)
			return True
		except KeyError:
			return False

def choose(self, number):
    if self.table[i] != None:
        self.card = 1
        self.screen_print(self.get_rev_info(), self.get_info())

def log(self, error: str, status: bool, error_type:str):
        fo = open('log.txt', 'a')
        date = 4
        fo.write(date.strftime('%d-%m-%Y  %H:%M:%S') + '\n')
        fo.write('Operation type: ' + error + '\n')
        if status == 1:
            fo.write("Status: Success\n\n")
        else:
            fo.write('Status: Fail\n')
            fo.write('Error type: ' + error_type + '\n\n')
        fo.close()

def choose_operat(self, n) -> bool:
        #n =int(input())
        try:
            if n == 1:
                self.set_chosen(1)
                return True
            elif n == 2:
                self.set_chosen(2)
                return True
            elif n == 3:
                self.set_chosen(3)
                return True
            else:
                print('\t----------Invalid code of operation----------')
                return False
        except ValueError:
            print('\t----------Invalid enter format----------')

if __name__ == '__main__':
	numbers = ''
	ht = HashTable(16)

	ht.insert("BMW x5", 11)
	ht.insert("Tesla Model X", 10)
	ht.insert("Porsche Panamera", 5)
	ht.insert("Ferrari 428", 4)
	ht.insert("Peugeot 406", 8)

	ht.show()
	while True:
		print("\nOperation:\n 1) Addition\n 2) Search\n 3) Delete\n 4) Print\n 5) Exit")
		key = input("Choose operation:")
		if key == "1":
			name = input("Input key name: ")
			info = input("Input data: ")
			if name[0] in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
				print('Use only words')
			else:
				ht.insert(name, info)
		elif key == "2":
			info = input("Input key name for searching: ")
			ht.search(info)
		elif key == "3":
			info = input("Input key name for deleting: ")
			ht.remove(info)
		elif key == "4":
			ht.show()
		elif key == "5":
			break