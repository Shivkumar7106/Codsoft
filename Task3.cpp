#include <iostream>
#include <limits>

using namespace std;

void drawBoard(char board[4][4]) {
    cout << "-------------" << endl;
    for (int i = 1; i <= 3; i++) {
        cout << "| ";
        for (int j = 1; j <= 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool checkWin(char board[4][4], char player) {
    for (int i = 1; i <= 3; i++) {
        if ((board[i][1] == player && board[i][2] == player && board[i][3] == player) ||
            (board[1][i] == player && board[2][i] == player && board[3][i] == player))
            return true;
    }
    return (board[1][1] == player && board[2][2] == player && board[3][3] == player) ||
           (board[1][3] == player && board[2][2] == player && board[3][1] == player);
}

bool isValidInput(int row, int col, char board[4][4]) {
    return (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row][col] == ' ');
}

void playerMove(char board[4][4], char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter row and column : ";
        cin >> row >> col;
        if (cin.fail() || !isValidInput(row, col, board)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid move, Try again." << endl;
        } else {
            board[row][col] = player;
            break;
        }
    }
}

int main() {
    char board[4][4] = { { ' ', ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ', ' ' } };
    char player = 'X';

    cout << "Tic-Tac-Toe Game" << endl;

    for (int turn = 0; turn < 9; turn++) {
        drawBoard(board);
        playerMove(board, player);

        if (checkWin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " Wins!" << endl;
            return 0; 
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    drawBoard(board);
    cout << "It's a Draw!" << endl;
    return 0;
}
