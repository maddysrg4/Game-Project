
public class Pawn extends Heros
{
	public Pawn(String n,int player,int x,int y)
	{
		super(n,player,x,y);
	}
	public GameBoard move(String s,int player,GameBoard g)
	{
		char ch=s.charAt(3);
		switch(ch)
		{
			case 'F':
					if(player==1)
					{
						MoveForward(-1,g);
					}
					else
					{
						MoveForward(1,g);
					}
					break;
			case 'B':
					if(player==1)
					{
						MoveBackward(-1,g);
					}
					else
					{
						MoveBackward(1,g);
					}
					break;
			case 'L':
					if(player==1)
					{
						MoveLeft(-1,g);
					}
					else
					{
						MoveLeft(1,g);
					}
					break;
			case 'R':
					if(player==1)
					{
						MoveRight(-1,g);
					}
					else
					{
						MoveRight(1,g);
					}
					break;

		}
		return g;
	}
	
}