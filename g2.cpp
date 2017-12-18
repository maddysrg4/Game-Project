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
            void ArrangePawns(string s1[],string s2[])
            {
                for(int i=0;i<5;i++)
                {
                    Board[4][i]="A-"+s1[i];
                }
                for(int i=4;i>=0;i--)
                {
                    Board[0][i]="B-"+s2[4-i];
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


};

class Heros: public GameBoard
{
    public:
        virtual int* move(string s,int player)=0;
        int* FindPosition(string s,int player)
        {
            int flag=0;
            int *temp=new int[2];
            temp[0]=-1;
            temp[1]=-1;
            if(player==1){
                s="A-"+s.substr(0,2);
            }
            else
            {
                s="B-"+s.substr(0,2);
            }
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                {
                    if(Board[i][j]==s)
                    {
                        temp[0]=i;
                        temp[1]=j;flag=1;break;
                    }
                }
                if(flag==1){break;}
            }
            return temp;
        }
};
class Pawn: public Heros
{
    public:
        int* move(string s,int player)
        {
            int *position=FindPosition(s,player);
            int* old_new=new int[4];
            old_new[0]=-1;
            old_new[1]=-1;
            old_new[2]=-1;
            old_new[3]=-1;
            if(position[0]==-1){return old_new;}
            int i=position[0];
            int j=position[1];
            old_new[0]=i;
            old_new[1]=j;
            cout<<i<<"  "<<j<<endl;
            if(player==1)
            {
                if(s[3]=='F'){i--;}
                else if(s[3]=='B'){i++;}
                else if(s[3]=='L'){j--;}
                else if(s[3]=='R'){j++;}
            }
            old_new[2]=i;
            old_new[3]=j;
            return old_new;
        }
};

int main()
{
    int i;
    cout<<"Player1 Input:\n";
    string As[5]={"P3","P2","P5","P4","P1"},Bs[5]={"P2","P1","P3","P5","P4"};
   /* for(i=0;i<5;i++)
    {
        cin>>As[i];
    }*/
    cout<<endl<<"Player2 Input:\n";
  /*  for(i=0;i<5;i++)
    {
        cin>>Bs[i];
    }*/
//    As[]={"P3","P2","P5","P4","P1"};
  //  Bs[]={"P2","P1","P3","P5","P4"};
    GameBoard* game= new GameBoard();
    game->ArrangePawns(As,Bs);
    game->DisplayBoard();
    int turn=1,check=1;

      //  string s;

            cout<<"Player-1 Move: ";
          //  getline (cin, s);
            cout<<"2sg";
            Pawn p;cout<<"g";
            int* positions=p.move("P1:F",turn);
            cout<<"dsg";
            game->Board[positions[2]][positions[3]]=game->Board[positions[0]][positions[1]];
            game->Board[positions[0]][positions[1]]="-";
            game->DisplayBoard();
            cout<<"Pawn Displayed\n";

    delete game;
}
