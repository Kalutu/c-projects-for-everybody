# Hangman Game
This is a simple hangman game implemented in C programming language. In this game, the player has to guess a word by suggesting letters within a certain number of guesses.

## Installation
- Clone the repository or download the source code as a zip file and extract it.
- Open a terminal and navigate to the directory where the code is located.
- Compile the code using a C compiler such as GCC

## How to Play
- The program prompts the player to enter a word to be guessed.
- The program initializes an "unknown" array with underscores representing the letters of the word that haven't been guessed yet.
- The game loop prompts the player to guess a letter, and then checks if the letter is in the word. If it is, the corresponding underscores in the "unknown" array are replaced with the letter. If not, the program informs the player that they guessed wrong and increments the number of tries.
- The game continues until either the player guesses all the letters in the word or they run out of tries.
- At the end of the game, the program informs the player whether they won or lost.

## Contributing
Contributions to the game are always welcome. If you find any issues or have suggestions for improvements, feel free to open an issue or create a pull request.
