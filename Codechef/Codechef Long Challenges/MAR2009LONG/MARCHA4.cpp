//By Jaskaran.Finding first k digits of N^N and lst k digits
//Includes
#include<iostream>
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include<cassert>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,c,n) for(int i=c;i<n;i++)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

const int p[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
/* This function calculates (a^b)%MOD */
ll power(int a, int b, int MOD)
{ ll x=1,y=a; 
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
ll firstkdig(int N,int K)
{long double a=N*log10l(N);//a=R+f where f is the fractional part
 ll R=floor(a);
 long double f=a-R;//Since n^n=10^a=10^R*10^f 10^R doesn't decide the first k digits.its only 10^f which decides first k digits
 ll ans=floor(pow((long double)10,f+K-1));//as 10^f is a single digit
 return ans;}
 
ll lastkdig(int N,int K)//N^N%(10^K+1)
{
 int MOD=p[K];
 ll ans=power(N,N,MOD);
 return ans;
}
int len(int num)
{int c=0;
if(num==0)
return 1;
while(num!=0)
{num/=10;
 c++;}
 return c;
}
int main()
{int T,N,K;
scanf("%d",&T);
while(T--)
{scanf("%d%d",&N,&K);
 ll ans1=firstkdig(N,K);
 ll ans2=lastkdig(N,K);
 printf("%lld ",ans1);
 int l=len(ans2);//number of digits in ans2.This is to correct output in cases where the number of digits in ans2<K.We have to fix leading zeroes
  rep(i,0,K-l)
  printf("0");
 printf("%lld\n",ans2);
}
return 0;
}