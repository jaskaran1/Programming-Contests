#include<stdio.h>
#include<stdlib.h>
double expect(int N,int K,double mem[])//going from bottom to up
{double sum;
 int i;
 if(N<=K)
	return 0;
 if(K==0)
	return N;
 if(K==1)
	return mem[N-K-1];
 else if(K==2)
	{for(i=0;i<=N-K-1;i++)
	  sum+=mem[i];
	 sum=sum/N;
     return sum;	 
	}
 else//when K>2
	{int k;
	 for(k=2;k<=K-1;k++)
			{int last=N-K+k;
			    sum=0;
				int j;
				for(j=last-k-1;j>=0;j--)
					sum=sum+mem[j];
				int temp=mem[last-k-1];
                mem[last-k-1]=sum/last;
				if(mem[last-k-1]<1e-6)
					return 0;
				last--;
				while(last-k-1>=0)
					{sum=sum-temp;
					 temp=mem[last-k-1];
					 mem[last-k-1]=sum/last;
					 last--;	
					}
			 //printf("for k=%d\n",k);		
			 //for(i=0;i<=N-K-1;i++)		
			  // printf("%lf\n",mem[i]);
			// printf("--------\n"); 
			}//after this the computation for the K-1 column is complete
	 sum=0;
     for(i=0;i<=N-K-1;i++)
		sum=sum+mem[i];
	 sum=sum/N;
	 //printf("loop exit\n");
	 return sum;
	}
}
int main()
{int T,N,K;
 double ans;
 int i; 
 scanf("%d",&T);
 double mem[100000];
 while(T--)
	{scanf("%d %d",&N,&K);
	 //printf("for k=1\n");
	 for(i=0;i<=N-K-1;i++)//N=i+2.N ranges from 1 to N-K+1.
		{mem[i]=(i+1)/2.0;//(N,1)=(N-1)/2
	     //printf("%lf\n",mem[i]);
		 }
	 //printf("-------\n");
     if(K<=36)	 
	 ans=expect(N,K,mem);
	 else
	 ans=0;
	 printf("%lf\n",ans);
	 }
 return 0;} 