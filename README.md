Knight's Tour Solver
This project provides a solution to the classic "Knight's Tour" problem on a chessboard, implemented in C. The goal is to find a path for a knight to cover all squares on a 5x5 chessboard, starting from a user-specified position. The program leverages trees and linked lists to track possible moves and avoid revisiting squares in the same path.

Features
Calculates valid moves for a knight from each square on a 5x5 chessboard.
Builds a tree of all possible knight paths from a given starting position.
Searches for a path that covers all squares on the board, if one exists.
Displays the knight's tour in a formatted chessboard layout.

File Descriptions

1. main.c
The main entry point of the program.
Prompts the user for a starting position, validates input, and builds possible knight paths.
Uses findKnightPathCoveringAllBoard to find a path that covers all squares.
Outputs the knight’s tour path or indicates if no such path exists.
Ensures proper memory deallocation for path trees and lists.

2. Structs.h
Defines core data structures used in the project:
chessPos: Represents a chessboard position.
chessPosArray: Stores valid knight moves for a specific position.
chessPosList: A linked list to store sequences of knight moves.
pathTree: A tree structure representing all possible knight paths from a position.
Utilizes constants for the board dimensions and defines the knight's possible moves.

3. SectionA.h / SectionA.c
SectionA.h declares and defines helper functions:
validKnightMoves: Generates all valid moves for the knight from each board position.
Movement and helper functions like moveUpR, moveDownRL, and isValidInput for input validation and move generation.
Utility functions for memory management, including freeChessPosArray.
Contains the isValidInput function to verify the correctness of user input.

4. SectionB.h / SectionB.c
Handles linked list operations and chessboard display:
display: Displays the knight's path on the chessboard.
convertPositionsToIndex: Converts chess positions to matrix indices.
List manipulation functions such as removeFromList, insertDataToStartList, and isEmptyList.
printChessBoard: Outputs the board with move sequence numbers.

5. SectionC.h / SectionC.c
Manages the creation of knight path trees:
findAllPossibleKnightPaths: Builds a tree representing all possible paths from a starting position.
createTreeNode: Creates nodes for the path tree.
buildTree: Recursively generates paths to avoid revisiting squares within the same path.
Memory management functions to free allocated trees and arrays.

6. SectionD.h / SectionD.c
Searches for a knight's tour covering the entire board:
findKnightPathCoveringAllBoard: Attempts to find a full knight’s tour using a recursive approach.
findKnightPassCoveringAllBoardRec: Recursive function to traverse the path tree.
Linked list functions to add or remove chess positions.


Example

Enter the starting position (e.g., A1): B2
Knight's path that covers all squares on the board:
    1  2  3  4  5
A |15 |14 |13 |12 |11 |
B |16 | 1 |10 | 9 | 8 |
C |17 | 2 | 3 | 4 | 7 |
D |18 |19 |20 | 5 | 6 |
E |25 |24 |23 |22 |21 |

Memory Management
This project follows best practices in memory management:
Ensures all dynamically allocated memory for the tree, lists, and arrays is freed at the end.
Includes a checkAllocation utility to handle allocation errors gracefully.

Dependencies
Standard C library (stdlib.h, stdbool.h, stdio.h, string.h)

Contributing
Feel free to contribute to improve or extend the functionalities, like expanding to an 8x8 board or exploring different movement algorithms.

License
This project is open-source and available under the MIT License.
