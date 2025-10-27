#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validate_key(int key_len, string key);
int get_sub_cipher(string plaintext, string key);

int main(int argc, string argv[])
{
    // check if two command-line arguments are present
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    if (validate_key(strlen(argv[1]), argv[1]) == 0)
    {
        string plain = get_string("plaintext: ");
        get_sub_cipher(plain, argv[1]);
    }
    else
    {
        return 1;
    }
}

// fucntion to validate the key
int validate_key(int key_len, string key)
{
    // check if key is correct length
    if (key_len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // check if key is alphabetical
    for (int i = 0; i < key_len; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    // check for repeated characters
    for (int i = 65; i <= 90; i++)
    {
        int n = 0;
        for (int j = 0; j < key_len; j++)
        {
            if (toupper(key[j]) == i)
            {
                n++;
            }
        }
        if (n != 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    return 0;
}

// this is not working, only works for upper case... and incorrectly at that
int get_sub_cipher(string plaintext, string key)
{
    // make alphabetical keys to compare the user's key to
    string alpha_key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha_lower_key = "abcdefghijklmnopqrstuvwxyz";

    // make sure the whole key is uppercase
    for (int i = 0, len = strlen(key); i <= len; i++)
    {
        key[i] = toupper(key[i]);
    }

    // initialize new array to hold characters.... but can't output array...
    char cipher_array[strlen(plaintext)];

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        cipher_array[i] = plaintext[i];
        if (isalpha(plaintext[i]))
        {
            for (int j = 0, key_len = strlen(alpha_key); j < key_len; j++)
            {
                // discerning between upper and lowercase
                if ((isupper(plaintext[i])))
                {
                    if (plaintext[i] == alpha_key[j])
                    {
                        cipher_array[i] = key[j];
                    }
                }
                else
                {
                    if (plaintext[i] == alpha_lower_key[j])
                    {
                        cipher_array[i] = tolower(key[j]);
                    }
                }
            }
        }
    }

    // print the cipher
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", cipher_array[i]);
    }
    printf("\n");

    return 0;
}
