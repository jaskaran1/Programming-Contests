//Picking cards
//The idea:sort the array as we have to find all the possible order
//Now for every card having value ci which is on the position i(starts from 1)
//the number of swaps for this card which don't break the property are i-ci
//since all th possible swaps for this card are
//(i,i-1);(i,i-2);(i,i-3);........(i,ci+1) which are i-ci swaps
//if i-ci<=0 then its not possible to pick the cards up.
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int cmp(const void *a,const void *b)
{return (*(int *)a-*(int *)b);
}
int main()
{int T,N;
scanf("%d",&T);
const int p=1e9+7;
while(T--)
{scanf("%d",&N);
 int a[N];
 for(int i=0;i<N;i++)
 scanf("%d",&a[i]);
 qsort(a,N,sizeof(int),cmp);//sorted in increasing order
 long long ways=1;
 for(int i=N-1;i>=0;i--)//I'll consider index of cards starting from 1 ie a[0] is card1 with value a[0]
 {if(i+1-a[i]>0)
  ways=(ways*(i+1-a[i]))%p;
  else
  {ways=0;
   break;}
 }
printf("%lld\n",ways);
 }
return 0;
}
