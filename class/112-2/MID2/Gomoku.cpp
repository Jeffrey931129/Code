#include <iostream>
#include <string>
#include <sstream>
#include <vector>
//#include "function.h"
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

int main() {
    int testcase;
    cin >> testcase;
    cin.ignore();
    vector<Board*> boards;
    vector<string> winners;
    Board *gameBoard = nullptr;
    Move gameMove;
    string line, gameType, winner = "Tie";
    
    for (int round = 0; round < testcase; ++round) {
        getline(cin, line);
        stringstream ss(line);

        ss >> gameType;
        if (gameType == "TicTacToe") gameBoard = new TicTacToeBoard();
        else if (gameType == "ConnectFour") gameBoard = new ConnectFourBoard();
        
        winner = "Tie";
        while (ss >> gameMove) {
            *gameBoard += gameMove;
            if (gameBoard->isGameWon()) {
                winner = gameMove.getPlayer();
                break;
            }
        }

        boards.push_back(gameBoard->clone());
        winners.push_back(winner);
        delete gameBoard;
    }
    for (int round = 0; round < testcase; ++round) {
        cout << "Round #" << round+1 << ": " << winners[round] << endl;
        cout << (*boards[round]) << endl << endl;
    }
}

/* === TODO_01 === */
// Constructor that initializes the board with specified rows and columns.
Board::Board(int r, int c){
    rows=r; cols=c; gameTurn=1;
    board=new char*[r];
    for(int i=0;i<r;i++){
        board[i]=new char[c];
        for(int j=0;j<c;j++) board[i][j]='.';
    }
}

/* === TODO_02 === */
// Copy constructor to create a deep copy of an existing board.
Board::Board(const Board& b){
    rows=b.rows; cols=b.cols; gameTurn=b.gameTurn;
    board=new char*[b.rows];
    for(int i=0;i<b.rows;i++){
        board[i]=new char[b.cols];
        for(int j=0;j<b.cols;j++) board[i][j]=b.board[i][j];
    }
}

/* === TODO_03 === */
// Subscript operator to access a row of the board directly,
// gives access to the character at the specified index.
char* Board::operator[](int idx){
    return board[idx];
}

/* === TODO_04 === */
// Destructor to clean up dynamically allocated memory for the board.
Board::~Board(){
    for(int i=0;i<rows;i++) delete[] board[i];
    delete[] board;
}

/* === TODO_05 === */
// Provide ostream support for printing the board.
ostream& operator<<(ostream& output, const Board& b){
    for(int i=0;i<b.rows;i++){
        for(int j=0;j<b.cols;j++){
            output<<b.board[i][j];
        }
        if(i!=b.rows-1) output<<endl;
    }
    return output;
}

/* === TODO_06 === */
// Constructor to initialize a TicTacToeBoard with the board size of 3x3.
TicTacToeBoard::TicTacToeBoard():Board(3,3){}

/* === TODO_07 === */
// Applies a move to the board, 
// alternating between players ( gameTurn = nextPlayer(); ).
TicTacToeBoard& TicTacToeBoard::operator+=(const Move& m){
    size_t find=m.move.find('/');
    (*this)[stoi(m.move.substr(0,find))][stoi(m.move.substr(find+1))]=(gameTurn?'O':'X');
    gameTurn=nextPlayer();
    //cout<<*this;
    return *this;
}

/* === TODO_08 === */
// Checks rows, columns, and diagonals 
// to determine if the TicTacToe game is won.
bool TicTacToeBoard::isGameWon(){
    //cout<<"OK"<<endl;
    for(int i=0;i<3;i++){
        if((*this)[i][0]!='.'&&(*this)[i][0]==(*this)[i][1]&&(*this)[i][0]==(*this)[i][2]) return true;
        //cout<<i<<"-1"<<endl;
        if((*this)[0][i]!='.'&&(*this)[0][i]==(*this)[1][i]&&(*this)[0][i]==(*this)[2][i]) return true;
        //cout<<i<<"-2"<<endl;
    }
    //cout<<"OK"<<endl;
    if((*this)[0][0]!='.'&&(*this)[0][0]==(*this)[1][1]&&(*this)[0][0]==(*this)[2][2]) return true;
    if((*this)[0][2]!='.'&&(*this)[0][2]==(*this)[1][1]&&(*this)[0][2]==(*this)[2][0]) return true;
    //cout<<"OK"<<endl;
    return false;
}

/* === TODO_09 === */
// Constructor to initialize a ConnectFourBoard with the board size of 6x7.
ConnectFourBoard::ConnectFourBoard():Board(6,7){}

/* === TODO_10 === */
// Applies a move to the board, 
// alternating between players ( gameTurn = nextPlayer(); ).
ConnectFourBoard& ConnectFourBoard::operator+=(const Move& m){
    int i=5;
    while((*this)[i][m.move[1]-'0']!='.') i--;
    (*this)[i][m.move[1]-'0']=(gameTurn?'W':'B')+26;
    gameTurn=nextPlayer();
    //cout<<*this<<endl;
    return *this;
}

/* === TODO_11 === */
// Checks for four consecutive pieces horizontally, vertically, and diagonally
// to determine if the ConnectFour game is won.
bool ConnectFourBoard::isGameWon(){
    //cout<<"OK"<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if((*this)[i][j]>'Z'){
                (*this)[i][j]-=26;
                //cout<<(*this)[i][j]<<endl;
                int left=j,right=j,down=1,left_down=1,right_down=1,left_up=1,right_up=1;
                while(left>=0&&(*this)[i][left]==(*this)[i][j]) left--;
                while(right<7&&(*this)[i][right]==(*this)[i][j]) right++;
                if(right-left>=5) return true;
                while(i+down<6&&(*this)[i+down][j]==(*this)[i][j]) down++;
                if(down>=4) return true;
                while(i+left_down<6&&j-left_down>=0&&(*this)[i+left_down][j-left_down]==(*this)[i][j]) left_down++;
                while(i-right_up>=0&&j+right_up<7&&(*this)[i-right_up][j+right_up]==(*this)[i][j]) right_up++;
                if(left_down+right_up>=5) return true;
                while(i+right_down<6&&j+right_down<7&&(*this)[i+right_down][j+right_down]==(*this)[i][j]) right_down++;
                while(i-left_up>=0&&j-left_up>=0&&(*this)[i-left_up][j-left_up]==(*this)[i][j]) left_up++;
                if(right_down+left_up>=5) return true;
                return false;
            }
        }
    }
    //cout<<"OK"<<endl;
    return false;
}