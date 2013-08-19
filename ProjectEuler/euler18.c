//Project Euler
//Max path sum 1 prob 18 & prob 67
#include<stdio.h>//header file for input and output functions scanf() and printf()
#include<stdlib.h>//header file for dynamic allocation of array

int max(int a,int b)
{return (a>b)?a:b;}//ternary operator.

int main()
{int N;
scanf("%d",&N);//Number of rows
int **dp=(int**)malloc(N*sizeof(int*));
int i;
for(i=0;i<N;i++)
	dp[i]=(int*)malloc((i+1)*sizeof(int));//dp is basically an array in which the ith row contains i cells.dp[i][j] means the i,jth entry of the array
int j;
for(i=0;i<N;i++)
	{for(j=0;j<=i;j++)
		scanf("%d",&dp[i][j]);}//input for the dp array
	 for(i=1;i<N;i++)//loop for all rows
		{dp[i][0]+=dp[i-1][0];//dp[i][0]=dp[i][0]+dp[i-1][0]for the starting element of the row.its parent is the element above it
		 for(j=1;j<i;j++)
			dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);//dp[i][j]=dp[i][j]+max of (i,j)'s parents
		 dp[i][i]+=dp[i-1][i-1];//for the last element of the row.
		}
int M=dp[N-1][0]; 
for(i=1;i<N;i++)
	M=max(M,dp[N-1][i]);
printf("ans=%d\n",M);  
return 0;}