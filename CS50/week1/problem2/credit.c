#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_num_len(long num);
int sum_individually(int mult);

int main(void)
{
    // visa
    long n1 = 369421438430814L;

    int n_digits = get_num_len(n1);

    // converts to array of char (using cs50's referenced sprintf)
    char cc_str[n_digits];
    sprintf(cc_str, "%lu", n1);

    // 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    int sum_multiplied_digits = 0;
    for (int i = n_digits - 2; i >= 0; i -= 2)
    {
        int d_int = (int)(cc_str[i]) - '0'; // converts char to int
        int mult = d_int * 2;

        if (mult < 10)
        {
            sum_multiplied_digits += mult;
        }
        else
        {
            // if higher than 10, sum individually
            sum_multiplied_digits += sum_individually(mult);
        }
    }

    // 2. Add the sum to the sum of the digits that weren’t multiplied by 2
    int sum_not_multiplied_digits = 0;
    for (int i = n_digits - 1; i >= 0; i -= 2)
    {
        int d_int = (int)(cc_str[i]) - '0'; // converts char to int
        sum_not_multiplied_digits += d_int;
    }

    // 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    int final_sum = sum_multiplied_digits + sum_not_multiplied_digits;
    if ((final_sum % 10) == 0)
    {
        if (cc_str[0] == '3')
        {
            if (cc_str[1] == '4' || cc_str[1] == '7')
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (cc_str[0] == '5')
        {
            if (cc_str[1] == '1' || cc_str[1] == '2' || cc_str[1] == '3' || cc_str[1] == '4' || cc_str[1] == '5')
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else if (cc_str[0] == '4')
        {
            if (n_digits >= 13)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// Gets the number of digits, ex: 100 = 3, 991199 = 6
int get_num_len(long num)
{
    // doesnt matter for this exercise
    if (num < 0)
        return 0;

    int len = 0;

    // divide by 10 until it reaches 0
    do
    {
        len++;
    } while ((num = num / 10) > 0);

    return len;
}

// Sums individual digits, ex: 12 = 1 + 2, 19 = 1 + 9
int sum_individually(int mult)
{
    int total_sum = 0;
    char tmp[2];              // always length 2
    sprintf(tmp, "%d", mult); // converts to array of char

    for (int i = 0; i < 2; i++)
    {
        total_sum += (int)(tmp[i]) - '0'; // converts char to int
    }

    return total_sum;
}