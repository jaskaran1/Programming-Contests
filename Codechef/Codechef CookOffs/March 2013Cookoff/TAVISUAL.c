#include<stdio.h>
int main()
{int T;
int N,C,Q;
int L,R;
scanf("%d",&T);
while(T--)
{scanf("%d %d %d",&N,&C,&Q);
while(Q--)
{scanf("%d %d",&L,&R);
if(C<L||C>R)
 continue;
 else
 C=R-C+L;
}
printf("%d\n",C);
}
return 0;}