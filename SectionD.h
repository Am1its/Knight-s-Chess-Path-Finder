#ifndef FINALPROJECTFORREAL_SECTIOND_H
#define FINALPROJECTFORREAL_SECTIOND_H

#include "SectionC.h"

// Function declarations
chessPosList * findKnightPathCoveringAllBoard(pathTree* path_tree);                         //Function that finds a path that covers all squares on the chessboard ,starting from the root of the path tree.
void insertDataToEndList(chessPosList *list, chessPos position);                             // Function to insert a new chess position at the end of the list
void removeFromListEnd(chessPosList *list);                                                  //Function to remove the last chess position from the list
bool findKnightPassCoveringAllBoardRec(chessPosList *list, int counter, treeNode *node);    //Recursively finds a knight's path covering the entire board.




#endif //FINALPROJECTFORREAL_SECTIOND_H
