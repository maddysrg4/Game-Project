#include "heros.h"
#include "gameboard.h"
#include<iostream>
using namespace std;
class Pawn : public Heros

{    public:
    GameBoard* move(string s,int player,GameBoard *g,Pawn *p1,Pawn *p2,Knight *n1,Knight *n2);
        int ErrorCheck(string s,int player,GameBoard *g);
};
