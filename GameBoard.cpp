#include "GameBoard.h"

GameBoard::GameBoard()
{
    for(int i=0;i<5;i++)
                {
                    vector<string> vec;
                    for(int j=0;j<5;j++)
                    {
                        vec.push_back("-");
                    }
                    Board.push_back(vec);
                }
}
void GameBoard::DisplayBoard()
            {
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        cout<<Board[i][j]<<"            ";
                    }
                    cout<<endl;
                }
            }
 int GameBoard:: Check()
            {
                int a=0,b=0;
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        if(Board[i][j][0]=='A'){a++;}
                        else if(Board[i][j][0]=='B'){b++;}
                    }
                }
                if(b==0&&a>0){return 1;}
                if(a==0&&b>0){return 2;}
                return 0;
            }

