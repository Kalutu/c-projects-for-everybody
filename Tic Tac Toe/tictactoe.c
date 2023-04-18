#include <stdio.h>

// function to draw the game board
void drawBoard(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// function to check if a player has won the game
int checkWin(char board[3][3], char mark) {
    int i, j;
    // check rows
    for(i = 0; i < 3; i++) {
        if(board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
            return 1;
    }
    // check columns
    for(j = 0; j < 3; j++) {
        if(board[0][j] == mark && board[1][j] == mark && board[2][j] == mark)
            return 1;
    }
    // check diagonals
    if(board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
        return 1;
    if(board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
        return 1;
    return 0;
}

int main() {
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
    int i, j, row, col, count = 0;
    char mark;
    printf("Welcome to Tic-Tac-Toe!\n");
    drawBoard(board);
    while(count < 9) {
        mark = (count % 2 == 0) ? 'X' : 'O';
        printf("Player %c's turn.\n", mark);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        if(board[row-1][col-1] == 'X' || board[row-1][col-1] == 'O') {
            printf("That cell is already marked. Please try again.\n");
            continue;
        }
        board[row-1][col-1] = mark;
        drawBoard(board);
        if(checkWin(board, mark)) {
            printf("Player %c wins!\n", mark);
            return 0;
        }
        count++;
    }
    printf("It's a tie!\n");
    return 0;
}
