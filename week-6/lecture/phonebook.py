import csv

# file = open("phonebook.csv", "a")
# name = str(input("Name: "))
# number = str(input("Number: "))

# writer = csv.writer(file)
# writer.writerow([name, number])
# file.close()


with open("phonebook.csv", "a") as file:
    name = str(input("Name: "))
    number = str(input("Number: "))

    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})  # dictionary syntax
