class Student():
    def __init__(self, name, id):
        self.name = name
        self.id = id

    def changeID(self, id):
        self.id = id

    def print(self):
        print(f"{self.name} is ID -> [{self.id}]")


z = Student("Zwel", 11)
z.print()
z.changeID(111)
z.print()
