#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float coleman_liau(int n_letters, int n_words, int n_sentences);
string get_grade(float col_liau_idx);

int main(int argc, char **argv)
{
    string inputText = get_string("Text: ");

    int num_letters = count_letters(inputText);
    int num_words = count_words(inputText);
    int num_sentences = count_sentences(inputText);

    float index = coleman_liau(num_letters, num_words, num_sentences);
    get_grade(index);

    return 0;
}

int count_letters(string text)
{
    int c = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            c++;
        }
    }

    return c;
}

int count_words(string text)
{
    int c = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (!isspace(text[i]) && isspace(text[i + 1]))
        {
            c++;
        }
    }

    return c + 1;
}

int count_sentences(string text)
{
    int c = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char t_i = text[i];
        if (t_i == '.' || t_i == '!' || t_i == '?')
        {
            if (i > 0 && isalpha(text[i - 1]))
            {
                c++;
            }
        }
    }

    return c;
}

float coleman_liau(int n_letters, int n_words, int n_sentences)
{
    float L = ((float)n_letters / (float)(n_words)) * 100;
    float S = ((float)n_sentences / (float)(n_words)) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    return round(index);
}

string get_grade(float col_liau_idx)
{
    if (col_liau_idx >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (col_liau_idx < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", col_liau_idx);
    }
}