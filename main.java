import java.util.*;

public class main{  
    public static void main(String args[]){  
     	
     	GameBoard game=new GameBoard();
     	Heros[] p1=new Heros[5];
     	Heros[] p2=new Heros[5];
     	takeinput(game,p1,p2);
    }  
    public static void takeinput(GameBoard game,Heros p1[],Heros p2[])
{
		Scanner input=new Scanner(System.in);
	System.out.println("Player A input");
     	int i,j;
     	for(i=0;i<5;i++)
     	{
     		String s= input.nextLine();
     		if(s.charAt(0)=='P')
     		{
     			p1[i]=new Pawn(s,1,4,i);
     			game.Board[4][i]="A-"+s;
     		}
     	}
     	System.out.println("\nPlayer B input");
     	for(i=4;i>=0;i--)
     	{
     		String s= input.nextLine();
     		if(s.charAt(0)=='P')
     		{
     			p2[4-i]=new Pawn(s,2,0,i);
     			game.Board[0][i]="B-"+s;
     		}
     	}
     	int turn=1;
     	game.DisplayBoard();
     	
     	while(true)
     	{
     		if(turn==1)
     		{
     			System.out.println("Player A turn");
     			int flag=0;
     			String s=input.nextLine();
     			String tem="A-"+s.substring(0,2);
     			for(i=0;i<5;i++)
     			{

     				if(p1[i].name.equals(tem)&&p1[i].PlayerStatus)
					{
						flag=1;break;
					}
     			}
     			if(flag==0){System.out.println("Player Already Dead\n");continue;}
     			int[] temp=new int[2];
     			temp=p1[i].NewPosition(s,1);
     			int fl=game.ErrorCheck(temp[0],temp[1],p2,-1,game);
     			if(fl==-1){continue;}
     			if(fl!=-2){p2[fl].PlayerStatus=false;}
     			game=p1[i].move(s,1,game);
     			turn=2;
     		}
     		else
     		{
     			System.out.println("Player B turn");
     			int flag=0;
     			String s=input.nextLine();
     			String tem="B-"+s.substring(0,2);
     			for(i=0;i<5;i++)
     			{
     				if(p2[i].name.equals(tem)&&p2[i].PlayerStatus)
					{
						flag=1;break;
					}
     			}
     			if(flag==0){System.out.println("Player Already Dead\n");continue;}
     			int[] temp=new int[2];
     			temp=p2[i].NewPosition(s,2);
     			int fl=game.ErrorCheck(temp[0],temp[1],p1,1,game);
     			if(fl==-1){continue;}
     			if(fl!=-2){p1[fl].PlayerStatus=false;}
     			game=p2[i].move(s,2,game);
     			turn=1;
     		}
     		game.DisplayBoard();
     		int p=game.check();
        if(p==1){System.out.println("Player A wins\n");break;}
        else if(p==2){System.out.println("Player B wins\n");break;}
     	}
}
}  
