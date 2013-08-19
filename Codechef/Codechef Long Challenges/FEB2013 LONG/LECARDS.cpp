#include<iostream>
#include<cstdio>
using namespace std;
#include<vector>
 
/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD)
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
 
/* 	Modular Multiplicative Inverse
	Using Euler's Theorem
	a^(phi(m)) = 1 (mod m)
	a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
	return pow(n,MOD-2,MOD);
}
 
long long C(int n, int r, int MOD)
{
	vector<long long> f(n + 1,1);
	for (int i=2; i<=n;i++)
		f[i]= (f[i-1]*i) % MOD;
	return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
 
int main()
{ int T;
int N;
int x;
const int prime=1e9+7;
scanf("%d",&T);
while(T--)
{scanf("%d",&N);
 int i;
 for(i=0;i<N;i++)
 scanf("%d",&x);
 long long int ans;
 long long int ans1;
 if(N%2==0)
 {ans=pow(2,N,prime);
  ans1=C(N,N/2,prime);
  ans=ans-ans1;
  ans1=InverseEuler(2,prime);
  ans=(ans*ans1)%prime;}
 else
 ans=pow(2,N-1,prime);
 if(ans<0)
  ans=ans+prime;
 printf("%lld\n",ans);}
	
	return 0;
} 