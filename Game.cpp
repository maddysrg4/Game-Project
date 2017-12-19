#include<iostream>
#include<vector>
#include<limits>
using namespace std;
class Pawn;
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
        virtual  GameBoard* move(string s,int player,GameBoard* g,Pawn *p1,Pawn *p2)=0;
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
        GameBoard* move(string s,int player,GameBoard *g,Pawn *p1,Pawn *p2)
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
            if(g->Board[i][j][0]!='-'){
                    s=g->Board[i][j];
                    int p=s[3]-'0';
                    if(player==2){
                    p1[p-1].p.x=-1;
                    p1[p-1].p.y=-1;}
                    else
                    {
                        p2[p-1].p.x=-1;
                        p2[p-1].p.y=-1;
                    }

            }
            g->Board[i][j]=g->Board[p.x][p.y];
            g->Board[p.x][p.y]="-";
            p.x=i;
            p.y=j;
            return g;
        }
        int ErrorCheck(string s,int player,GameBoard *g)
        {
            int i=p.x;
            int j=p.y;

            if(player==1)
            {
                if(s[3]=='F'){if(i-1<0){return 1;}}
                else if(s[3]=='B'){if(i+1>4){return 1;}}
                else if(s[3]=='L'){if(j-1<0){return 1;}}
                else if(s[3]=='R'){if(j+1>4){return 1;}}
                if(s[3]=='F'){if(g->Board[i-1][j][0]=='A') return 2;}
                else if(s[3]=='B'){if(g->Board[i+1][j][0]=='A') return 2;}
                else if(s[3]=='L'){if(g->Board[i][j-1][0]=='A') return 2;}
                else if(s[3]=='R'){if(g->Board[i][j+1][0]=='A') return 2;}
            }
            else
            {
                if(s[3]=='F'){if(i+1>4){return 1;}}
                else if(s[3]=='B'){if(i-1<0){return 1;}}
                else if(s[3]=='L'){if(j+1>4){return 1;}}
                else if(s[3]=='R'){if(j-1<0){return 1;}}
                if(s[3]=='F'){if(g->Board[i+1][j][0]=='B') return 2;}
                else if(s[3]=='B'){if(g->Board[i-1][j][0]=='B') return 2;}
                else if(s[3]=='L'){if(g->Board[i][j+1][0]=='B') return 2;}
                else if(s[3]=='R'){if(g->Board[i][j-1][0]=='B') return 2;}
            }
            return 0;
        }
};

int main()
{
    int i;
    cout<<"Player1 Input:\n";
   // string As[5]={"P3","P2","P5","P4","P1"},Bs[5]={"P2","P1","P3","P5","P4"};

    GameBoard* game= new GameBoard();
//    Pawn* p1=new Pawn[50];
    Pawn p1[5],p2[5];
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
            if(p1[p-1].p.x==-1){cout<<"Player Already Dead\n";continue;}
            int error=p1[p-1].ErrorCheck(s,1,game);
            if(error==1){cout<<"Out of Board\n";continue;}
            else if(error==2){cout<<"Own Player standing\n";continue;}

            game=p1[p-1].move(s,1,game,p1,p2);
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
            game=p2[p-1].move(s,2,game,p1,p2);
            game->DisplayBoard();
            turn=1;
        }
        int p=game->Check();
        if(p==1){cout<<"Player A wins\n";break;}
        else if(p==2){cout<<"Player B wins\n";break;}

    }
}
