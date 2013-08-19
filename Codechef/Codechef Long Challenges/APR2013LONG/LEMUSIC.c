#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long ull;
typedef long long ll;
typedef struct song
{ll Bi;
 ll Li;}
 Song;
int compareBi(const void *v1,const void *v2)
{const Song *u1=v1;
 const Song *u2=v2;
 return (u1->Bi-u2->Bi);
}
int cmp(const void *v1,const void *v2)
{return (*(ll*)v1-*(ll*)v2);}
Song arr[100000];
ll minarr[100000];//stores the min of all Li of a fixed Bi.sort this 
int main()
{int T,N;
scanf("%d",&T);
while(T--)
{scanf("%d",&N);//No of songs
 int i,j;
 for(i=0;i<N;i++)
	scanf("%lld%lld",&arr[i].Bi,&arr[i].Li);
 qsort(arr,N,sizeof(Song),compareBi);
 i=0,j=0;
 ull Sum=0;//this will give us the Sum of all the repeated Bi's minus the min Li computed for every fixed Bi 
 ull sweet=0;
 while(i<N)
 {ll min=arr[i].Li;
  ll start=arr[i].Bi;
  while(arr[i].Bi==start&&i<N)
  {Sum+=arr[i].Li;
   if(min>arr[i].Li)
   min=arr[i].Li;
   i++;}
  Sum-=min;
  minarr[j++]=min;//finally j will contain the size of the minarr[] and also is equal to the number of distinct Bi's 
 }
 qsort(minarr,j,sizeof(ll),cmp);
 for(i=0;i<j;i++)
 sweet+=(i+1)*minarr[i];
 sweet+=Sum*j;
 printf("%llu\n",sweet);
}
return 0;
}