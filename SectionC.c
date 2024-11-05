#include "SectionC.h"

// Finds all possible knight paths starting from a given position on the chess board.
pathTree findAllPossibleKnightPaths(chessPos *startingPosition) {
    chessPos visited[ROWS * COLLUMS]; // Array to track visited positions
    int visitedSize = 1;
    visited[0][0] = startingPosition[0][0];
    visited[0][1] = startingPosition[0][1];
    treeNode *root;

    root = createTreeNode(*startingPosition); // Create the root of the tree
    chessPosArray ***allPossibleMoves = validKnightMoves(); // Get all valid knight moves
    buildTree(root, visited, visitedSize, allPossibleMoves); // Build the tree recursively

    pathTree tree;
    tree.root = root;

    // Free the allocated memory for allPossibleMoves
    freeChessPosArray(allPossibleMoves);

    return tree;
}

// Creates a new tree node for a given chess position.
treeNode *createTreeNode(chessPos position) {
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));
    checkAllocation(newNode); // Check if memory allocation was successful

    newNode->position[0] = position[0];
    newNode->position[1] = position[1];
    newNode->next_possible_positions = makeEmptyTreeList(); // Initialize an empty list of next possible positions
    return newNode;
}

// Function to recursively build the tree of knight's possible moves
void buildTree(treeNode *node, chessPos visited[], int visitedSize, chessPosArray ***allPossibleMoves) {
    int row = 0, col = 0;

    convertPositionsToIndex(&row, &col, node->position); // Convert position to indices
    chessPosArray *nodeMoves = allPossibleMoves[row][col]; // Get possible moves for the position

    for (int i = 0; i < nodeMoves->size; i++) {
        if (!isInVisited(visited, visitedSize, nodeMoves->positions[i])) { // Check if the move is already visited
            insertDataToEndListTree(&node->next_possible_positions, nodeMoves->positions[i]); // Add move to the list
            addVisited(visited, &visitedSize, nodeMoves->positions[i]); // Mark the move as visited
            buildTree(node->next_possible_positions.tail->node, visited, visitedSize, allPossibleMoves); // Recur for the new move
            visitedSize--; // Decrement visited size after recursion
        }
    }
}

// Function to add a position to the list of visited positions
void addVisited(chessPos *visited, int *visitedSize, chessPos position) {
    visited[*visitedSize][0] = position[0];
    visited[*visitedSize][1] = position[1];
    (*visitedSize)++;
}

// Function to check if a tree node list is empty
treeNodeList makeEmptyTreeList() {
    treeNodeList result;
    result.head = result.tail = NULL; // Initialize head and tail to NULL
    return result;
}

// Inserts a data node to the end of a tree node list.
void insertDataToEndListTree(treeNodeList *lst, chessPos data) {
    treeNodeListCell *newTail;
    newTail = createNewListCellTree(data, NULL); // Create a new list cell
    insertNodeToEndListTree(lst, newTail); // Insert the cell at the end
}

// Function to insert a node to the end of a tree node list
void insertNodeToEndListTree(treeNodeList *lst, treeNodeListCell *newTail) {
    if (isEmptyListTree(*lst)) {
        lst->head = lst->tail = newTail; // Update head and tail if list is empty
    } else {
        lst->tail->next = newTail; // Insert at the end
        lst->tail = newTail;
    }
    newTail->next = NULL;
}

// Creates a new tree node list cell.
treeNodeListCell *createNewListCellTree(chessPos data, treeNodeListCell *next) {
    treeNodeListCell *cell = (treeNodeListCell *)malloc(sizeof(treeNodeListCell));
    cell->node = createTreeNode(data); // Create a new tree node for the position
    cell->next = next;
    return cell;
}

// Function to check if the list is empty
bool isEmptyListTree(treeNodeList lst) {
    return (lst.head == NULL);
}

// Function to check if a move is already visited
bool isInVisited(chessPos *visited, int visitedSize, chessPos position) {
    for (int i = 0; i < visitedSize; i++) {
        if (visited[i][0] == position[0] && visited[i][1] == position[1]) {
            return true; // Move is already visited
        }
    }
    return false; // Move is not visited
}

// Function to free the allocated memory for the tree
void freeTree(treeNode *root) {
    if (root == NULL)
        return;

    treeNodeListCell *current = root->next_possible_positions.head;
    while (current != NULL) {
        treeNodeListCell *next = current->next;
        freeTree(current->node); // Recursively free child nodes
        free(current);
        current = next;
    }
    free(root); // Free the root node
}
