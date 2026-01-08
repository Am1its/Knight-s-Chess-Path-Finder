# Knight's Tour Solver

A C implementation of the classic **Knight’s Tour** problem.  
The program finds a path for a knight to visit every square on a **5x5 chessboard** exactly once, starting from a user-specified position.  
It uses **trees** and **linked lists** to track all possible moves while avoiding revisits, ensuring efficient pathfinding.

---

## 🎯 Features

- Generates all valid knight moves from any position.
- Builds a tree of all possible paths from a chosen starting square.
- Searches for a **full tour** covering every square on the board.
- Displays the knight’s tour in a clean, chessboard-like format.
- Ensures proper memory management (no leaks!).

---

## 🛠 How It Works

1. **User Input**  
   Prompts for a starting position (e.g., `B2`) and validates it.

2. **Path Generation**  
   - Uses `findAllPossibleKnightPaths()` to build a tree of possible moves.
   - Avoids revisiting squares within the same path.

3. **Path Search**  
   - Uses `findKnightPathCoveringAllBoard()` to search for a complete tour.
   - Outputs the move sequence if a tour exists.

4. **Display**  
   Prints the chessboard with the sequence numbers for each move.

---

## 📂 Project Structure

| File              | Description |
|-------------------|-------------|
| **main.c**        | Entry point – handles input, runs search, outputs result. |
| **Structs.h**     | Defines all data structures (`chessPos`, `chessPosArray`, `chessPosList`, `pathTree`). |
| **SectionA.c/h**  | Move generation, input validation, and utility functions. |
| **SectionB.c/h**  | Linked list operations & chessboard display utilities. |
| **SectionC.c/h**  | Tree creation for all possible knight paths. |
| **SectionD.c/h**  | Recursive search for a complete knight’s tour. |

---

## 🔧 Technical Details

- **Board Size:** 5×5 (can be extended to 8×8 or more).
- **Data Structures:** Trees, linked lists, arrays.
- **Memory Management:**  
  - All dynamic allocations are freed at program termination.  
  - `checkAllocation` utility ensures safe memory handling.

---

## 📦 Dependencies

- Standard C libraries:  
  `stdlib.h`, `stdbool.h`, `stdio.h`, `string.h`




