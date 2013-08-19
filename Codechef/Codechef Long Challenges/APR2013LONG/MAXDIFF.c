#include<stdio.h>
#include<stdlib.h>
int cmp(const void * a,const void* b)
{return (*(int *)a-*(int *)b);
}
int arr[100];
int main()
{int T,N,K;
scanf("%d",&T);
while(T--)
{scanf("%d%d",&N,&K);
 int i,total=0;
 for(i=0;i<N;i++)
 {scanf("%d",&arr[i]);
 }
 qsort(arr,N,sizeof(int),cmp);
 int Ksum=0,N_Ksum=0,diffl,diffr;
 for(i=0;i<K;i++)
  Ksum+=arr[i];
 for(;i<N;i++)
  N_Ksum+=arr[i];
  diffl=N_Ksum-Ksum;
  Ksum=N_Ksum=0;
  for(i=N-1;i>=N-K;i--)
  Ksum+=arr[i];
  for(;i>=0;i--)
  N_Ksum+=arr[i];
  diffr=Ksum-N_Ksum;
  if(diffr>diffl)
  printf("%d\n",diffr);
  else
  printf("%d\n",diffl);}
 return 0;
}
