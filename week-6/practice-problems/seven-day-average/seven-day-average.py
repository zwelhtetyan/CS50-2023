import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_case = dict()
    prev_case = dict()

    for value in reader:
        state = value["state"]
        cases = int(value["cases"])

        # if not create empty list or check for 14 and if so pop
        if state not in new_case:
            new_case[state] = list()
        else:
            if len(new_case[state]) == 14:
                new_case[state].pop(0)

        # if already exits in prev, make subtraction or simply append
        if state not in prev_case:
            prev_case[state] = cases
            new_case[state].append(cases)
        else:
            case = cases - int(prev_case[state])
            prev_case[state] = cases
            new_case[state].append(case)

    return new_case


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        prev_week = new_cases[state][-7:]
        last_week = new_cases[state][:7]

        prev_avg = round(sum(prev_week) / 7)
        last_avg = round(sum(last_week) / 7)

        diff = prev_avg - last_avg

        if diff > 0:
            msg = "an increase"
        else:
            msg = "a decrease"

        try:
            d = diff / last_avg
            p = round(d * 100, 2)
        except ZeroDivisionError:
            raise ZeroDivisionError

        print(f"{state} had a 7-day average of {prev_avg} and {msg} of {p}%.")


main()
