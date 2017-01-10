#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>


int flag = 0;


class sudoku
{
	int a[9][9];
	int b[9][9],k,l,m,z,g,h;
	public:
	void ip(); 	//For Input
	void inst();	//For Instructions
	void checker();	//In cases of ambiguity
	void op();	//For output
	int crow(int,int,int);	//To check row
	int ccol(int,int,int);	//To check column
	int cbox(int,int,int);	//To check grid
	int assume(int,int);	//For assuming and inserting the values into blank squares.
};


int get_grid(int);
void title();
void square(int,int,int);
int color_check(int);


void sudoku::ip()
{

	int i, j;
	cout<<"\t\t\tSUDOKU SOLVER\n\n\n";
	for(i=0;i<9;i++)
	{
		cout<<"\n\nENTER THE VALUES FOR ROW "<<i+1<<": \n\n";
		for(int j=0;j<9;j++)
			cin>>a[i][j];
	}
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		   b[i][j]=a[i][j];
		   getch();
		   clrscr();

	int gdriver = EGA, gmode = EGAHI;
	initgraph(&gdriver, &gmode, "c:/tc/bgi");

	char *msg;
	int color=1;
	int rowcount=0;
	int colcount=0;
	int startrow=175;
	int startcol=75;
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	for(rowcount=0;rowcount<9;rowcount++)
	{
	   startrow=175;
	   for(colcount=0;colcount<9;colcount++)
	   {
	       square(startrow,startcol,30);
	       startrow=startrow+30;
	       delay(200);
	   }
	   startcol=startcol+30;

	}
	startrow=180;
	startcol=80;
	for(colcount=1;colcount<=9;colcount++)
	{
	 setcolor(color);
	 sprintf(msg,"%d",colcount);
	 outtextxy(150,startcol,msg);
	 startcol=startcol+30;
	 color++;
	 delay(500);
	}
	color=1;
	for(rowcount=1;rowcount<=9;rowcount++)
	{
	 setcolor(color);
	 sprintf(msg,"%d",rowcount);
	 outtextxy(startrow,50,msg);
	 startrow=startrow+30;
	 color++;
	 delay(500);
	}
	 startrow=180;
	 startcol=80;
	 color=1;

	cout<<"\t\t\t\tENTERED SUDOKU";
	for(rowcount=0;rowcount<9;rowcount++)
	{
	 startrow=180;
	 for(colcount=0;colcount<9;colcount++)
	 {
	  if(b[rowcount][colcount]==0)
	  {
	   outtextxy(startrow,startcol," ");
	  }
	  else
	  {
	  color=color_check(b[rowcount][colcount]);
	  setcolor(color);
	  sprintf(msg,"%d",b[rowcount][colcount]);
	  outtextxy(startrow,startcol,msg);
	  }
	  startrow=startrow+30;
	  delay(500);
	 }
	 startcol=startcol+30;
	}
	getch();
	closegraph();
}
void sudoku::inst()
{
	cout<<"\t\t\tSUDOKU SOLVER\n\n\n\n\n";
	delay(2000);
	cout<<"INSTRUCTIONS - READ CAREFULLY!\n\n\n";
	delay(2000);
	cout<<"1. THIS IS A 9X9 SUDOKU SOLVER\n"<<endl;
	delay(2000);
	cout<<"2. ENTER A VALID SUDOKU PUZZLE\n"<<endl;
	delay(2000);
	cout<<"3. ENTER THE VALUES ROW-WISE\n"<<endl;
	delay(2000);
	cout<<"4. ENTER 0 FOR BLANK SQUARES\n"<<endl;
	delay(2000);
	cout<<"5. ALL THE CLUES ENTERED SHOULD BE IN THE RANGE OF 1-9\n"<<endl;
	delay(2000);
	cout<<"6. IT WOULD BE EASIER FOR YOU TO ENTER IN THIS FORMAT\n"<<endl;
	delay(2000);
	cout<<"\t\t"<<"ENTER THE VALUES FOR ROW 1: "<<endl<<"\t\t";
	delay(2000);
	cout<<"0 0 7 4 0 0 2 0 9\n"<<endl;
	delay(2000);
	cout<<"7. "<<"AFTER THIS ENTRY, PRESS ENTER. IT WILL GO TO THE NEXT ROW.\n"<<endl;
	delay(2000);
	cout<<"8. THE 6TH STEP IS NOT NECESSARY. IT IS A PREFERRED WAY OF ENTERING THE VALUES.\n"<<endl;
	delay(2000);
	cout<<"9. IN THIS WAY, ANY MISTAKE MADE IN A ROW ENTRY CAN BE CORRECTED\n"<<endl;
	delay(2000);
	cout<<"10. ONLY 9 VALUES SHOULD BE ENTERED FOR A ROW.\n"<<endl;
}
void sudoku::op()
{
	int gdriver = EGA, gmode = EGAHI;
	initgraph(&gdriver, &gmode, "c:/tc/bgi");

	char *msg;
	int color=1;
	int rowcount=0;
	int colcount=0;
	int startrow=175;
	int startcol=75;
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	for(rowcount=0;rowcount<9;rowcount++)
	{
	   startcol=75;
	   for(colcount=0;colcount<9;colcount++)
	   {
	       square(startrow,startcol,30);
	       startcol=startcol+30;
	       delay(200);
	   }
	   startrow=startrow+30;

	}
	startrow=180;
	startcol=80;
	for(colcount=1;colcount<=9;colcount++)
	{
	 setcolor(color);
	 sprintf(msg,"%d",colcount);
	 outtextxy(startrow,50,msg);
	 startrow=startrow+30;
	 color++;
	 delay(500);
	}
	color=1;
	for(rowcount=1;rowcount<=9;rowcount++)
	{
	 setcolor(color);
	 sprintf(msg,"%d",rowcount);
	 outtextxy(150,startcol,msg);
	 startcol=startcol+30;
	 color++;
	 delay(500);
	}
	 startrow=180;
	 startcol=80;
	color=1;

	cout<<"\t\t\t\tSOLVED SUDOKU";
	for(rowcount=0;rowcount<9;rowcount++)
	{
	 startcol=80;
	 for(colcount=1;colcount<=9;colcount++)
	 {
	  color=color_check(b[rowcount][colcount]);
	  setcolor(color);
	  sprintf(msg,"%d",b[rowcount][colcount]);
	  outtextxy(startrow,startcol,msg);
	  startcol=startcol+30;
	  delay(500);
	 }
	 startrow=startrow+30;
	}
	getch();
	closegraph();
}
void sudoku::checker()
{
	int i, j;
	for(i=0;i<9;i=i+1)
		for(j=0;j<9;j=j+1)
		{
			//First iteration flag is 0. In cases of ambiguity, flag is 1.
			if(a[i][j]==0)
			{
				if(flag)
				{
					i=g;j=h;
					flag=0;
				}
				if(assume(i,j)==2)
				{
					flag=1;
					if(j==0)
					{
						h=8;
						g=i;
						g--;
					}
					else
					{
						g=i;
						h=j;
						h--;
					}
					if(a[g][h]!=0)
					{
						if(h==0)
						{
							h=8;
							g--;
						}
						else
						{
							h--;
						}
						if(a[g][h]!=0)
						{
							if(h==0)
							{
								h=8;
								g--;
							}
							else
							{
								h--;
							}
							if(a[g][h]!=0)
							{
								if(h==0)
								{
									h=8;
									g--;
								}
								else
								{
									h--;
								}
								if(a[g][h]!=0)
								{
									if(h==0)
									{
										h=8;
										g--;
									}
									else
									{
										h--;
									}
								}
							}
						}
					}
				}
			}
		}
}

