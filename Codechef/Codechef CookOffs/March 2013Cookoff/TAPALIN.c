#include<stdio.h>
#include<stdlib.h>
int p=1e9+7;
long long power(long long int a,long long  int b,long long int MOD)
{
	long long x=1,y=a; 
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD; 
		b /= 2;
	}
	return x;
}
long long InverseEuler(int n, int MOD)
{
	return power(n,MOD-2,MOD);
}
int main()
{
int T,N;
scanf("%d",&T);
long long int ans; 
while(T--)
{scanf("%d",&N);
 if(N%2==0)
 ans=((((power(26,N/2,p)-1)*52)%p)*InverseEuler(25,p))%p;
 else
 ans=(power(26,(N+1)/2,p)+(52*(((power(26,(N-1)/2,p)-1)*InverseEuler(25,p))%p))%p)%p;
 printf("%lld\n",ans);
 }
return 0;
}