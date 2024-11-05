#include "SectionB.h"

// Displays the contents of the chessPosList in a chessboard format
void display(chessPosList *lst) {
    int chessBoardCounter[ROWS][COLLUMS] = {0}; // Tracks occurrences of each position
    int chessBoardSaver[ROWS][COLLUMS] = {0}; // Saves the order of positions
    chessPosCell *p = lst->head;
    chessPosCell *temp = lst->head;
    int i, j, counter = 0;

    if (!p) {
        printf("The list is empty.\n");
        return;
    }

    // Traverse the list and process each position
    while (p != NULL) {
        convertPositionsToIndex(&i, &j, p->position); // Convert position to indices
        if (chessBoardCounter[i][j] > 0)
            removeFromList(&lst->head, temp); // Remove duplicate positions
        else {
            chessBoardCounter[i][j]++;
            counter++;
            chessBoardSaver[i][j] = counter; // Save the position order
        }
        temp = p;
        p = p->next;
    }
    printChessBoard(chessBoardSaver); // Print the chessboard
}

// Print the chessboard with positions marked
void printChessBoard(int chessBoardSaver[ROWS][COLLUMS]) {
    int i, j;

    for (i = 0; i < ROWS + 1; i++) {
        for (j = 0; j < COLLUMS + 1; j++) {
            if (i == 0 && j == 0)
                printf("   "); // Top-left corner
            else if (i == 0 && j != 0)
                printf("%d  ", j); // Column headers
            else if (j == 0 && i != 0)
                printf("%c ", 'A' + i - 1); // Row headers
            else if (chessBoardSaver[i - 1][j - 1] != 0) {
                if (chessBoardSaver[i - 1][j - 1] < 10)
                    printf("| %d", chessBoardSaver[i - 1][j - 1]); // Position numbers
                else
                    printf("|%d", chessBoardSaver[i - 1][j - 1]);
            } else
                printf("|  "); // Empty cells
            if (j == COLLUMS) {
                if (i != 0)
                    printf("|");
                printf("\n");
            }
        }
    }
}

// Converts chess positions to their corresponding row and column indices
void convertPositionsToIndex(int* row, int* collom, chessPos pos) {
    *row = pos[0] - 'A'; // Convert row from letter to index
    *collom = pos[1] - '1'; // Convert column from number to index
}

// Removes a node from the linked list
void removeFromList(chessPosCell** head, chessPosCell* node) {
    if (*head == NULL || node == NULL) {
        return; // Nothing to remove
    }

    if (*head == node) {
        *head = node->next; // Update head if removing the first element
        free(node);
        return;
    }

    chessPosCell* temp = *head;
    while (temp != NULL && temp->next != node) {
        temp = temp->next; // Traverse the list
    }

    if (temp == NULL) {
        return; // Node not found in the list
    }

    temp->next = node->next; // Adjust pointers to remove the node
    free(node);
}

// Inserts data at the start of the linked list
void insertDataToStartList(chessPosList *lst, chessPos data) {
    chessPosCell *newHead;
    newHead = createNewListNode(data, NULL); // Create a new node
    insertNodeToStartList(lst, newHead); // Insert node at the start
}

// Creates a new node for the linked list
chessPosCell* createNewListNode(chessPos data, chessPosCell *next) {
    chessPosCell *node = (chessPosCell *)malloc(sizeof(chessPosCell));
    node->position[0] = data[0];
    node->position[1] = data[1];
    node->next = next;
    return node; // Return the new node
}

// Inserts a node at the start of the linked list
void insertNodeToStartList(chessPosList *lst, chessPosCell *newHead) {
    if (isEmptyList(*lst))
        lst->head = lst->tail = newHead; // Update head and tail if list is empty
    else {
        newHead->next = lst->head; // Insert at the beginning
        lst->head = newHead;
    }
}

// Checks if the linked list is empty
bool isEmptyList(chessPosList lst) {
    return (lst.head == NULL); // Returns true if list is empty
}

// Creates an empty chessPosList
chessPosList makeEmptyList() {
    chessPosList result;
    result.head = result.tail = NULL; // Initialize head and tail to NULL
    return result;
}
