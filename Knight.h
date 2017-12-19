#ifndef KNIGHT_H
#define KNIGHT_H

#include <Heros.h>
#include <Pawn.h>
#include "GameBoard.h"
#include<iostream>
using namespace std;


class Knight : public Heros
{
    public:
       	GameBoard* move(string s,int player,GameBoard *g,Pawn *p1,Pawn *p2,Knight *n1,Knight *n2);
        int ErrorCheck(string s,int player,GameBoard *g);
};

#endif // KNIGHT_H
