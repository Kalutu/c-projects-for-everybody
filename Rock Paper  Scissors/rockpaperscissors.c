#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerChoice, computerChoice, result;

    srand(time(NULL)); // seed the random number generator

    // prompt the player to make a choice
    printf("Choose rock (0), paper (1), or scissors (2): ");
    scanf("%d", &playerChoice);

    // generate a random choice for the computer
    computerChoice = rand() % 3;

    // determine the result of the game
    if (playerChoice == computerChoice) {
        result = 0; // tie
    } else if (playerChoice == 0 && computerChoice == 2 ||
               playerChoice == 1 && computerChoice == 0 ||
               playerChoice == 2 && computerChoice == 1) {
        result = 1; // player wins
    } else {
        result = -1; // player loses
    }

    // display the results of the game
    printf("You chose %s.\n", playerChoice == 0 ? "rock" : playerChoice == 1 ? "paper" : "scissors");
    printf("The computer chose %s.\n", computerChoice == 0 ? "rock" : computerChoice == 1 ? "paper" : "scissors");
    if (result == 0) {
        printf("It's a tie!\n");
    } else if (result == 1) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return 0;
}
