#include<iostream>
#include<vector>
using namespace std;
class GameBoard
{
    public:
        vector<vector<string> > Board;
            GameBoard();
           
            void DisplayBoard();
            int Check();
};
