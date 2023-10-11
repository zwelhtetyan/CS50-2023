import re


def main():
    card_numbers = get_card_numbers()

    card_type = get_card_type(card_numbers)

    if card_type == "INVALID" or not is_legit(card_numbers):
        print("INVALID")
    else:
        print(card_type)


def get_card_numbers():
    while True:
        card_numbers = input("Number: ")
        x = bool(re.match(r'^\d+$', card_numbers))
        if x:
            break

    return card_numbers


def get_card_type(card_numbers):
    l = len(card_numbers)

    if l == 15 and (card_numbers.startswith('34') or card_numbers.startswith('37')):
        print("AMEX")
    elif l == 16 and card_numbers.startswith(('51', '52', '53', '54', '55')):
        print("MASTERCARD")
    elif (l == 13 or l == 16) and card_numbers.startswith('4'):
        print("VISA")
    else:
        print("INVALID")


def is_legit(card_numbers):
    first_sum = 0
    second_sum = 0

    for i in range(len(card_numbers) - 2, -1, -2):
        n = int(card_numbers[i])
        r = n * 2

        if r >= 10:
            first_sum += ((r // 10) + (r % 10))
        else:
            first_sum += r

    for i in range(len(card_numbers) - 1, -1, -2):
        n = int(card_numbers[i])
        second_sum += n

    # print(first_sum + second_sum)

    return (first_sum + second_sum) % 10 == 0


if __name__ == "__main__":
    main()
