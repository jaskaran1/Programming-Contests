#include<stdio.h>
#include<math.h>
int main()
{int T,N;
int isprime[9997];//contains the bool values for  primes
int primes[9997];//contains only prime numbers
int i,j;
for(i=0;i<9997;i++)
isprime[i]=1;
for(i=2;i<=(int)sqrt(9997);i++)
{if(isprime[i])
{for(j=i;j*i<9997;j++)
 isprime[i*j]=0;}
}//boolean for primes till 9996
j=0;
for(i=3;i<9997;i++)
{if(isprime[i])
 primes[j++]=i;
}
//j contains the total number of primes starting from 3
scanf("%d",&T);
while(T--)
{int nop=0;//number of ordered pairs
scanf("%d",&N);
int p,q;
if(N%2==0)//p has to be 2
{
if((N-2)/2>=2&&isprime[(N-2)/2])
 nop=1;}
else
{for(i=0;i<j;i++)
 {p=primes[i];
  if(isprime[(N-p)/2]&&(N-p)/2>=2)
  nop++;
 }
} 
printf("%d\n",nop); 
}
return 0;
}