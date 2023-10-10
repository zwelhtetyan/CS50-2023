from cs50 import get_float


def main():
    cents = get_cents()

    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    pennies = cents
    cents = cents - pennies * 1

    coins = quarters + dimes + nickels + pennies

    print(round(coins))


def get_cents():
    while True:
        cent = get_float("Change owed: ")

        if cent > 0:
            break
    return cent * 100


def calculate_quarters(cents):
    return cents // 25


def calculate_dimes(cents):
    return cents // 10


def calculate_nickels(cents):
    return cents // 5


main()
