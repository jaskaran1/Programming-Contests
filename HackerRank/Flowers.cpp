//Flowers
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int cmp(const void* a,const void* b)
{int *p=(int*)a;
 int *q=(int *)b;
 return *q-*p;//sorts in decreasing order
}
int main()
{int N,K;
 scanf("%d%d",&N,&K);
 int price[N];
 for(int i=0;i<N;i++)
 scanf("%d",&price[i]);
 long long amt=0;
 qsort(price,N,sizeof(int),cmp);
 int i=0;
 int k=0;
 int ct=1;
 while(i<N)
 {amt+=ct*price[i];
  i++;
  k++;
  if(k==K)
  {ct++;
   k=0;
  }
  }
  printf("%lld\n",amt);
  return 0;
}
