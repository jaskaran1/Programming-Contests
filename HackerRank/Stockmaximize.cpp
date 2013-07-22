//stock maximize
//start from the end
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 int T,price[50000],N;
 scanf("%d",&T);
 while(T--)
 {scanf("%d",&N);
  for(int i=0;i<N;i++)
  scanf("%d",&price[i]);
  int m=0;
  long long prof=0;
  for(int i=N-1;i>=0;i--)
  {int ai=price[i];
   if(m<=ai)
    m=ai;
   prof+=m-ai;	
  }
  printf("%lld\n",prof);
 }
return 0;}
