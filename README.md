♟️ 4x4 Console Board Game in C++

This project is a console-based board game written in C++. The game is played on a 4×4 board between a human player and a simple computer opponent. Each side controls a row of pieces, and the goal is to eliminate all opponent pieces or block them from making a move.

The program includes a text-based board renderer, move validation, capturing mechanics, a basic AI opponent, time control for both players, and a limited UNDO system.

✨ Features
4×4 board rendered in console using ASCII characters
Two players: human vs computer
Move validation: only legal adjacent moves allowed
Capturing mechanic: jumping over pieces in straight lines
Turn-based system with clear player indication
Time control: each player has a countdown timer
UNDO option: limited number of move reversals
Move history preview shown at the end of the game
Simple AI: computer prioritizes captures, otherwise makes the first valid move
🎮 Rules (Simplified)
Each player starts with 4 pieces on opposite sides of the board.
A piece can move to an adjacent empty square (up, down, left, right).
A piece can capture by jumping over an adjacent piece into an empty square behind it.
A player wins if:
The opponent has no pieces left, or
The opponent has no legal moves, or
The opponent runs out of time.
⌨️ Controls

During your turn:

Select a piece by typing:
row column → e.g. 1 A
Select a destination the same way.
Type UNDO instead of coordinates to revert moves (limited).
🧠 Computer Player Logic

The AI scans the board in this order:

Looks for any possible capture and performs it immediately.
If no capture is possible, performs the first legal move found.
🛠️ Technical Details
Language: C++
No external libraries
Uses:
struct to represent the board state
pair<int,int> for coordinates
time_t for time tracking
2D static arrays for the board
Board state history stored in an array for UNDO functionality.
▶️ How to Compile and Run

Compile with any C++ compiler:

g++ main.cpp -o game
./game

Works in a standard terminal (Windows / Linux).

📌 Notes
Designed as an academic/learning project.
Focus on game logic, state management, and console rendering.
Code intentionally avoids advanced libraries and OOP patterns.
