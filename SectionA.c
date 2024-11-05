#include "SectionA.h"

// Function to generate all valid knight moves for each position on the chessboard
chessPosArray ***validKnightMoves() {
    chessPosArray ***possibleMoves = (chessPosArray ***) malloc((COLLUMS * sizeof(chessPosArray**)));
    checkAllocation(possibleMoves);
    for (int i = 0; i < COLLUMS; i++) {
        possibleMoves[i] = (chessPosArray **)malloc(ROWS * sizeof(chessPosArray*));
        checkAllocation(possibleMoves[i]);

        for (int j = 0; j < ROWS; ++j) {
            possibleMoves[i][j] = (chessPosArray *) malloc(sizeof(chessPosArray));
            checkAllocation(possibleMoves[i][j]);
            possibleMoves[i][j]->positions = (chessPos*) malloc(MAX_MOVES * sizeof(chessPos));
            checkAllocation(possibleMoves[i][j]->positions);
            possibleMoves[i][j]->size = 0;

            // Determine the possible moves for the knight from position (i, j)
            moveUpR(i , j , possibleMoves[i][j]->positions, &possibleMoves[i][j]->size);
            moveRightUD(i , j , possibleMoves[i][j]->positions, &possibleMoves[i][j]->size);
            moveDownRL(i , j , possibleMoves[i][j]->positions, &possibleMoves[i][j]->size);
            moveLeftUD(i , j , possibleMoves[i][j]->positions, &possibleMoves[i][j]->size);
            moveUpL(i , j , possibleMoves[i][j]->positions, &possibleMoves[i][j]->size);


            // Resize the positions array to the actual number of valid moves
            possibleMoves[i][j]->positions = (chessPos*) realloc(possibleMoves[i][j]->positions, possibleMoves[i][j]->size * sizeof(chessPos));
            checkAllocation(possibleMoves[i][j]->positions);
        }
    }
    return possibleMoves;
}

// Function to determine valid knight moves in the "Up-Right and Up-Left" directions
void moveUpR(int row , int collom, chessPos* possibleMoves, unsigned int* size) {
    if (row - 2 >= FIRST_ROW && collom + 1 < COLLUMS) {
        convertIndexToPosition(row - 2, collom + 1, possibleMoves[*size]);
        (*size)++;
    }
}

// Function to determine valid knight moves in the "Up-Right and Up-Left" directions
void moveUpL(int row , int collom, chessPos* possibleMoves, unsigned int* size) {
    if (row - 2 >= FIRST_ROW && collom - 1 >= FIRST_COLLUM) {
        convertIndexToPosition(row -2, collom -1, possibleMoves[*size]);
        (*size)++;
    }
}

// Function to determine valid knight moves in the "Down-Right and Down-Left" directions
void moveDownRL(int row , int collom, chessPos* possibleMoves, unsigned int* size) {
    if (row + 2 < ROWS && collom + 1 < COLLUMS) {
        convertIndexToPosition(row + 2, collom +1, possibleMoves[*size]);
        (*size)++;
    }
    if (row + 2 < ROWS && collom - 1 >= FIRST_COLLUM) {
        convertIndexToPosition(row + 2, collom -1,possibleMoves[*size]);
        (*size)++;
    }
}

// Function to determine valid knight moves in the "Right-Up and Right-Down" directions
void moveRightUD(int row , int collom, chessPos* possibleMoves, unsigned int* size) {
    if (collom + 2 < COLLUMS && row - 1 >= FIRST_ROW) {
        convertIndexToPosition(row - 1, collom +2, possibleMoves[*size]);
        (*size)++;
    }

    if (collom + 2 < COLLUMS && row + 1 < ROWS) {
        convertIndexToPosition(row + 1, collom +2, possibleMoves[*size]);
        (*size)++;
    }
}

// Function to determine valid knight moves in the "Left-Up and Left-Down" directions
void moveLeftUD(int row , int collom, chessPos* possibleMoves, unsigned int* size) {
    if (collom - 2 >= FIRST_COLLUM && row + 1 < ROWS) {
        convertIndexToPosition(row + 1, collom -2, possibleMoves[*size]);
        (*size)++;
    }
    if (collom - 2 >= FIRST_COLLUM && row - 1 >= FIRST_ROW) {
        convertIndexToPosition(row - 1, collom - 2, possibleMoves[*size]);
        (*size)++;
    }
}

// Function to convert board indices to a chess position (e.g., 0,0 -> A1)
void convertIndexToPosition(int row, int collom, chessPos pos) {
    pos[0] = 'A' + row;
    pos[1] = '1' + collom;
}

// Function to check if memory allocation was successful
void checkAllocation(void *ptr) {
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Function to free the allocated memory for chessPosArray
void freeChessPosArray(chessPosArray ***array) {
    for (int i = 0; i < COLLUMS; i++) {
        for (int j = 0; j < ROWS; j++) {
            free(array[i][j]->positions);
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

//Function to check if the input is valid
bool isValidInput(chessPos startingPosition, int num) {
    if (startingPosition[0] < 'A' || startingPosition[0] > ('A' + ROWS - 1) || num < 1 || num >  COLLUMS )
        return false;
    startingPosition[1] =  num - 1 + '1' ;
    return true;
}

