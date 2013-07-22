#include <iostream>//to find the path from the source to the destination we use the parent concept
#include<queue>
#include <vector>
#include<utility>
using namespace std;
vector< pair<int,int> > visited;//visited points so as to store them for printing.
queue< pair<int,int> > BFS;
struct point
{int x,y;}
parent[30][30];//stores the parent of the node i,j.-1,-1 if the node doesn't have a parent
char visit[30][30];//to keep a record of the visited vertices.
  			  //w is white,g is grey.no need for black here.could've used 0 or 1 or bool array.
void bfs(int x, int y, int pacman_x, int pacman_y, int food_x, int food_y, vector <string> grid)
{pair<int,int> v;
 pair<int,int> p;
 BFS.push(make_pair(pacman_x,pacman_y));
 while(BFS.empty()==false)//as long as the vertices are white they remain in the queue and a vertex is popped out when its black
 {v=BFS.front();
  if(v.first==food_x&&v.second==food_y)//the point at which BFS has to be terminated
  {  visit[v.first][v.second]='g';
     visited.push_back(v);
	 BFS.pop();
   return;}
  if(visit[v.first][v.second]=='g')//if a queue has grey vertex.pop it out.
  {BFS.pop();
   continue;}
  visit[v.first][v.second]='g';
  visited.push_back(v);
  //now check for neighbours
  if(grid[v.first-1][v.second]!='%'&&v.first>=1&&visit[v.first-1][v.second]=='w')
  {parent[v.first-1][v.second].x=v.first;
   parent[v.first-1][v.second].y=v.second;
   BFS.push(make_pair(v.first-1,v.second));
  }
  if(grid[v.first][v.second-1]!='%'&&v.second>=1&&visit[v.first][v.second-1]=='w')
  {parent[v.first][v.second-1].x=v.first;
   parent[v.first][v.second-1].y=v.second;
   BFS.push(make_pair(v.first,v.second-1));
   }
  if(grid[v.first][v.second+1]!='%'&&v.second+1<=y-1&&visit[v.first][v.second+1]=='w')
  {parent[v.first][v.second+1].x=v.first;
   parent[v.first][v.second+1].y=v.second;
   BFS.push(make_pair(v.first,v.second+1));
  }
  if(grid[v.first+1][v.second]!='%'&&v.first+1<=x-1&&visit[v.first+1][v.second]=='w')
  {parent[v.first+1][v.second].x=v.first;
   parent[v.first+1][v.second].y=v.second;
   BFS.push(make_pair(v.first+1,v.second));
  }
  }
}
/* Tail starts here */
int main(void) {

    int x,y, pacman_x, pacman_y, food_x, food_y;
    
    cin >> pacman_x >> pacman_y;//pacman coordinates
    cin >> food_x >> food_y;//food coordinates
    cin >> x >> y;//rows and columns
    
    vector <string> grid;//grid is a vector of strings

    for(int i=0; i<x; i++) {
        string s; cin >> s;//input row by row
        grid.push_back(s);
    }
    for(int i=0;i<x;i++)
	{for(int j=0;j<y;j++)
	 {visit[i][j]='w';//vertices not visited
	  parent[i][j].x=parent[i][j].y=-1;
	  }//initialised parent value
	}
    bfs( x, y, pacman_x, pacman_y, food_x, food_y, grid);//perform BFS starting from pacman_x,pacman_y
	int count;//number of vertices explored during BFS are all visited nodes
	count=visited.size(); 
	cout<<count<<endl;
	for(int i=0;i<visited.size();i++)	
		cout<<visited[i].first<<" "<<visited[i].second<<endl;
    int d=0;
	vector< pair<int,int> >path;//stores the reverse path ie from the destination to source
	pair <int,int> v;
	v=make_pair(food_x,food_y);
	while(parent[v.first][v.second].x!=-1&&parent[v.first][v.second].y!=-1)
	{pair <int,int> u;
	 u=make_pair(parent[v.first][v.second].x,parent[v.first][v.second].y);
	 path.push_back(u);
	 d++;
	 v=u;}
	cout<<d<<endl;
	for(int i=path.size()-1;i>=0;i--)
			cout<<path[i].first<<" "<<path[i].second<<endl;
	cout<<food_x<<" "<<food_y<<endl;		
    return 0;
}
