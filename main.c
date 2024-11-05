#include "SectionD.h"


void main() {
    chessPos startingPosition;
    int num;

    printf("Enter the starting position (e.g., A1): ");
    scanf(" %c%d", &startingPosition[0], &num);

    //Validate Input
    if (!isValidInput(startingPosition, num))
        printf("Invalid input");
    else
    {
        // Find all possible knight paths from the starting position
        pathTree knightPaths = findAllPossibleKnightPaths(&startingPosition);

        // Find a knight path that covers all squares on the board
        chessPosList *coveringPath = findKnightPathCoveringAllBoard(&knightPaths);

        // Display the covering path
        if (coveringPath != NULL) {
            printf("Knight's path that covers all squares on the board:\n");
            display(coveringPath);
        } else {
            printf("No knight's tour\n");
        }
        // Free allocated memory for the tree and path list
        freeTree(knightPaths.root);
        if (coveringPath != NULL) {
            free(coveringPath);
        }
    }
}


