#include <cs50.h>
#include <math.h>
#include <stdio.h>

#define CARD_MAX 5599999999999999
#define CARD_MIN 4000000000000

long get_good_long(void);
int count_digits(long num);
int luhn_alg(long number, int digits);
int first_digits(long number, int digits);

int main(void)
{
    long card = get_good_long();
    int digits = count_digits(card);
    int luhn_num = luhn_alg(card, digits);
    int starts_with = first_digits(card, digits);

    // check the card number fits within the expected range
    if (card < CARD_MIN || card > CARD_MAX)
    {
        printf("INVALID\n");
    }

    // checks if the card number is valid under luhn's algorithm
    else if (luhn_num != 0)
    {
        printf("INVALID\n");
    }

    // checks if card fits under card types
    else if (digits == 15 && (starts_with == 34 || starts_with == 37))
    {
        printf("AMEX\n");
    }
    else if (digits == 16 && (starts_with == 51 || starts_with == 52 || starts_with == 53 ||
                              starts_with == 54 || starts_with == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((digits == 13 || digits == 16) && starts_with / 10 == 4)
    {
        printf("VISA\n");
    }

    // if card doesn't fit any card types
    else
    {
        printf("INVALID\n");
    }
}

// prompts user for a long value
long get_good_long(void)
{
    long c;
    do
    {
        c = get_long("Number: \n");
    }
    while (false);
    return c;
}

// returns the number of digits in card number
int count_digits(long num)
{
    int i = 0;
    long n = num;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return i;
}

// applies luhn's algorithm and returns the mod 10 value
int luhn_alg(long number, int digits)
{
    int n = 1;
    long digit;
    int evens = 0;
    int odds = 0;
    do
    {
        long i = pow(10, n);
        long j = pow(10, n - 1);
        digit = number % (i);
        digit = digit / (j);
        if (n % 2 == 0)
        {
            int k = digit * 2;
            if (k >= 10)
            {
                k = (k / 10) + (k % 10);
            }
            evens += k;
        }
        else
        {
            odds += digit;
        }
        n++;
    }
    while (n < (digits + 1));
    int total = evens + odds;
    total = total % 10;
    return total;
}

// returns the first two digits of the card number
int first_digits(long number, int digits)
{
    long i = pow(10, digits - 1);
    long j = pow(10, digits - 2);
    int first_digits = number % i;
    first_digits = number / j;
    return first_digits;
}
