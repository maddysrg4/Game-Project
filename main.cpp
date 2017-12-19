#include<iostream>
#include "GameBoard.h"

#include "Pawn.h"
#include "Knight.h"
using namespace std;

int main()
{
	int i;
    cout<<"Player1 Input:\n";
     GameBoard* game= new GameBoard();
     Pawn p1[5],p2[5];
     Knight n1[5],n2[5];
     for(i=0;i<5;i++)
    {
        string s;
        cin>>s;
        int p=s[1]-'0';
        if(s[0]=='P')
        {
            p1[p-1].Get(s,4,i,1);
            game->Board[4][i]="A-"+s;
        }
        else if(s[0]=='K')
        {
            n1[p-1].Get(s,4,i,1);
            game->Board[4][i]="A-"+s;
        }
    }
    cout<<endl<<"Player2 Input:\n";
    for(i=4;i>=0;i--)
    {
        string s;
        cin>>s;
        int p=s[1]-'0';
        if(s[0]=='P')
        {
            p2[p-1].Get(s,0,i,2);
            game->Board[0][i]="B-"+s;
        }
        else if(s[0]=='K')
        {
            n2[p-1].Get(s,0,i,2);
            game->Board[0][i]="B-"+s;
        }
    }
    game->DisplayBoard();
    int turn=1,check=1;
    while(check)
    {
        if(turn==1)
        {
            cout<<"Player1 move: ";
            string s;
            cin>>s;
            int p=s[1]-'0';
            if(p1[p-1].p.x==-1){cout<<"Player Already Dead\n";continue;}
            int error=p1[p-1].ErrorCheck(s,1,game);
            if(error==1){cout<<"Out of Board\n";continue;}
            else if(error==2){cout<<"Own Player standing\n";continue;}

            game=p1[p-1].move(s,1,game,p1,p2,n1,n2);
            game->DisplayBoard();
            turn=2;
        }
        else
        {
            cout<<"Player2 move: ";
            string s;
            cin>>s;
            int p=s[1]-'0';
            if(p2[p-1].p.x==-1){cout<<"Player Already Dead\n";continue;}
            int error=p2[p-1].ErrorCheck(s,2,game);
            if(error==1){cout<<"Out of Board\n";continue;}
            else if(error==2){cout<<"Own Player standing\n";continue;}
            game=p2[p-1].move(s,2,game,p1,p2,n1,n2);
            game->DisplayBoard();
            turn=1;
        }
        int p=game->Check();
        if(p==1){cout<<"Player A wins\n";break;}
        else if(p==2){cout<<"Player B wins\n";break;}

    }
}
