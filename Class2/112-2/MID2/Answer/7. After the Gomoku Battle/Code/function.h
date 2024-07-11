#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
using namespace std;

const int TIC_TAC_TOW_ROWS = 3;
const int TIC_TAC_TOW_COLS = 3;
const int CONNECT_FOUR_ROWS = 6;
const int CONNECT_FOUR_COLS = 7;

class Move;
class Board;
class TicTacToeBoard;
class ConnectFourBoard;

class Move {
    protected:
        string player;
        string move;

    public:
        Move() : player(""), move("") {}
        Move(string p, string m) : player(p), move(m) {}
        string getPlayer() { return player; }
        friend class TicTacToeBoard;
        friend class ConnectFourBoard;
        friend istream& operator>>(istream& input, Move& m) {
            string moveStr;
            input >> moveStr;
            size_t colonPos = moveStr.find(':');
            if (colonPos != std::string::npos) {
                m.player = moveStr.substr(0, colonPos);
                m.move = moveStr.substr(colonPos + 1);
            }
            return input;
        }
};

class Board {
    private:
        char** board;
        int rows;
        int cols;
        
    protected:
        int gameTurn;
        int nextPlayer() { return (gameTurn + 1) % 2; }

        /* === TODO_01 === */
        // Constructor that initializes the board with specified rows and columns.
        Board(int r, int c);

        /* === TODO_02 === */
        // Copy constructor to create a deep copy of an existing board.
        Board(const Board& b);

        /* === TODO_03 === */
        // Subscript operator to access a row of the board directly,
        // gives access to the character at the specified index.
        char* operator[](int idx);

    public:
        Board() : board(nullptr), rows(0), cols(0), gameTurn(0) {}

        /* === TODO_04 === */
        // Destructor to clean up dynamically allocated memory for the board.
        ~Board();

        // To determine if a game has been won.
        virtual bool isGameWon() = 0;

        // To create and return a clone of the current board.
        virtual Board* clone() const = 0;

        // To apply a move to the board and return the updated board.
        virtual Board& operator+=(const Move& m) = 0;

        /* === TODO_05 === */
        // Provide ostream support for printing the board.
        friend ostream& operator<<(ostream& output, const Board& b);
};

class TicTacToeBoard : public Board {
    public:
        // Returns a new instance of a TicTacToeBoard that is a copy of the current board.
        TicTacToeBoard* clone() const override { return new TicTacToeBoard(*this); }

        /* === TODO_06 === */
        // Constructor to initialize a TicTacToeBoard with the board size of 3x3.
        TicTacToeBoard();

        /* === TODO_07 === */
        // Applies a move to the board, 
        // alternating between players ( gameTurn = nextPlayer(); ).
        TicTacToeBoard& operator+=(const Move& m) override;

        /* === TODO_08 === */
        // Checks rows, columns, and diagonals 
        // to determine if the TicTacToe game is won.
        bool isGameWon() override;
};

class ConnectFourBoard : public Board {
    public:
        // Returns a new instance of a ConnectFourBoard that is a copy of the current board.
        ConnectFourBoard* clone() const override { return new ConnectFourBoard(*this); }

        /* === TODO_09 === */
        // Constructor to initialize a ConnectFourBoard with the board size of 6x7.
        ConnectFourBoard();

        /* === TODO_10 === */
        // Applies a move to the board, 
        // alternating between players ( gameTurn = nextPlayer(); ).
        ConnectFourBoard& operator+=(const Move& m) override;

        /* === TODO_11 === */
        // Checks for four consecutive pieces horizontally, vertically, and diagonally
        // to determine if the ConnectFour game is won.
        bool isGameWon() override;
};

#endif
