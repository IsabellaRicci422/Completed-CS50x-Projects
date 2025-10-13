#include <cs50.h>
#include <stdio.h>

void build_left_pyramid(int height);
int get_pos_int(void);

int main(void)
{
    int height = get_pos_int();
    build_left_pyramid(height);
}

// get a positive integer, adjusted from class
int get_pos_int(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h <= 0);
    return h;
}

// nested loops to build left-slant pyramid
void build_left_pyramid(int height)
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
        printf("\n");
        n++;
    }
}
