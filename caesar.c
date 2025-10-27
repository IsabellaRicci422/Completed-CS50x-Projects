#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(string key);
int rotate(string plaintext, int key);

int main(int argc, string argv[])
{
    // check if two command-line arguments are present
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // checks if there are only digits
    else if (only_digits(argv[1]) != 0)
    {
        return 1;
    }
    // conducts caesar cipher
    else
    {
        string plain = get_string("plaintext: ");
        int key = atoi(argv[1]);
        rotate(plain, key);
    }
}

// checks if key is only digits
int only_digits(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (isdigit(key[i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return 0;
}

// encrypts plaintext using caesar cipher and key
int rotate(string plaintext, int key)
{
    // intitialize a string for the alphabet and an array to hold the cipher characters
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher_array[strlen(plaintext)];

    // discerns between upper and lower case while rotating the letter characters of the plaintext
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]) && isupper(plaintext[i]))
        {
            cipher_array[i] = alphabet[(plaintext[i] - 65 + key) % 26];
        }
        else if (isalpha(plaintext[i]) && islower(plaintext[i]))
        {
            cipher_array[i] = tolower(alphabet[(plaintext[i] - 97 + key) % 26]);
        }
        else
        {
            cipher_array[i] = plaintext[i];
        }
    }

    // prints the ciphertext
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", cipher_array[i]);
    }
    printf("\n");
    return 0;
}
