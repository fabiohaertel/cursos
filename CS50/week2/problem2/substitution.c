#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

const char eng_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool check_key(string key);
bool check_repeated_letter(string key);
string do_cipher(string plaintext, string cipher_key);

int main(int argc, char **argv)
{
    // should have exactly 2 args
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // must contain 26 chars
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // must have a valid format
    if (!check_key(argv[1]))
    {
        printf("Invalid key format.\n");
        return 1;
    }

    // passed all checks
    string plain_text = get_string("plaintext: ");
    printf("ciphertext: %s\n", do_cipher(plain_text, argv[1]));

    return 0;
}

// ensures valid key format
bool check_key(string key)
{
    bool valid = true;

    // allows only alphanumeric chars
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            valid = false;
            break;
        }
    }

    // avoids repeated letters
    if (check_repeated_letter(key))
    {
        valid = false;
    }

    return valid;
}

// checks if the key has a repeated letter
bool check_repeated_letter(string key)
{
    bool has = false;

    for (int i = 0; i < strlen(key); i++)
    {
        char current = key[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (tolower(key[j]) == tolower(current))
            {
                has = true;
                break;
            }
        }
        if (has == true)
        {
            break;
        }
    }

    return has;
}

string do_cipher(string plaintext, string cipher_key)
{
    // allocate space, or else = seg. fault
    string ciphered = malloc(sizeof(plaintext));

    for (int i = 0; i < strlen(plaintext); i++)
    {
        // 1. index of letter in original english alphabet
        char *idx = strchr(eng_alphabet, toupper(plaintext[i]));

        if (idx)
        {
            int index = idx - eng_alphabet;

            // replace by cipher key, using the same index, keeping case
            if (isupper(plaintext[i]))
            {
                ciphered[i] = toupper(cipher_key[index]);
            }
            else
            {
                ciphered[i] = tolower(cipher_key[index]);
            }
        }
        else
        {
            // non alpha chars stay the same
            ciphered[i] = plaintext[i];
        }
    }

    return ciphered;
}