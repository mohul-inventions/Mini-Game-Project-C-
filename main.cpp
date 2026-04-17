#include <iostream>
#include <string>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    int movesMade;

public:
    // Constructor initializes the game state
    TicTacToe() {
        resetGame();
    }

    void resetGame() {
        char slot = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = slot++;
            }
        }
        currentPlayer = 'X';
        movesMade = 0;
    }

    // Clears the terminal and draws the board dynamically
    void drawBoard() const {
        // ANSI escape code to clear the screen and move the cursor to the top
        cout << "\x1B[2J\x1B[H"; 
        
        cout << "===========================\n";
        cout << "   TIC TAC TOE IN C++      \n";
        cout << "===========================\n\n";
        cout << "Player 1 (X)  -  Player 2 (O)\n\n";

        for (int i = 0; i < 3; i++) {
            cout << "       |     |     \n";
            cout << "    " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  \n";
            if (i < 2) cout << "  _____|_____|_____\n";
            else cout << "       |     |     \n\n";
        }
    }

    bool placeMarker(int slot) {
        // Mathematical trick to convert a 1-9 slot into 2D array coordinates [row][col]
        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;

        // Check if the slot is valid and not already taken by 'X' or 'O'
        if (slot >= 1 && slot <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;
            movesMade++;
            return true;
        }
        return false;
    }

    bool checkWin() const {
        // Check Rows and Columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        // Check Diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

        return false;
    }

    bool checkDraw() const {
        return movesMade == 9;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

// --- Main Menu and Game Loop ---

int main() {
    TicTacToe game;
    int choice;
    bool keepPlaying = true;

    while (keepPlaying) {
        game.resetGame();
        bool gameOver = false;

        while (!gameOver) {
            game.drawBoard();
            cout << "Player " << game.getCurrentPlayer() << ", enter a slot (1-9): ";
            cin >> choice;

            // Failsafe for invalid string input
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                continue; 
            }

            if (game.placeMarker(choice)) {
                if (game.checkWin()) {
                    game.drawBoard();
                    cout << "🎉 WINNER! Player " << game.getCurrentPlayer() << " dominates the board!\n";
                    gameOver = true;
                } else if (game.checkDraw()) {
                    game.drawBoard();
                    cout << "🤝 IT'S A DRAW! A battle of equals.\n";
                    gameOver = true;
                } else {
                    game.switchPlayer();
                }
            } else {
                cout << "Invalid move! Press Enter to try again...";
                cin.ignore();
                cin.get();
            }
        }

        // Replay Option
        char replay;
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> replay;
        if (replay == 'N' || replay == 'n') {
            keepPlaying = false;
            cout << "Thanks for playing! Goodbye.\n";
        }
    }

    return 0;
}