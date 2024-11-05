#ifndef FINALPROJECTFORREAL_SECTIONC_H
#define FINALPROJECTFORREAL_SECTIONC_H

#include "SectionB.h"

pathTree findAllPossibleKnightPaths(chessPos *startingPosition);                                    // Finds all possible knight paths starting from a given position on the chess board.
treeNode* createTreeNode(chessPos position);                                                        // Creates a new tree node for a given chess position.
bool isInVisited(chessPos *visited, int visitedSize, chessPos position);                            // Function to check if a move is already visited
void buildTree(treeNode *node, chessPos visited[], int visitedSize, chessPosArray *** allPossibleMoves); // Function to recursively build the tree of knight's possible moves
void addVisited(chessPos visited[], int *visitedSize, chessPos position);                            // Function to add a position to the list of visited positions
treeNodeList makeEmptyTreeList();                                                                   // Function to check if a tree node list is empty
bool isEmptyListTree(treeNodeList lst);                                                             // Function to check if the list is empty
void insertNodeToEndListTree(treeNodeList * lst, treeNodeListCell * newTail);                       // Function to insert a node to the end of a tree node list
void insertDataToEndListTree(treeNodeList * lst, chessPos data);                                    // Inserts a data node to the end of a tree node list.
treeNodeListCell * createNewListCellTree(chessPos data, treeNodeListCell * next);                   //Creates a new tree node list cell.
void freeTree(treeNode *root);                                                                       // Function to free the allocated memory for the tree




#endif //FINALPROJECTFORREAL_SECTIONC_H
