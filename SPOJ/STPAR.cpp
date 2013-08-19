#include<iostream>//SPOJ solution of STPAR or railroad problem using STL
#include<stack>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{int n,I;
int *road;
while(1)
{scanf("%d",&n);
if(n==0)
break;
road=(int *)malloc(n*sizeof(int));
for(I=0;I<n;I++)
scanf("%d",&road[I]);
stack<int> lane; int need = 1;
bool state = true;
for (I = 0; I<n; I++) {
	while (!lane.empty() && lane.top() == need) {
		need++;
		lane.pop();
	}
	if (road[I] == need) {
		need++;
	} else if (!lane.empty() && lane.top() <road[I]) {
		state = false;
		break;
	} else {
		lane.push(road[I]);
	}
}
if (state) cout << "yes" << "\n";
else cout << "no" << "\n"; }
return 0;
}