import java.util.*;

public class GameBoard
{
	String Board[][]=new String[5][5];
	public GameBoard()
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				Board[i][j]="-";
			}
		}
	}
	public void DisplayBoard()
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				System.out.print(Board[i][j]+" ");
			}
			System.out.print("\n");
		}
	}
	public int check()
	{
		int a=0,b=0;
        for(int i=0;i<5;i++)
           {
             for(int j=0;j<5;j++)
              {
                 if(Board[i][j].charAt(0)=='A'){a++;}
                 else if(Board[i][j].charAt(0)=='B'){b++;}
               }
           	}
         if(b==0&&a>0){return 1;}
         if(a==0&&b>0){return 2;}
           return 0;
	}
	public int ErrorCheck(int temp1,int temp2,Heros h[],int factor,GameBoard g)
	{
		System.out.println(temp1+" "+temp2);
		if(isOutofBoard(temp1,temp2))
		{
			System.out.print("Out of Board\n");return -1;
		}
		if(g.Board[temp1][temp2]!="-")
		{
			if(isAlly(temp1,temp2,g,factor))
			{
				System.out.print("Own Player Standing\n");return -1;
			}
			int index=FindHero(temp1,temp2,h,g);
			return index;
		}
		return -2;
	}
	public boolean isOutofBoard(int temp1,int temp2)
	{
		if((temp1>=0&&temp1<5)&&(temp2>=0&&temp2<5))
		{
			return false;
		}
		return true;
	}
	public boolean isAlly(int temp1,int temp2,GameBoard g,int factor)
	{
		if(factor==-1){if(g.Board[temp1][temp2].charAt(0)=='A')return true;}
		else if(factor==1){if(g.Board[temp1][temp2].charAt(0)=='B')return true;}
		return false;
	}
	public int FindHero(int temp1,int temp2,Heros h[],GameBoard g)
	{
		for(int i=0;i<5;i++)
		{
			if(h[i].name==g.Board[temp1][temp2])
			{
				return i;
			}
		}
		return -2;
	}
}