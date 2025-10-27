#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_LENGTH 26

int point_value(string word);

int main(void)
{
    // Gathering values
    string player1 = get_string("PLayer 1 \n");
    string player2 = get_string("Player 2 \n");
    int pts1 = point_value(player1);
    int pts2 = point_value(player2);

    // Find and announce the winner!
    if (pts1 > pts2)
    {
        printf("Player 1 wins!\n");
    }
    else if (pts1 < pts2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Determine the point value of a word
int point_value(string word)
{
    // making arrays for alphabet and corresponding point values
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int letter_value[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    char w[strlen(word)];
    int points = 0;

    // Covert all chracters to uppercase
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        w[i] = toupper(word[i]);
    }

    // Add points value character by character
    for (int j = 0; j < strlen(word); j++)
    {
        for (int i = 0; i < ALPHABET_LENGTH; i++)
        {
            if (w[j] == alphabet[i])
            {
                points += letter_value[i];
            }
        }
    }

    return points;
}
