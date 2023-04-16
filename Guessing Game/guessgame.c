#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HIGH_SCORE_FILE "high_score.txt"

int main() {
    int guess, number, attempts = 0, high_score = 0;
    FILE *file;
    srand(time(0));
    number = rand() % 10 + 1;  // generate a random number between 1 and 10

    // read high score from file
    file = fopen(HIGH_SCORE_FILE, "r");
    if (file != NULL) {
        fscanf(file, "%d", &high_score);
        fclose(file);
    }

    printf("Welcome to Guess the Number!\n");
    printf("I'm thinking of a number between 1 and 10. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Guess again.\n");
        } else if (guess < number) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);

            // update high score if needed and save to file
            if (attempts < high_score || high_score == 0) {
                high_score = attempts;
                file = fopen(HIGH_SCORE_FILE, "w");
                if (file != NULL) {
                    fprintf(file, "%d", high_score);
                    fclose(file);
                }
            }
        }
    } while (guess != number);

    printf("High score: %d\n", high_score);

    return 0;
}
