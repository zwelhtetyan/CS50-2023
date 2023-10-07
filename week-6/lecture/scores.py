scores = []


def main():
    # getting score
    add_score(3)

    # calculating average
    average = sum(scores) / len(scores)

    # printing
    print(f"average is {average}")


def add_score(n):
    for _ in range(n):
        while True:
            try:
                score = int(input("Score: "))
                if score > 0:
                    scores.append(score)
                    break
            except ValueError:
                print("Not an integer!")


main()
