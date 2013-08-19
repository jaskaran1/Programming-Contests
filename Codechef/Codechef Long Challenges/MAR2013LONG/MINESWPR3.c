#include<stdio.h>//The Checkunseen function is to be corrected.
int board[50][50]={0};//it means that the all squares are unseen.A 1 means that this square has been taken into consideration and no survey or neutralize to be applied.
int count=0;
int N,K,M;
char Survey(int x,int y)
{printf("S %d %d\n",x,y);
 fflush(stdout);
  board[x][y]=1;//since the cell has been seen.
  char res;
  getchar();
  scanf("%c",&res);
  return res;}
void Neutralize(int x,int y)
{printf("N %d %d\n",x,y);
 count++;
 board[x][y]=1;
 //fflush(stdout);
 }
int Checkunseen(i,j)
{if(i>=0&&i<N-1&&j>0&&j<N-1)
 {if(Survey(i,j+1)!='M')
  {if(board[i+1][j-1]==0)
   Neutralize(i+1,j-1);
   if(board[i+1][j]==0)
   Neutralize(i+1,j);
   if(board[i+1][j+1]==0)
   Neutralize(i+1,j+1);
   board[i][j+1]=0;//this square will be surveyed again in the main loop
   }
  else
  {Neutralize(i,j+1);
	if(Survey(i+1,j-1)!='M')
		{board[i+1][j-1]=0;
		 if(board[i+1][j]==0)
		 Neutralize(i+1,j);
		 if(board[i+1][j+1]==0)
		 Neutralize(i+1,j+1);
		}
	else
	{Neutralize(i+1,j-1);
	 if(Survey(i+1,j)!='M')
		{board[i+1][j]=0;
		 if(board[i+1][j+1]==0)
		 Neutralize(i+1,j+1);}
	 else
	 Neutralize(i+1,j);
	}   
   }  
 }
 else if(j==0&&i<N-1)
 {//2 mines are surrounding the square
  if(Survey(i,j+1)!='M')
	{if(board[i+1][j]==0)
	 Neutralize(i+1,j);
	 if(board[i+1][j+1]==0)
	 Neutralize(i+1,j+1);
	 board[i][j+1]=0;}
   else 
   {Neutralize(i,j+1);
    if(Survey(i+1,j)!='M')
    {if(board[i+1][j+1]==0)
		Neutralize(i+1,j+1);
	 board[i+1][j]=0;}
	 else
	 Neutralize(i+1,j);
    }
   
 }
if(count==M)
return -1; 
} 
int Unseen(int i,int j)
{int k=0;//counts the number of unseen squares
	if(i>=0&&i<N-1&&j>0&&j<N-1)
	{int r;
	 int c;
	 for(r=i;r<=i+1;r++)
		{for(c=j-1;c<=j+1;c++)
			{if(r==i&&c==j)
				continue;
			 else
				{if(board[r][c]==0)
				 k++;}
			} 
		}
	}
	else if(j==0&&i<N-1)
		{if(board[i][j+1]==0)
		  k++;
		 if(board[i+1][j]==0)
		  k++;
		 if(board[i+1][j+1]==0)
		  k++;
		}
	else if(i==N-1&&j<N-1)
		{if(board[i][j+1]==0)
		  k++;
		}
	else if(j==N-1&&i<N-1)
		{if(board[i+1][j-1]==0)
		 k++;
		 if(board[i+1][j]==0)
		 k++;
		}
return k; 
}
int  MarkUnseen(int i,int j)
{	if(i>=0&&i<N-1&&j>0&&j<N-1)
	{int r;
	 int c;
	 for(r=i;r<=i+1;r++)
		{for(c=j-1;c<=j+1;c++)
			{if(r==i&&c==j)
				continue;
			 else
				{if(board[r][c]==0)
				 Neutralize(r,c);}
			} 
		}
	}
	else if(j==0&&i<N-1)
		{if(board[i][j+1]==0)
		  Neutralize(i,j+1);
		 if(board[i+1][j]==0)
		  Neutralize(i+1,j);
		 if(board[i+1][j+1]==0)
		  Neutralize(i+1,j+1);
		}
	else if(i==N-1&&j<N-1)
		{if(board[i][j+1]==0)
		  Neutralize(i,j+1);
		}
	else if(j==N-1&&i<N-1)
		{if(board[i+1][j-1]==0)
		 Neutralize(i+1,j-1);
		 if(board[i+1][j]==0)
		 Neutralize(i+1,j);
		}
	if(count==M)
		return -1;
		}

int main()
{
scanf("%d %d %d",&N,&M,&K);//M-no of mines,K-no of dynamite
int i,j;
for(i=0;i<N;i++)//rowwise exploration
	{for(j=0;j<N;j++)
		{if(board[i][j]==1)//these cells aren't counted as they've been explored
		 continue;
		 char x=Survey(i,j);//(i,j) is seen.
		 if(x=='M')
			{Neutralize(i,j);//(i,j) is counted as a mine
			 if(count==M)
			 {printf("Done\n");
			  return 0;}
			}
		 else
			{int Y=x-'0';//Y is the number of mines in the surrounding squares
			 //printf("mines=%d\n",Y);
			 if(Y==0)//mark its surrounding explored
			 {if(0<i&&i<N-1&&0<j&&j<N-1)
				board[i][j+1]=board[i+1][j+1]=board[i+1][j]=board[i+1][j-1]=1;
			  else if(i==0)
				{if(j==0)
				  board[i][j+1]=board[i+1][j]=board[i+1][j+1]=1;
				 else if(j==N-1)
				  board[i+1][j]=board[i+1][j-1]=1;
				 else
				  board[i][j+1]=board[i+1][j+1]=board[i+1][j]=board[i+1][j-1]=1;
				  }
			  else if(i==N-1&&j<N-1)
			    board[i][j+1]=1;
			  else if(j==0)
			  board[i+1][j]=board[i+1][j+1]=board[i][j+1]=1;
			  else if(j==N-1)
			  board[i+1][j]=board[i+1][j-1]=1;	
			 }
			 else
			 {int u=Unseen(i,j);//Unseen is a function which gives the number of unseen squares(0) in the surrounding of (i,j)
			  //printf("Unseen=%d\n",u);
			  if(Y==u)
			  {int stat=MarkUnseen(i,j);//it marks the unseen squares and counts them as mines by neutralizing them.since these unseen squares are mines.
			   if(stat==-1)
			   {printf("Done\n");
			    return 0;}
			   }
			   else if(Y>u/2)
			   {//printf("Entered checkseen");
			    //printf("Y=%d,u=%d\n",Y,u);			   
			    int stat=Checkunseen(i,j);
			    if(stat==-1)
				{printf("Done\n");
			    return 0;
				}
				}//surveys the unseen squares for mines and neutralizes them if its a mine
			 }
			}
		}	
	}
return 0;	
}