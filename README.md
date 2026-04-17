# C++ Mini Game: Tic Tac Toe

A dynamic, console-based Tic Tac Toe game built in C++ to demonstrate mastery of loops, multi-dimensional arrays, and conditional logic.

This project was developed as Task 4 for the C++ Developer Internship.

## 🚀 Core Features
* **Dynamic Board Display:** Utilizes ANSI escape sequences to smoothly redraw the game board in place, providing a clean, flicker-free UI in the console.
* **2D Array Logic:** The game grid is managed using a `3x3` multidimensional array, applying math (`(slot - 1) / 3`) to map user input directly to array coordinates.
* **Algorithmic Win Detection:** Employs optimized looping logic to verify horizontal, vertical, and diagonal win conditions efficiently after every turn.
* **Robust Error Handling:** Validates all user inputs, preventing crashes from non-integer types and rejecting moves on already occupied grid slots.
* **Game State & Replayability:** Uses a nested `while` loop architecture allowing players to instantly reset the board state and play multiple matches continuously.

## 📂 Project Structure

```text
Mini-Game-Project/
│
├── main.cpp                # Main source code containing the game logic
├── tictactoe.exe           # The compiled Windows executable
└── README.md               # Project documentation