#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "function.h"

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