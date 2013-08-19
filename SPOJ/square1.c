#include<stdio.h>
#include<math.h>
int main(){int J,K,N,C;
for(J=1;J<=50;J++)
{scanf("%d",&N);
C=0;
for(K=0;K<=sqrt(N/2);K++)
{double a=sqrt(N-K*K);
if(a==floor(a))
C++;
}
printf("%d\n",C);
}
return 0;}
