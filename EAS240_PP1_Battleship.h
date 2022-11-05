#ifndef EAS240_PP1_Battleship_H
#define EAS240_PP1_Battleship_H
#define false 0
#define true 1
#define bool int


void PlayGame();
void printBoard(int gameBoard[8][8]);
void printBoard2(int gameBoard2[8][8]);
void printBoard3( int myGameBoard[8][8]);
void computerRandBoard(int gameBoard[8][8], int backGameBoard[8][8]);
void getUserInputFromMe(int gameBoard[8][8],int backGameBoard[8][8]);
void myRandBoard(int gameBoard[8][8]);
void computerRandInput(int myGameBoard[8][8]);
bool shipExists(int boardToCheck[8][8]);
void Winner(int myGameBoard[8][8], int gameBoard[8][8]);





#endif

