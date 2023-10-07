def main():
    h = get_height()
    for _ in range(h):
        print("#" * h)


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an integer!")


main()
