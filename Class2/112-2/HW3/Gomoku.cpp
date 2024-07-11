#include <iostream>
#include <string>
//#include "function.h"
using namespace std;
class Board {
    private:
        int** board;
        int size;

    public:
        Board(int n) : size(n) {
            board = new int*[size];
            for(int i = 0; i < size; ++i) {
                board[i] = new int[size];
                for(int j = 0; j < size; ++j) {
                    board[i][j] = 0;
                }
            }
        }

        ~Board() {
            for(int i = 0; i < size; ++i) {
                delete[] board[i];
            }
            delete[] board;
        }

        void showBoard() {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (!board[i][j]) cout << ".";
                    //else cout<<board[i][j];
                    else cout << (board[i][j] == 1 ? "O" : "X");
                }
                cout << "\n";
            }
            cout << "\n";
        }

        /* TODO: Get the size of the board */
        int getSize();

        /* TODO: Set the value of board[i][j] to x */
        void set(int i, int j, int x);

        /* TODO: Get the value of board[i][j] */
        int get(int i, int j);
};
// my function
int Board::getSize()
{
    return size;
}
void Board::set(int i, int j, int x)
{
    board[i][j]=x;
}
int Board::get(int i, int j)
{
    return board[i][j];
}

class GomokuGame {
    private:
        Board* gomokuBoard;
        int turn; // 1 -> Doraemon, 2 -> DebugCatCapoo

    public:
        GomokuGame(int n) {
            gomokuBoard = new Board(n);
            turn = 1;
        }

        ~GomokuGame() {
            delete gomokuBoard;
        }

        void showBoard() {
            gomokuBoard->showBoard();
        }

        void nextRound() {
            turn = (turn == 1 ? 2 : 1);
        }

        /* TODO: Place or remove the piece at the specified location
                 Return true if the operation completes successfully */
        bool place(int player, string location);
        bool remove(int player, string location);
    
        /* TODO: Return 1 if Doraemon wins, 2 if DebugCatCapoo wins,
                 or 0 if the game has not yet ended */
        int getWinner(); 
};
// my function
bool GomokuGame::place(int player,string location)
{
    if(turn==player)
    {
        // 如果是10?
        int i,j;
        if(location[2]!=0)
        {
            if(location[3]!=0)
            {
                i=stoi(location.substr(0,2)),j=stoi(location.substr(2,2));
            }
            else if(location[1]=='0')
            {
                i=stoi(location.substr(0,2)),j=location[2]-'0';
            }
            else
            {
                i=location[0]-'0',j=stoi(location.substr(1,2));
            }
        }
        else i=location[0]-'0',j=location[1]-'0';
        gomokuBoard->set(i,j,-1*player);
        return true;
    }
    else return false;
}
bool GomokuGame::remove(int player, string location)
{
    if(turn==player)
    {
        // 如果是10?
        int i,j;
        if(location[2]!=0)
        {
            if(location[3]!=0)
            {
                i=stoi(location.substr(0,2)),j=stoi(location.substr(2,2));
            }
            else if(location[1]=='0')
            {
                i=stoi(location.substr(0,2)),j=location[2]-'0';
            }
            else
            {
                i=location[0]-'0',j=stoi(location.substr(1,2));
            }
        }
        else i=location[0]-'0',j=location[1]-'0';
        gomokuBoard->set(i,j,0);
        return true;
    }
    else return false;
}
int GomokuGame::getWinner()
{
    int size=gomokuBoard->getSize(),ans=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            int value=-1*gomokuBoard->get(i,j);
            if(value>0)
            {
                int left=j,right=j,up=i,down=i;
                while(left>0&&gomokuBoard->get(i,left-1)==value) left--;
                while(right<size-1&&gomokuBoard->get(i,right+1)==value) right++;
                while(up>0&&gomokuBoard->get(up-1,j)==value) up--;
                while(down<size-1&&gomokuBoard->get(down+1,j)==value) down++;
                gomokuBoard->set(i,j,value);
                //cout<<"left:"<<left<<" right:"<<right<<" up:"<<up<<" down:"<<down<<endl;
                if(right-left>=4||down-up>=4) ans=value;
            }
        }
    }
    return ans;
}

int main() {
    int boardSize, round = 1;
    while (cin >> boardSize) {
        GomokuGame *game = new GomokuGame(boardSize);
        string player[101], action[101][2];
        int actionSize = 0;
        while (true) {
            cin >> player[actionSize];
            cin >> action[actionSize][0] >> action[actionSize][1];
            if (player[actionSize] == "-") break;
            actionSize++;
        }

        int result = 0;
        for (int i = 0; i < actionSize; ++i) {
            bool success = true;
            if (player[i] == "Doraemon") {
                success = game->place(1, action[i][0]);
                success = game->place(1, action[i][1]);
            } else if (player[i] == "DebugCatCapoo") {
                success = game->place(2, action[i][0]);
                success = game->remove(2, action[i][1]);
            }
            if (success) {
                // cout << player[i] << ": " << action[i][0] << "/" << action[i][1] << "\n"; 
                // game->showBoard();
                result = game->getWinner();
                // cout << player[i] << ": " << action[i][0] << "/" << action[i][1] << "\n"; 
                // game->showBoard();
                if (result) break;
                game->nextRound();
            }
        }

        if (result) {
            cout << "Round #" << round++ << " winner: ";
            cout << (result == 1 ? "Doraemon" : "DebugCatCapoo") << "!\n";
        } else {
            cout << "Round #" << round++ << ": Tie.\n";
        }
        game->showBoard();

        delete game;
    }
}