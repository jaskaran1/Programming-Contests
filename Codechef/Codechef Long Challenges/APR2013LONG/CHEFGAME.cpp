//Template
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
#define MOD 747474747
int main()
{int T,N,D;
scanf("%d",&T);
ll points[6667][5];//points are stored in array
ll d[6667];//distance vector stores all the edge wts computed at the frontier
bool disc[6667];
ll **g=new ll*[6667];
rep(i,0,6667)
g[i]=new ll[6667];
while(T--)
{scanf("%d%d",&N,&D);
 ll ans=1;
 rep(i,0,N)
 {d[i]=0;
  disc[i]=0;}
 //graph input taken
 rep(i,0,N)//for the n points
 rep(j,0,D)//for each dimension
 scanf("%lld",&points[i][j]);
 //calculate the distance b/w every point
 rep(i,0,N)
 {rep(j,i,N)
 {ll dist=0;
  rep(k,0,D)
  dist+=(points[i][k]-points[j][k])*(points[i][k]-points[j][k]);
  g[i][j]=g[j][i]=dist;
  }
 }//distance has been calculated
//Prim O(V^2).
int s=0;//start point.This is the point that moves through the graph
disc[s]=1;
rep(i,0,N)
d[i]=g[s][i];
rep(i,0,N-1)//iterating n-1 times since evry time we include  a new vertex in MAXST
{ll max=0;
 int v;
 rep(j,0,N)//iterate through the d[] we find the edge with the maximum weight crossing explored and unexplored and push the vertex v in explored region
{if(!disc[j]&&max<d[j])
 {max=d[j];
  v=j;}
 }
 if(max==0)
 break;
 disc[v]=1;//This is the vertex with the maximum non -zero edge crossing
 ans=((ans%MOD)*(max%MOD))%MOD;  
//update the d[] for unseen vertices surrounding v
rep(j,0,N)
{if(!disc[j]&&d[j]<g[v][j])
 d[j]=g[v][j];
}
}
printf("%lld\n",ans);
 }
rep(i,0,6667)
delete [] g[i];
delete [] g; 
return 0;
}