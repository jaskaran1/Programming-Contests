#include<stdio.h>
int p=1e9+7;
typedef long long ll;
ll dpp[1001][11];

int main()
{
int T,N,K;
for(K=1;K<=10;K++)
dpp[0][K]=dpp[1][K]=0;
for(K=1;K<=10;K++)
dpp[2][K]=K;
for(K=1;K<=10;K++)
{for(N=3;N<=1000;N++)
 {dpp[N][K]=((K*dpp[N-2][K])%p+((K-1)*dpp[N-1][K])%p)%p;}
}
scanf("%d",&T);
while(T--)
{scanf("%d%d",&N,&K);
 printf("%lld\n",dpp[N][K]);
}
return 0;
}