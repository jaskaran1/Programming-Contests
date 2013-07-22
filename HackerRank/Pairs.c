#include<stdio.h>
#include<stdlib.h>
long long int arr[100000];
int binsearch(long long int x,int L,int U)
{
while(L<=U)
{int mid=(L+U)/2;
if(arr[mid]==x)
 return 1;
 else if(x<arr[mid])
 U=mid-1;
 else
 L=mid+1;
}
return 0;
}
int cmp(const void *a,const void *b)
{return (*(long long int *)a-*(long long int *)b);}

int main()
{int N,K;
 scanf("%d%d",&N,&K);
 int i;
 for(i=0;i<N;i++)
  scanf("%lld",&arr[i]);
 qsort(arr,N,sizeof(long long int),cmp);
 int count=0;
 for(i=0;i<N;i++)
 {if(binsearch(K+arr[i],0,N-1)==1)
	count++;
}
 printf("%d\n",count);
 return 0;}
