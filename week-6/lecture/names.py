import sys

names = ["zwel", "wai", "shunn", "ellie"]

name = str(input("Name: "))

if name.lower() in names:  # algorithm is linear search
    print("Found!")
    sys.exit(0)

print("Not found!")
sys.exit(1)
