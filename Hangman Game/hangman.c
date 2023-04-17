#include <stdio.h>
#include <string.h>

#define MAX_TRIES 5

int main()
{
    char word[100], unknown[100];
    int length, i, tries = 0, letter_found = 0;

    printf("Enter a word to guess: ");
    scanf("%s", word);

    length = strlen(word);

    // Initialize unknown array with underscores
    for (i = 0; i < length; i++)
        unknown[i] = '_';

    unknown[length] = '\0';

    // Main game loop
    while (tries < MAX_TRIES && strcmp(word, unknown) != 0)
    {
        printf("\n%s\n", unknown);
        printf("Guess a letter: ");

        char letter;
        scanf(" %c", &letter);

        // Check if the letter is in the word
        letter_found = 0;
        for (i = 0; i < length; i++)
        {
            if (word[i] == letter)
            {
                unknown[i] = letter;
                letter_found = 1;
            }
        }

        if (!letter_found)
        {
            printf("Wrong letter!\n");
            tries++;
        }
    }

    // Game over
    if (tries == MAX_TRIES)
        printf("\nSorry, you lost. The word was %s.\n", word);
    else
        printf("\nCongratulations, you won!\n");

    return 0;
}
