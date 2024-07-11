#include "function.h"
#include <iostream>

Board::Board(int r, int c) : rows(r), cols(c), gameTurn(0) {
    board = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        board[i] = new char[cols]();
        for (int j = 0; j < cols; ++j) {
            board[i][j] = '.';
        }
    }
}

Board::Board(const Board& b) : rows(b.rows), cols(b.cols), gameTurn(b.gameTurn) {
    board = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        board[i] = new char[cols];
        for (int j = 0; j < cols; ++j) {
            board[i][j] = b.board[i][j];
        }
    }
}

Board::~Board() {
    for (int i = 0; i < rows; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

char* Board::operator[](int idx) {
    return board[idx];
}

ostream& operator<<(ostream& output, const Board& b) {
    for (int i = 0; i < b.rows; ++i) {
        for (int j = 0; j < b.cols; ++j) {
            output << b.board[i][j];
        }
        if (i + 1 < b.rows) output << endl;
    }
    return output;
}

TicTacToeBoard::TicTacToeBoard() : Board(TIC_TAC_TOW_ROWS, TIC_TAC_TOW_COLS) {}

TicTacToeBoard& TicTacToeBoard::operator+=(const Move& m) {
    (*this)[m.move[0]-'0'][m.move[2]-'0'] = (gameTurn ? 'X' : 'O');
    gameTurn = nextPlayer();
    return *this;
}

bool TicTacToeBoard::isGameWon() {
    for (int row = 0; row < 3; ++row) {
        if ((*this)[row][0] != '.' &&
            (*this)[row][0] == (*this)[row][1] &&
            (*this)[row][1] == (*this)[row][2]) {
            return true;
        }
    }
    for (int col = 0; col < 3; ++col) {
        if ((*this)[0][col] != '.' &&
            (*this)[0][col] == (*this)[1][col] &&
            (*this)[1][col] == (*this)[2][col]) {
            return true;
        }
    }
    if ((*this)[0][0] != '.' &&
        (*this)[0][0] == (*this)[1][1] &&
        (*this)[1][1] == (*this)[2][2]) {
        return true;
    }
    if ((*this)[0][2] != '.' &&
        (*this)[0][2] == (*this)[1][1] &&
        (*this)[1][1] == (*this)[2][0]) {
        return true;
    }
    return false;
}

ConnectFourBoard::ConnectFourBoard() : Board(CONNECT_FOUR_ROWS, CONNECT_FOUR_COLS) {}

ConnectFourBoard& ConnectFourBoard::operator+=(const Move& m) {
    int col = m.move[1]-'0';
    for (int i = 5; i >= 0; i--) {
        if ((*this)[i][col] == '.') {
            (*this)[i][col] = (gameTurn ? 'B' : 'W');
            break;
        }
    }
    gameTurn = nextPlayer();
    return *this;
}

bool ConnectFourBoard::isGameWon() {
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            if ((*this)[row][col] != '.' &&
                (*this)[row][col] == (*this)[row][col+1] &&
                (*this)[row][col+1] == (*this)[row][col+2] &&
                (*this)[row][col+2] == (*this)[row][col+3]) {
                return true;
            }
        }
    }
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 3; ++row) {
            if ((*this)[row][col] != '.' &&
                (*this)[row][col] == (*this)[row+1][col] &&
                (*this)[row+1][col] == (*this)[row+2][col] &&
                (*this)[row+2][col] == (*this)[row+3][col]) {
                return true;
            }
        }
    }
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 4; ++col) {
            if ((*this)[row][col] != '.' &&
                (*this)[row][col] == (*this)[row+1][col+1] &&
                (*this)[row+1][col+1] == (*this)[row+2][col+2] &&
                (*this)[row+2][col+2] == (*this)[row+3][col+3]) {
                return true;
            }
        }
    }
    for (int row = 3; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            if ((*this)[row][col] != '.' &&
                (*this)[row][col] == (*this)[row-1][col+1] &&
                (*this)[row-1][col+1] == (*this)[row-2][col+2] &&
                (*this)[row-2][col+2] == (*this)[row-3][col+3]) {
                return true;
            }
        }
    }
    return false;
}
