#include<iostream>
#include<cstdio>
using namespace std;
double dp[100001][37];
int main()
{int i,j;
for(i=0;i<100001;i++)
	dp[i][0]=i;
 int T,N,K;
 double sum;
 scanf("%d",&T);
 while(T--)
 {scanf("%d %d",&N,&K);
  if(K<=36)
  {for(j=1;j<=K;j++)
	{sum=0;
     for(i=1;i<=N;i++)
		sum+=dp[i-1][j-1];
	     dp[i][j]=sum/(double)i;
	}
	printf("%lf\n",dp[i][j]);
   }
  else
	printf("0\n");
 }
return 0; 
}