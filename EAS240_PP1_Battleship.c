#include "EAS240_PP1_Battleship.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void PlayGame(){ // Starts the game
    int gameBoard[8][8];
    int backGameBoard[8][8];
    int myGameBoard[8][8];
    printBoard(gameBoard);
    printf("\n");
    printBoard2(gameBoard);
    printf("\n");
    printBoard3( myGameBoard);
    printf("\n");
    computerRandBoard(gameBoard,  backGameBoard);
    printf("\n");
    myRandBoard(myGameBoard);
    printf("\n");
    getUserInputFromMe(gameBoard,backGameBoard);
    printf("\n");
    computerRandInput(myGameBoard);
    shipExists(gameBoard);
    shipExists(myGameBoard);
    while(shipExists(gameBoard) && shipExists(myGameBoard)){
        getUserInputFromMe(gameBoard,backGameBoard);
        computerRandInput(myGameBoard);
    }
   Winner( myGameBoard,gameBoard);

}

// Print board with an array full of zeros
void printBoard( int gameBoard[8][8]){
    int row = 8;
    int col = 8;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            gameBoard[i][j]= 0;
            printf("%d", gameBoard[i][j]);
        }
        printf("\n");
    }
}



void printBoard2( int gameBoard2[8][8]){
    int row = 8;
    int col = 8;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            gameBoard2[i][j]= 0;
            printf("%d", gameBoard2[i][j]);
        }
        printf("\n");
    }
}

// Creating a game board for the player 
void printBoard3( int myGameBoard[8][8]){
    int row = 8;
    int col = 8;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            myGameBoard[i][j]= 0;
        }
        printf("\n");
    }
}

/* Print out the computer random board and enter the values in the hidden gameBoard.*/

void computerRandBoard(int gameBoard[8][8], int backGameBoard[8][8]){
    int row = 8;
    int col = 8;
    printf("\n");
    printf("Hidden Computer Ships\n");


    int z = rand()%5;
    int q = rand()%5;
    for (int h = 0; h < 2; h++) {
        q++;
        gameBoard[z][q] = 1;
    }

    int t = rand()%5;
    int y = rand()%5;
    for (int h = 0; h < 4; h++) {
        y++;
        gameBoard[t][y] = 1;
    }
    int e = rand()%8;
    int r = rand()%8;
    for (int h = 0; h < 3; h++) {
        r++;
        gameBoard[e][r] = 1;
    }
    int g = rand()%8;
    int a = rand()%8;
    for (int h = 0; h < 3; h++) {
        g++;
        gameBoard[g+4][a] = 1;
    }
    printf("\n");
    for (int o = 0; o < row; o++) {
        for (int p = 0; p < col; p++) {
            backGameBoard[o][p] = 0;
            printf("%d", backGameBoard[o][p]);
        }
        printf("\n");
    }

}

// Print out MY GAME BOARD and show it's values

void myRandBoard(int myGameBoard[8][8]){
    int row = 8;
    int col = 8;
    printf("\n");
    printf("My Game Board\n");


    int z = rand()%6;
    int q = rand()%6;
    for (int h = 0; h < 2; h++) {
        q++;
        myGameBoard[z][q] = 1;
    }

    int t = (rand()%5)+2;
    int y = rand()%5;
    for (int h = 0; h < 4; h++) {
        y++;
        myGameBoard[t][y] = 1;
    }
    int e = rand()%4;
    int r = rand()%4;
    for (int h = 0; h < 3; h++) {
        r++;
        myGameBoard[e][r] = 1;
    }
    int g = rand()%6;
    int a = rand()%6;
    for (int h = 0; h < 3; h++) {
        g++;
        myGameBoard[g][a] = 1;
    }
    printf("\n");
    for (int o = 0; o < row; o++) {
        for (int p = 0; p < col; p++) {
            printf("%d", myGameBoard[o][p]);
        }
        printf("\n");
    }

}

// Get my X and Y coordinates! If it hit then the 1 value turns into an 8 and if it misses that 0 value turns into a 4.

void getUserInputFromMe(int gameBoard[8][8],int backGameBoard[8][8]){
    int l;
    int k;
    int row = 8;
    int col = 8;

    printf("Now guess where the computer's ship is at?!\n");

    printf("X coordinate:");
    scanf("%d", &l);
    printf("Y coordinate:");
    scanf("%d", &k);
    if(gameBoard[l][k] == 1){
        printf("HIT!");
        gameBoard[l][k]= 0;
        backGameBoard[l][k] = 8;
    }else if(gameBoard[l][k] == 0){
        printf("MISS LOSER!");
        backGameBoard[l][k] = 4;
    }
    printf("\n");
    printf("Computer's Ships");
    printf("\n");
    printf("\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            printf("%d", backGameBoard[i][j]);
        }
        printf("\n");
    }

}

//Check if the x and y coordinate equals 1 and if it does then turn it into zero.

void computerRandInput( int myGameBoard[8][8]){
    int a = rand()%8;
    int b = rand()%8;
    printf("\n");
    printf("Computer's Input[%d, %d]\n", a,b);
    if(myGameBoard[a][b] == 1){
        printf("\nComputer Hit!\n");
        myGameBoard[a][b]= 0;
    }else if(myGameBoard[a][b] == 0){
        printf("\n");
        printf("Computer Miss");
        printf("\n");
    }
    int row = 8;
    int col = 8;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d", myGameBoard[i][j]);
        }
        printf("\n");
    }

}

//Check if a ship exist which if there is a 1 in the array and if it there is return a true value.

bool shipExists(int boardToCheck[8][8]){
    int row = 8;
    int col = 8;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(boardToCheck[i][j] == 1){
               return true;
            }else{
                return false;
            }
            return false;
        }
        return false;
        printf("\n");
    }
}




// Check to see if the a player won the game!

void Winner(int myGameBoard[8][8], int gameBoard[8][8]) {
    int row = 8;
    int col = 8;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (myGameBoard[i][j] = 0) {
                printf("Player 1 wins!");
            } else if (gameBoard[i][j] = 0) {
                printf("Player 2 wins!");
            }
        }
    }
    printf("\n");

}














