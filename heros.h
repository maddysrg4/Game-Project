#include "coordinates.h"
#include "gameboard.h"
#include "pawn.h"
#include "knight.h"

#include<iostream>
using namespace std;
class Heros
{
    public:
        Coordinates p;
        string name;

        virtual  GameBoard* move(string s,int player,GameBoard* g,Pawn *p1,Pawn *p2,Knight *n1,Knight *n2)=0;
        void Get(string s,int i,int j,int k);
};
