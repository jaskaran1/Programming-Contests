#include <stdio.h>
#include <string.h>
#include <math.h>
/* Head ends here */
void nextMove(int n, int x, int y, char grid[101][101]){
    int i,j,f=0;
    for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
     {if(grid[i][j]=='p')
     {f=1;
      break;}
     }
    if(f==1)
        break;
    }
   if(i==x)//same row
   {if(j<y)
    printf("LEFT\n");
    else
    printf("RIGHT\n");
    return;}
   if(j==y)
    {if(i<x)
     printf("UP\n");
     else
     printf("DOWN\n");
     return;
    }
   if(j<y)
       printf("LEFT\n");
   else
       printf("RIGHT\n");
}
/* Tail starts here */
int main(void) {

    int n, x, y;

    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &y);

   char grid[101][101];
    
    for(int i=0; i<n; i++) {
        scanf("%s[^\n]%*c", grid[i]);
    }

    nextMove(n, x, y, grid);
    return 0;
}
