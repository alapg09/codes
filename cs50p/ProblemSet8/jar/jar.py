class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Not a non-negative int")
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return f"🍪"*self.size

    def deposit(self, n):
        if (self.size + n) <= self.capacity:
            self._size += n
        else:
            raise ValueError("Exceeding Capacity")
    def withdraw(self, n):
        if self.size >= n:
            self._size -= n
        else:
            raise ValueError("Not many cookies")



    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size




jar = Jar()
jar.deposit(3)
jar.withdraw(1)
print(jar)
