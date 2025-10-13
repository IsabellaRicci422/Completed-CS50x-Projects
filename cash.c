#include <cs50.h>
#include <stdio.h>

int get_pos_int(void);
int minimum_change(int c);

int main(void)
{
    int change = get_pos_int();
    int coins = minimum_change(change);
    printf("%i\n", coins);
}

// get a positive integer, adjusted from class
int get_pos_int(void)
{
    int h;
    do
    {
        h = get_int("Change owed: ");
    }
    while (h < 0);
    return h;
}

// least number of coins to deliver proper change
int minimum_change(int c)
{
    int i = 0;

    // number of quarters
    while (c >= 25)
    {
        c = c - 25;
        i++;
    }
    // number of dimes
    while (c >= 10)
    {
        c = c - 10;
        i++;
    }

    // number of nickels
    while (c >= 5)
    {
        c = c - 5;
        i++;
    }

    // number of pennies
    while (c >= 1)
    {
        c = c - 1;
        i++;
    }
    return i;
}
