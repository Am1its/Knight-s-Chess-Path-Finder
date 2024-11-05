#ifndef FINALPROJECTFORREAL_SECTIONA_H
#define FINALPROJECTFORREAL_SECTIONA_H

#include "Structs.h"

chessPosArray ***validKnightMoves();                                                // Function to generate all valid knight moves for each position on the chessboard
void convertIndexToPosition(int row, int collom, chessPos pos);                     // Function to convert board indices to a chess position (e.g., 0,0 -> A1)
void moveUpR(int row , int collom, chessPos* possibleMoves, unsigned int* size);    // Function to determine valid knight moves in the "Up-Right directions
void moveUpL(int row , int collom, chessPos* possibleMoves, unsigned int* size);    // Function to determine valid knight moves in the "Up-Left" directions
void moveDownRL(int row , int collom, chessPos* possibleMoves, unsigned int* size); // Function to determine valid knight moves in the "Down-Right and Down-Left" directions
void moveRightUD(int row , int collom, chessPos* possibleMoves, unsigned int* size); // Function to determine valid knight moves in the "Right-Up and Right-Down" directions
void moveLeftUD(int row , int collom, chessPos* possibleMoves, unsigned int* size);  // Function to determine valid knight moves in the "Left-Up and Left-Down" directions
void checkAllocation(void *ptr);                                                     // Function to check if memory allocation was successful
void freeChessPosArray(chessPosArray ***array);                                     // Function to free the allocated memory for chessPosArray
bool isValidInput(chessPos startingPosition ,int num);                               //Function to check if the input is valid



#endif //FINALPROJECTFORREAL_SECTIONA_H
