import csv
import sys

# dict for peoples
peoples = []


def main():

    argv = sys.argv
    csv_file = argv[1]
    txt_file = argv[2]

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Usage: dna.py file.csv file.txt")
        return sys.exit(1)

    # TODO: Read database file into a variable
    with open(csv_file, 'r') as file:
        r = csv.DictReader(file)
        for row in r:
            peoples.append(row)

    # TODO: Read DNA sequence file into a variable
    f = open(txt_file)
    txt = f.read()

    # TODO: Find longest match of each STR in DNA sequence
    strs = dict()
    for key, _ in peoples[0].items():
        if key != "name":
            str_value = longest_match(txt, key)
            strs[key] = str_value

    # TODO: Check database for matching profiles
    for person in peoples:
        match = True

        for i in strs:
            # print(person[i], strs[i])

            if int(person[i]) != int(strs[i]):
                match = False
                break

        if match:
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
