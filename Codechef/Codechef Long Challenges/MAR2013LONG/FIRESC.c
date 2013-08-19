#include<stdio.h>//Weighted Union Find(amortized O(m+nlog*n)) m is the union find ops and n is elems
int prime=1e9+7;
int id[100001];//id of the employees.id[i] points to the root of the ith element
int sz[100001]={0};//sz[i] gives size of tree rooted at i

int root(int i,int id[])//path compression find
{while(i!=id[i])
	{id[i]=id[id[i]];
	 i=id[i];
     }
 return i;}

void unite(int p,int q,int id[])//weighted union find
{int i=root(p,id);
 int j=root(q,id);
 if(i!=j)//the 2 elements belong to distinct sets
 {if(sz[i]<sz[j])
	{id[i]=j;
	 sz[j]+=sz[i];}
  else
	{id[j]=i;
	 sz[i]+=sz[j];}
  }
 }

int main()
{int T,N,M;
 scanf("%d",&T);//no of test cases
 while(T--)
	{int escapes=0;
     long long int ways=1;
	 scanf("%d",&N);//no of employees
	 scanf("%d",&M);//no of friendship relations
	 int i,j,k;
	 for(i=1;i<=N;i++)//all are disjoint sets
		{id[i]=i;
		 sz[i]=1;}
	 for(k=0;k<M;k++)
		{scanf("%d %d",&i,&j);
		 unite(i,j,id);
		 }
     for(i=1;i<=N;i++)
	 {if(id[i]==i)//the ith element is the root
	  {escapes++;
	   ways=(ways*sz[i])%prime;}
	 }
	 printf("%d %lld\n",escapes,ways);
	 }
return 0;
}