class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.cookies = 0

    def __str__(self):
        cookies_txt = ""
        for _ in range(self.size):
            cookies_txt += "🍪"
        return cookies_txt

    def deposit(self, n):
        total_cookies = self.cookies + n
        if total_cookies > self.capacity:
            raise ValueError("Jar is full!")
        self.cookies += n

    def withdraw(self, n):
        if self.cookies < n:
            raise ValueError("Not enough cookies!")
        self.cookies -= n

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, value):
        if value < 0:
            raise ValueError("Value must be non-negative!")
        self._capacity = value

    @property
    def size(self):
        return self.cookies


def main():
    jar = Jar(11)
    jar.deposit(5)
    jar.withdraw(2)

    print(str(jar))


main()
