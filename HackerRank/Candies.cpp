//candies
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{int N;
 scanf("%d",&N);
 int val[N],cand[N];
 for(int i=0;i<N;i++)
 {scanf("%d",&val[i]);
  cand[i]=1;
  }
 int tot=0;
 for(int i=0;i<N-1;i++)
 {if(val[i]<val[i+1])
  cand[i+1]=cand[i]+1;
  if(val[i]>val[i+1]&&cand[i]<=cand[i+1])
    {cand[i]=cand[i+1]+1;
    int j=i;
	while(j>=1&&val[j]!=val[j-1])//descending order
    {if(val[j-1]>val[j])
	cand[j-1]=cand[j]+1;
	 if(val[j-1]<val[j]&&cand[j-1]>=cand[j])
	 cand[j]=cand[j-1]+1;
	j--;}	
	}
 }
 for(int i=0;i<N;i++)
 tot+=cand[i];
 printf("%d\n",tot);
 return 0;
}
