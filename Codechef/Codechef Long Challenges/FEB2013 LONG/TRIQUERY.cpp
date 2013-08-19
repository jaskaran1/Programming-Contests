#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<cassert>

using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))

#define MP make_pair
#define pb push_back
#define inf 1000000000

#define maxq 200000
#define maxn 300000

#define TX 0
#define TY 1

int tree[2][maxn+1];//2 Binary indexed Trees

int read(int idx,int x)//it reads the cumulative frequency[idx] in O(log(maxn)) ie the number of points having their Xcoordinate <=idx when x=0
{						//and the number of points having their Ycoordinate<=idx(the y coordinate which is given as the parameter) when x=1
	int sum = 0;
	while (idx > 0) sum =(sum+tree[x][idx]) , idx -= (idx & -idx);
	return sum;
}

void update(int idx,int val,int x)//updates the BIT in O(log(maxn)) by updating the cumulative frequencies 
{
	while (idx <= maxn) tree[x][idx]=(tree[x][idx]+val),idx += (idx & -idx);
}

struct pt
{
	int x,y;
};

struct query
{
	int x,y,d,id;
};


pt pts[maxn];
query qs[maxq];
int ans[maxq];

int comp_pt(pt A,pt B) // For sorting points by their diagonal
{
	return A.x+A.y<B.x+B.y;
}

int comp_pt_byx(pt A,pt B) // For sorting points by x
{
	if(A.x==B.x) return A.y<B.y;
	return A.x<B.x;
}

int comp_query(query A,query B) // For sorting queries by the diagonal
{
	return A.x+A.y+A.d<B.x+B.y+B.d;
}

int comp_query_byx(query A,query B) //For sorting queries by x
{
	if(A.x==B.x) return A.y<B.y;
	return A.x<B.x;
}


int main()
{
	int i,j,k,tests,cs=0,n,q;
	
	scanf("%d%d",&n,&q);
	assert(n>=1 && n<=maxn);
	assert(q>=1 && q<=maxq);

	for(i=0;i<n;i++)
	{
		scanf("%d%d",&pts[i].x,&pts[i].y);
		assert(1<=pts[i].x && pts[i].x<=maxn);
		assert(1<=pts[i].y && pts[i].y<=maxn);
	}

	
	for(i=0;i<q;i++)
	{
		scanf("%d%d%d",&qs[i].x,&qs[i].y,&qs[i].d);
		assert(1<=qs[i].x && qs[i].x<=maxn);
		assert(1<=qs[i].y && qs[i].y<=maxn);
		assert(1<=qs[i].d && qs[i].d<=maxn);
		qs[i].id=i;
	}

	sort(pts,pts+n, comp_pt);//sorting pts by diagonal
	sort(qs, qs+q, comp_query);//sorting queries by diagonal


	for(j=i=0;i<q;i++)//going through all the queries in sorted order by diagonal
	{
		for(;j<n;j++)//j is the number of points which have been seen.j moves from 0 to n.Remember there is just a single pass over all points
		{
			if(pts[j].x+pts[j].y>qs[i].x+qs[i].y+qs[i].d) break;//the case when the point is ahead of the diagonal sweep line.then we break the loop as we have gone through all points below the hypotenuese
			update(pts[j].x,+1,TX);
			update(pts[j].y,+1,TY);
		}
		ans[qs[i].id] = j - read(qs[i].x-1,TX) - read(qs[i].y-1,TY);//for the ith query the number of points seen is j.since the number of points in the triangle x y d is
		//j-(all points having X<x)-(all points having Y<y)+(all points having X<x&Y<y)
	}

	MEM(tree,0);
	sort(pts,pts+n,comp_pt_byx);//resorting the points by x coordinate
	sort(qs,qs+q,comp_query_byx);//resorting the queries by y coordinate

	for(j=i=0;i<q;i++)
	{
		for(;j<n;j++)//this will just work once ie for the first triangle with the lowest y.The sweepline x=c moves from left to right and updates the frequency of all the y coordinate points
		{
			if(pts[j].x >= qs[i].x) break;
			update(pts[j].y,+1,TY);
		}//after this loop we have the number of points having Y<=y and X<=x

		ans[qs[i].id] += read(qs[i].y-1,TY); 
	}

	for(i=0;i<q;i++)
		printf("%d\n",ans[i]);

	return 0;
} 