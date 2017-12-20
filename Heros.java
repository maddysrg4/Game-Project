
public abstract class Heros
{
	String name;
	boolean PlayerStatus;
	Coordinates p;
	public abstract GameBoard move(String s,int player,GameBoard g);

	public Heros(String n,int player,int x,int y)
	{
		if(player==1)
		{
			name="A-"+n;
		}
		else
		{
			name="B-"+n;
		}
		PlayerStatus=true;
		p=new Coordinates(x,y);
	}
	public void MoveForward(int factor,GameBoard g)
	{
		int temp1=p.x+factor;
		int temp2=p.y;
						//System.out.print(temp1+"   "+temp2);
		update(g,temp1,temp2);

	}
	public void MoveBackward(int factor,GameBoard g)
	{
		int temp1=p.x-factor;
		int temp2=p.y;
		update(g,temp1,temp2);
	}
	public void MoveLeft(int factor,GameBoard g)
	{
		int temp1=p.x;
		int temp2=p.y+factor;
		update(g,temp1,temp2);
	}
	public void MoveRight(int factor,GameBoard g)
	{
		int temp1=p.x;
		int temp2=p.y-factor;
		update(g,temp1,temp2);
	}
	public void update(GameBoard g,int temp1,int temp2)
	{
		g.Board[temp1][temp2]=name;
		g.Board[p.x][p.y]="-";
		p.x=temp1;p.y=temp2;
	}
//	public int FindHero(int temp1,int temp2)
	public int[] NewPosition(String s,int player)
	{
		int[] temp=new int[2];
		char ch=s.charAt(3);
		switch(ch)
		{
			case 'F':
					if(player==1)
						{temp[0]=p.x-1;
						temp[1]=p.y;}
					else if(player==2)
						{temp[0]=p.x+1;
						temp[1]=p.y;}
					break;
			case 'B':
					if(player==2)
						{temp[0]=p.x-1;
						temp[1]=p.y;}
					else if(player==1)
						{temp[0]=p.x+1;
						temp[1]=p.y;}
					break;
			case 'L':
					if(player==1)
						{temp[0]=p.x;
						temp[1]=p.y-1;}
					else if(player==2)
						{temp[0]=p.x;
						temp[1]=p.y+1;}
					break;
			case 'R':
					if(player==1)
						{temp[0]=p.x;
						temp[1]=p.y+1;}
					else if(player==2)
						{temp[0]=p.x;
						temp[1]=p.y-1;}
					break;

		}
		return temp;
	}
}