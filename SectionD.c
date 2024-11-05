#include "SectionD.h"

// Function that finds a path that covers all squares on the chessboard, starting from the root of the path tree.
chessPosList *findKnightPathCoveringAllBoard(pathTree *path_tree) {
    if (!path_tree || !path_tree->root) {
        return NULL; // Return NULL if the path tree is empty or root is NULL
    }

    chessPosList *list = (chessPosList *)malloc(sizeof(chessPosList)); // Allocate memory for the chess position list
    checkAllocation(list); // Check if the allocation was successful
    *list = makeEmptyList(); // Initialize the list to be empty

    if (findKnightPassCoveringAllBoardRec(list, 1, path_tree->root)) {
        return list; // Return the list if a path covering the entire board is found
    } else {
        free(list); // Free the allocated list if no path is found
        return NULL;
    }
}

// Recursively finds a knight's path covering the entire board.
bool findKnightPassCoveringAllBoardRec(chessPosList *list, int counter, treeNode *node) {
    insertDataToEndList(list, node->position); // Insert the current position into the list

    if (counter == ROWS * COLLUMS) {
        return true; // All squares are covered
    }

    treeNodeListCell *child = node->next_possible_positions.head; // Get the list of next possible positions
    while (child != NULL) {
        if (findKnightPassCoveringAllBoardRec(list, counter + 1, child->node)) {
            return true; // Return true if a valid path is found in the subtree
        }
        child = child->next; // Move to the next possible position
    }

    // Backtrack if no valid path is found
    removeFromListEnd(list); // Remove the last position from the list
    return false;
}

// Function to insert a new chess position at the end of the list
void insertDataToEndList(chessPosList *list, chessPos position) {
    chessPosCell *newCell = (chessPosCell *)malloc(sizeof(chessPosCell)); // Allocate memory for a new list cell
    checkAllocation(newCell); // Check if the allocation was successful

    newCell->position[0] = position[0];
    newCell->position[1] = position[1];
    newCell->next = NULL;

    if (list->tail) {
        list->tail->next = newCell; // Link the new cell at the end of the list
        list->tail = newCell; // Update the tail to be the new cell
    } else {
        list->head = list->tail = newCell; // If the list is empty, set head and tail to the new cell
    }
}

// Function to remove the last chess position from the list
void removeFromListEnd(chessPosList *list) {
    if (list->head == NULL) {
        return; // Return if the list is empty
    }

    if (list->head == list->tail) {
        free(list->head); // Free the only element in the list
        list->head = list->tail = NULL; // Set head and tail to NULL
        return;
    }

    chessPosCell *current = list->head;
    while (current->next != list->tail) {
        current = current->next; // Traverse to the second last element
    }

    free(list->tail); // Free the last element
    list->tail = current; // Update the tail to be the second last element
    list->tail->next = NULL; // Set the next of the new tail to NULL
}
