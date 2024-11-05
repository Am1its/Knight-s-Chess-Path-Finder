#ifndef FINALPROJECTFORREAL_SECTIONB_H
#define FINALPROJECTFORREAL_SECTIONB_H

#include "SectionA.h"


// Function declarations
void display(chessPosList *lst);                                        //Displays the contents of the chessPosList in a chessboard format
void convertPositionsToIndex(int* row, int* collom, chessPos pos);      //Converts chess positions to their corresponding row and column indices.
void printChessBoard(int chessBoardSaver[ROWS][COLLUMS]);               //Prints the chessboard representation based on the given 2D array.
void removeFromList(chessPosCell** head, chessPosCell* node);           //Removes a node from the linked list.
void insertDataToStartList(chessPosList * lst, chessPos data);          //Inserts data at the start of the linked list.
chessPosCell * createNewListNode(chessPos data, chessPosCell * next);   //Creates a new node for the linked list.
void insertNodeToStartList(chessPosList * lst, chessPosCell * newHead); //Inserts a node at the start of the linked list.
bool isEmptyList(chessPosList lst);                                     //Checks if the linked list is empty.
chessPosList makeEmptyList();                                           //Creates an empty chessPosList.


#endif //FINALPROJECTFORREAL_SECTIONB_H
