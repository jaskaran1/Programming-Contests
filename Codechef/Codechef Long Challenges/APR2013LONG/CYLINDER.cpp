//By Jaskaran
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
#define rep(i,n) for(int i=0;i<n;i++)
const double PI=acos(-1.);
//Maximize PI*R^2*A
double maxV(double W,double H)//considering the cut is made parallel to W to get WxX and Wx(H-x)
{//CaseI when A=H-X
double D=min(W/PI,2*H/3);
double V=PI/4*D*D*(H-D);
//CaseII when A=W
//Case a)Horizontal circle case
if(H>=W*(2+PI))//then D=W
{if(V<PI/4*W*W*W)
 V=PI/4*W*W*W;
}
//Case b)Vertical circle case.D=H/(PI+1)
else if(H<=W/2*(PI+1))
{if(V<PI/4*(H/(PI+1))*(H/(PI+1))*W)
 V=PI/4*(H/(PI+1))*(H/(PI+1))*W;
}
//Case c)Circles touch each other and are in a slanting position
else
{double Hp=H/(PI+1);
 double Wp=W/((PI+1)*(PI+1));
 D=Hp+Wp-sqrt(Wp*(Wp+2*Hp-W));
 if(V<PI/4*D*D*W)
 V=PI/4*D*D*W;
}
return V;
}
int main()
{int T,W,H;
scanf("%d",&T);
while(T--)
{scanf("%d%d",&W,&H);
 double ans=max(maxV(W,H),maxV(H,W));//12 dig mantissa
 printf("%.11e\n",ans);
}
return 0;}