#include <cs50.h>
#include <stdio.h>

void build_pyramid(int height);
int get_good_int(void);

int main(void)
{
    int height = get_good_int();
    build_pyramid(height);
}

// get a positive integer, adjusted from class
int get_good_int(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h <= 0 || h > 8);
    return h;
}

// nested loops to build left-slant pyramid
void build_pyramid(int height)
{
    int n = 1;
    while (n <= height)
    {
        // define variable for number of spaces in each row
        int m = height - n;

        // print spaces
        for (int j = 0; j < m; j++)
        {
            printf(" ");
        }

        // print #'s
        for (int i = 0; i < n; i++)
        {
            printf("#");
        }
        printf("  ");
        for (int i = 0; i < n; i++)
        {
            printf("#");
        }
        
        // new row
        printf("\n");
        n++;
    }
}
