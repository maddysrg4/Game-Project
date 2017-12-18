#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class GameBoard
{
    public:
        vector<vector<string> > Board;
            GameBoard()
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

            void DisplayBoard()
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
            int Check()
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

};

class Heros
{
    public:
        virtual  GameBoard* move(string s,int player,GameBoard* g)=0;
};
class Coordinates
{
    public:
    int x,y;
};
class Pawn: public Heros
{
    public:
        Coordinates p;
        string name;
        void Get(string s,int i,int j,int k)
        {
            p.x=i;
            p.y=j;
            if(k==1){
            name="A-"+s;}
            else
            {
                name="B-"+s;
            }
           // g->Board[i][j]=name;
        }
        GameBoard* move(string s,int player,GameBoard *g)
        {
            int i=p.x;
            int j=p.y;
            if(player==1)
            {
                if(s[3]=='F'){i--;}
                else if(s[3]=='B'){i++;}
                else if(s[3]=='L'){j--;}
                else if(s[3]=='R'){j++;}
            }
            else
            {
                if(s[3]=='F'){i++;}
                else if(s[3]=='B'){i--;}
                else if(s[3]=='L'){j++;}
                else if(s[3]=='R'){j--;}
            }
            g->Board[i][j]=g->Board[p.x][p.y];
            g->Board[p.x][p.y]="-";
            p.x=i;
            p.y=j;
            return g;
        }
        int ErrorCheck(string s,int player,GameBoard *g)
        {
            if(player==1)
            {
                if(s[3]=='F'){i-1<0;return 1;}
                else if(s[3]=='B'){i+1>4;return 1;}
                else if(s[3]=='L'){j-1<0;return 1;}
                else if(s[3]=='R'){j+1>4;return 1;}

            }
        }
};

int main()
{
    int i;
    cout<<"Player1 Input:\n";
   // string As[5]={"P3","P2","P5","P4","P1"},Bs[5]={"P2","P1","P3","P5","P4"};

    GameBoard* game= new GameBoard();
    Pawn p1[50],p2[50];
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
            game=p1[p-1].move(s,1,game);
            game->DisplayBoard();
            turn=2;
        }
        else
        {
            cout<<"Player2 move: ";
            string s;
            cin>>s;
            int p=s[1]-'0';
            game=p2[p-1].move(s,2,game);
            game->DisplayBoard();
            turn=1;
        }
        int p=game->Check();
        if(p==1){cout<<"Player A wins\n";break;}
        else if(p==2){cout<<"Player B wins\n";break;}

    }
}
