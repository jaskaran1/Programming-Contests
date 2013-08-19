//By Jaskaran
//Includes
#include<iostream>
#include <vector> 
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
#include <cstdio>
#include <cmath>//for floor,pow,log10l(),log10(),log(),abs()
#include <cstdlib>
#include <ctime>
#include <cstring>
#include<cassert>//for assert
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define pb push_back
#define rep(i,c,n) for(long long i=c;i<n;i++)
struct balance{
ll ltwt;//left weight
ll rtwt;//right weight
vector<ll> lb;//vector for the balances on the left
vector<ll> rb;//vector for the balances on the right
};
ll foo(ll root,balance bal[],ll ans[][2])//returns the total weight after balancing
{ll wt=10;
 if(bal[root].lb.size()==0&&bal[root].rb.size()==0)
 {ll diff=bal[root].ltwt-bal[root].rtwt;//left weight-right weight
  if(diff>0)
  {ans[root][1]=diff;
   wt+=2*bal[root].ltwt;}
  if(diff<0)
  {ans[root][0]=-diff;
   wt+=2*bal[root].rtwt;}
  }
 else
 {ll lt=0,rt=0;
  rep(i,0,bal[root].lb.size())
	lt+=foo(bal[root].lb[i],bal,ans);
	 
  rep(i,0,bal[root].rb.size())
	rt+=foo(bal[root].rb[i],bal,ans);
	 
  ll diff=(bal[root].ltwt-bal[root].rtwt)+(lt-rt);//the difference of weights between left and right side
  if(diff>0)//when left side is greater
  {ans[root][1]=diff;
   wt+=2*(bal[root].ltwt+lt);}
  if(diff<0)
  {ans[root][0]=-diff;
   wt+=2*(bal[root].rtwt+rt);}
  }
  return wt;
 }

int main()
{ll N;//number of balances
scanf("%lld",&N);
balance bal[N];
vector< vector<ll> >tree(N);
rep(i,0,N)
{//Left
 scanf("%lld",&bal[i].ltwt);
 char c=getchar();
 ll n;
 while(c!='\n')
 {scanf("%lld",&n);
  bal[i].lb.pb(n);
  tree[n].pb(i);//n has its root as i
  c=getchar();}
 //Right
 scanf("%lld",&bal[i].rtwt);
 c=getchar();
 while(c!='\n')
 {scanf("%lld",&n);
  bal[i].rb.pb(n);
  tree[n].pb(i);
  c=getchar();
 } 
 }
//Input complete  
ll root;
ll ans[N][2];
rep(k,0,N)
rep(l,0,2)
ans[k][l]=0;
  
rep(i,0,N)
{if(tree[i].size()==0)
 {root=i;
  foo(root,bal,ans);
   }
  } 
//the root computed on which recursion has to be performed
rep(i,0,N)
 printf("%lld: %lld %lld\n",i,ans[i][0],ans[i][1]);
  
return 0;
 } 