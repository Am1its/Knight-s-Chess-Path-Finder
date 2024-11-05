#ifndef FINALPROJECTFORREAL_STRUCTS_H
#define FINALPROJECTFORREAL_STRUCTS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define  COLLUMS 5
#define  ROWS 5
#define MAX_MOVES 8
#define FIRST_ROW 0
#define FIRST_COLLUM 0


// Define a type representing a position on the chessboard
typedef char chessPos[2];

// Define a structure representing an array of chess positions
typedef struct _chessPosArray {
    unsigned int size;
    chessPos *positions;
} chessPosArray;

// Define the structures representing a linked list of chess positions
typedef struct _chessPosCell {
    chessPos position;
    struct _chessPosCell *next;
} chessPosCell;

typedef struct _chessPosList {
    chessPosCell *head;
    chessPosCell *tail;
} chessPosList;

// Define the structures representing a tree of chess positions
typedef struct _treeNode treeNode; // Forward declaration
typedef struct _treeNodeListCell treeNodeListCell; // Forward declaration

//Define a linked list of tree nodes.
typedef struct _treeNodeList {
    struct _treeNodeListCell *head;
    struct _treeNodeListCell *tail;
} treeNodeList;

//Define a node in the tree
typedef struct _treeNode {
    chessPos position;
    treeNodeList next_possible_positions;
} treeNode;

//Define a cell in the linked list of tree nodes (treeNodeList).
typedef struct _treeNodeListCell {
    treeNode *node;
    struct _treeNodeListCell *next;
} treeNodeListCell;

//Define the entire tree structure.
typedef struct _pathTree {
    treeNode *root;
} pathTree;


#endif //FINALPROJECTFORREAL_STRUCTS_H
