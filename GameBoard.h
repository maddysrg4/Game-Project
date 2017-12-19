#ifndef GAMEBOARD_H
#define GAMEBOARD_H

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

#endif // GAMEBOARD_H