void main()
{
	clrscr();
	sudoku s;

	title();
	s.inst();
	clrscr();
	s.ip();
	clrscr();
	s.checker();
	s.op();

	getch();
}



int sudoku::crow(int i,int j,int z)
{
	k=i;l=j;
	for(j=0;j<9;j++)
	{
		if(j==l)
		{
			if(j==8)
				break;
			j++;
		}
		if((z==b[i][j]))
		return 0;
	}
	return 1;
}
int sudoku::ccol(int i,int j,int z)
{
	k=i;
	l=j;
	for(i=0;i<9;i++)
	{
		if(i==k)
		{
			if(i==8)
				break;
			i++;
		}
		if((z==b[i][j]))
			return 0;
	}
	return 1;
}
int sudoku::cbox(int i,int j,int z)
{
	int m,n,a,c;
	int get_grid(int);
	sudoku s;
	k=i;
	l=j;
	m=get_grid(i);
	n=get_grid(j);
		for(a=m;a<=m+2;a++)
		{
			for(c=n;c<=n+2;c++)
			{
				if((k!=a&&l!=c)&&(z==b[a][c])) //checkout here
					return 0;
			}
		}
		return 1;
}

int sudoku::assume(int i,int j)
{
	m=b[i][j]+1;
	while(1)
	{
		b[i][j]=m;
		if(m>9)
		{
			b[i][j]=0;
			return 2;
		}
		if(ccol(i,j,b[i][j]))
		if(crow(i,j,b[i][j]))
		if(cbox(i,j,b[i][j]))
		{
			b[i][j]=m;
			return 0;
		}
		m++;
	}
}
int get_grid(int p)
{
	int c, f;
	c=p/3;
	switch(c)
	{
		case 0:
			f = 0;
			break;
		case 1:
			f = 3;
			break;
		case 2:
			f = 6;
			break;
	}
	return f;
}

void title()
{
    int gdriver = EGA, DETECT, gmode=EGAHI;
    char msg[20];
    initgraph(&gdriver, &gmode, "c:/tc/bgi");

    setbkcolor(RED);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
    delay(1000);
    setcolor(9);
    sprintf(msg,"SUDOKU SOLVER");
    outtextxy((getmaxx()/3), (getmaxy()/3), msg);

    delay(2000);
    closegraph();
 }

 void square(int x, int y, int l)
 {
    moveto(x+l,y);
    lineto(x+l,y+l);
    lineto(x,y+l);
    lineto(x,y);
    lineto(x+l,y);
 }

 int color_check(int c)
 {
  int f,ch;
  ch=c;
  switch(ch)
  {
  case 1:
  f=1;
  break;

  case 2:
  f=2;
  break;

  case 3:
  f=3;
  break;

  case 4:
  f=4;
  break;

  case 5:
  f=5;
  break;

  case 6:
  f=6;
  break;

  case 7:
  f=7;
  break;

  case 8:
  f=8;
  break;

  case 9:
  f=9;
  break;
  }
  return f;
 }