#include <iostream>
using namespace std;

void printBoard(int board[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int board[9][9], int row, int col, int num) {

    // Check row
    for(int x = 0; x < 9; x++) {
        if(board[row][x] == num)
            return false;
    }

    // Check column
    for(int x = 0; x < 9; x++) {
        if(board[x][col] == num)
            return false;
    }

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool findEmpty(int board[9][9], int &row, int &col) {
    for(row = 0; row < 9; row++) {
        for(col = 0; col < 9; col++) {
            if(board[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool solveSudoku(int board[9][9]) {

    int row, col;

    if(!findEmpty(board, row, col))
        return true;

    for(int num = 1; num <= 9; num++) {

        if(isSafe(board, row, col, num)) {

            board[row][col] = num;

            if(solveSudoku(board))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int board[9][9];
    cout << "=============================\n";
    cout << "  Sudoku Solver\n";
    cout << "=============================\n\n";

    cout << "Enter the Sudoku puzzle\n";
    cout << "(Use 0 for empty cells)\n\n";

    for(int i = 0; i < 9; i++) {
        cout << "Enter row " << i + 1 << ": ";
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    cout << "\nOriginal Sudoku:\n\n";
    printBoard(board);
    if(solveSudoku(board)) {
        cout << "\nSolved Sudoku:\n\n";
        printBoard(board);
    } else {
        cout << "\nNo solution exists!\n";
    }
    return 0;
}
