class Hash:
    def __init__(self):
        self.d = [{'name': '', 'name1': ''} for _ in range(10)]

    def insert(self):
        print("\nEnter number of words:")
        n = int(input())
        for _ in range(n):
            print("\nEnter the word:")
            na = input()
            print("\nEnter the meaning of that word:")
            na1 = input()
            sum_val = sum(ord(char) for char in na)
            x = (sum_val // len(na)) % 10
            print(x)
            c = x
            while True:
                if self.d[x]['name'] == '':
                    self.d[x]['name'] = na
                    self.d[x]['name1'] = na1
                    break
                x = (x + 1) % 10
                if c == x:
                    print("\nHash table is full")
                    break

    def search(self):
        print("\nEnter the word whose meaning you want:")
        na = input()
        sum_val = sum(ord(char) for char in na)
        x = (sum_val // len(na)) % 10
        c = x
        while True:
            if self.d[x]['name'] == na:
                print("\nMEANING-> ", self.d[x]['name'], "=", self.d[x]['name1'])
                break
            x = (x + 1) % 10
            if c == x:
                print("\nWord not found")
                break

    def delete(self):
        print("\nEnter the word which is to be deleted:")
        na = input()
        sum_val = sum(ord(char) for char in na)
        x = (sum_val // len(na)) % 10
        c = x
        while True:
            if self.d[x]['name'] == na:
                print("\n", self.d[x]['name'], " word deleted")
                self.d[x]['name'] = ''
                self.d[x]['name1'] = ''
                break
            x = (x + 1) % 10
            if c == x:
                print("\nWord not found")
                break

    def display(self):
        for i in range(10):
            print("\n", self.d[i]['name'], self.d[i]['name1'])


if __name__ == "__main__":
    h = Hash()
    while True:
        print("\nEnter the choice:")
        print("\n1. Insert word and its meaning")
        print("2. Find meaning")
        print("3. Delete the word")
        print("4. Exit")
        n = int(input())
        if n == 1:
            h.insert()
        elif n == 2:
            h.search()
        elif n == 3:
            h.delete()
        elif n == 4:
            break
        else:
            print("\nUnknown choice")
