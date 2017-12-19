#ifndef HEROS_H
#define HEROS_H
#include "Coordinates.h"
class Pawn;
#include<iostream>
using namespace std;
class Heros
{
    public:
    	Coordinates p;
        string name;
        void Get(string s,int i,int j,int k);
};

#endif // HEROS_H
