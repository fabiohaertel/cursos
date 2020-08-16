#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int _height = 0;

    do
    {
        _height = get_int("Height: ");
    }
    while (_height < 1 || _height > 8);

    // main loop - vertical
    for (int i = 1; i <= _height; i++)
    {
        // left blocks - first loop - horizontal
        for (int j = 1; j <= _height; j++)
        {
            if (j <= _height - i)
            {
                printf(" "); // fill with spaces
            }
            else
            {
                printf("#");
            }

            if (j == _height)
            {
                printf("  "); // space between left and right blocks
            }
        }

        // right blocks - second loop - horizontal
        for (int j = 1; j <= i; j++)
        {
            printf("#");
            if (j == i)
            {
                printf("\n");
            }
        }
    }
}