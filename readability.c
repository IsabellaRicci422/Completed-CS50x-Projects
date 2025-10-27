#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int coleman_liau_index(string text, int text_length);
void grade_assesment(int index);

int main(void)
{
    string txt = get_string("Text: \n");
    int txt_length = strlen(txt);

    int grade = coleman_liau_index(txt, txt_length);
    grade_assesment(grade);
}

// Takes the index value and prints appropriate
void grade_assesment(int index_grade)
{
    if (index_grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index_grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        for (int x = 1; x < 16; x++)
        {
            if (index_grade == x)
            {
                printf("Grade %i\n", x);
            }
        }
    }
}

// Gathers the number of words, letters and sentences, then runs them through the coleman-liau index
int coleman_liau_index(string text, int text_length)
{
    float L;
    float S;

    float word_count = 1;
    float sentences = 0;
    float letters = 0;

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        if (isspace(text[i]) != 0)
        {
            word_count++;
        }
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }

    // average number of letters per 100 words
    L = (letters / word_count) * 100;

    // average number of senetnces per 100 words
    S = (sentences / word_count) * 100;

    // coleman-liau index calculation
    float grade_level = (0.0588 * L) - (0.296 * S) - 15.8;

    // round grade level to the nearest integer value
    grade_level = round(grade_level);

    return grade_level;
}
