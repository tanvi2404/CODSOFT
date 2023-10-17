#include <iostream>
using namespace std;

char board[3][3]; // 3x3 game board

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----" << endl;
    }
}

bool isValidMove(int row, int col) {
    return board[row][col] == ' ';
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';
    bool gameWon = false;
    bool draw = false;

    initializeBoard();

    do {
        displayBoard();

        int row, col;
        do {
            cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2) separated by a space: ";
            cin >> row >> col;
        } while (row < 0 || row > 2 || col < 0 || col > 2 || !isValidMove(row, col));

        board[row][col] = currentPlayer;
        gameWon = checkWin(currentPlayer);
        if (!gameWon)
            draw = isBoardFull();

        if (!gameWon && !draw) {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
        }
    } while (!gameWon && !draw);

    displayBoard();

    if (gameWon)
        cout << "Player " << currentPlayer << " wins!" << endl;
    else
        cout << "It's a draw!" << endl;

    return 0;
}

