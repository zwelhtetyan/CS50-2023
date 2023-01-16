#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("%i %i\n", score1, score2);

    // TODO: Print the winner
    string result = score1 > score2 ? "Player 1 wins!" : score1 < score2 ? "Player 2 wins!" : "Tie!";

    printf("%s\n", result);
}

int compute_score(string word)
{
    int score = 0;

    for (int i = 0, N = strlen(word); i < N; i++)
    {


        if (tolower(word[i]) >= 'a' && tolower(word[i]) <= 'z')
        {
            const int idx = tolower(word[i]) - 'a';
            score += POINTS[idx];
        }
    }

    return score;
}
