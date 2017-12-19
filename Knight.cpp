#include "Knight.h"

GameBoard* Knight::move(string s,int player,GameBoard *g,Pawn *p1,Pawn *p2,Knight *n1,Knight *n2)
        {
            int i=p.x;
            int j=p.y,temp1,temp2;
            temp1=i;
            temp2=j;
            if(player==1)
            {
                if(s[3]=='F'){i--;temp1=i;i--;}
                else if(s[3]=='B'){i++;temp1=i;i++;}
                else if(s[3]=='L'){j--;temp2=j;j--;}
                else if(s[3]=='R'){j++;temp2=j;j++;}
            }
            else
            {
                if(s[3]=='F'){i++;temp1=i;i++;}
                else if(s[3]=='B'){i--;temp1=i;i--;}
                else if(s[3]=='L'){j++;temp2=j;j++;}
                else if(s[3]=='R'){j--;temp2=j;j--;}
            }
            if(g->Board[i][j][0]!='-'){
                    s=g->Board[i][j];
                    int p=s[3]-'0';
                   if(s[0]=='P'){ if(player==2){
                    p1[p-1].p.x=-1;
                    p1[p-1].p.y=-1;}
                    else
                    {
                        p2[p-1].p.x=-1;
                        p2[p-1].p.y=-1;
                    }}
                    else if(s[0]=='N')
                    {
                        if(player==2){
                        n1[p-1].p.x=-1;
                        n1[p-1].p.y=-1;}
                        else
                        {
                            n2[p-1].p.x=-1;
                            n2[p-1].p.y=-1;
                        }
                    }

            }
            if(g->Board[temp1][temp2][0]!='-'){
                    s=g->Board[temp1][temp2];
                    int p=s[3]-'0';
                   if(s[0]=='P'){ if(player==2){
                    p1[p-1].p.x=-1;
                    p1[p-1].p.y=-1;}
                    else
                    {
                        p2[p-1].p.x=-1;
                        p2[p-1].p.y=-1;
                    }}
                    else if(s[0]=='N')
                    {
                        if(player==2){
                        n1[p-1].p.x=-1;
                        n1[p-1].p.y=-1;}
                        else
                        {
                            n2[p-1].p.x=-1;
                            n2[p-1].p.y=-1;
                        }
                    }

            }
            g->Board[i][j]=g->Board[p.x][p.y];
            g->Board[temp1][temp2]="-";
            g->Board[p.x][p.y]="-";
            p.x=i;
            p.y=j;
            return g;
        }
        int Knight::ErrorCheck(string s,int player,GameBoard *g)
        {
            int i=p.x;
            int j=p.y;

            if(player==1)
            {
                if(s[3]=='F'){if(i-2<0){return 1;}}
                else if(s[3]=='B'){if(i+2>4){return 1;}}
                else if(s[3]=='L'){if(j-2<0){return 1;}}
                else if(s[3]=='R'){if(j+2>4){return 1;}}
                if(s[3]=='F'){if(g->Board[i-1][j][0]=='A'||g->Board[i-2][j][0]=='A') return 2;}
                else if(s[3]=='B'){if(g->Board[i+1][j][0]=='A'||g->Board[i+2][j][0]=='A') return 2;}
                else if(s[3]=='L'){if(g->Board[i][j-1][0]=='A'||g->Board[i][j-2][0]=='A') return 2;}
                else if(s[3]=='R'){if(g->Board[i][j+1][0]=='A'||g->Board[i][j+2][0]=='A') return 2;}
            }
            else
            {
                if(s[3]=='F'){if(i+2>4){return 1;}}
                else if(s[3]=='B'){if(i-2<0){return 1;}}
                else if(s[3]=='L'){if(j+2>4){return 1;}}
                else if(s[3]=='R'){if(j-2<0){return 1;}}
                if(s[3]=='F'){if(g->Board[i+1][j][0]=='B'||g->Board[i+2][j][0]=='B') return 2;}
                else if(s[3]=='B'){if(g->Board[i-1][j][0]=='B'||g->Board[i-2][j][0]=='B') return 2;}
                else if(s[3]=='L'){if(g->Board[i][j+1][0]=='B'||g->Board[i][j+2][0]=='B') return 2;}
                else if(s[3]=='R'){if(g->Board[i][j-1][0]=='B'||g->Board[i][j-2][0]=='B') return 2;}
            }
            return 0;
        }