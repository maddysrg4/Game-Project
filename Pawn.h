#ifndef PAWN_H
#define PAWN_H
#include "GameBoard.h"
#include <Heros.h>
#include<iostream>
using namespace std;

class Pawn : public Heros
{
    public:
        GameBoard* move(string s,int player,GameBoard *g,Pawn *p1,Pawn *p2);
        int ErrorCheck(string s,int player,GameBoard *g);

};

#endif // PAWN_H
