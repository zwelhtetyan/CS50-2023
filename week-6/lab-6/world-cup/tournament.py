# Simulate a sports tournament

import csv
import sys
import random


# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # Read teams into memory from file
    file = sys.argv[1]
    with open(file, "r") as file:
        reader = csv.DictReader(file)

        for row in reader:
            team = dict()
            team_name = row["team"]
            rating = int(row["rating"])

            team["team"] = team_name
            team["rating"] = rating
            teams.append(team)

    counts = {}
    # Simulate N tournaments and keep track of win counts
    for _ in range(N):
        winning_team = simulate_tournament(teams)
        if winning_team in counts:
            counts[winning_team] += 1
        else:
            counts[winning_team] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""

    if len(teams) == 1:
        return teams[0]["team"]

    return simulate_tournament(simulate_round(teams))

    # winner_list = simulate_round(teams)

    # while True:
    #     if len(winner_list) == 1:
    #         return winner_list[0]["team"]
    #     else:
    #         winner_list = simulate_round(winner_list)


if __name__ == "__main__":
    main()
