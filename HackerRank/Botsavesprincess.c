#include <stdio.h>
#include <string.h>
#include <math.h>
/* Head ends here */
void displayPathtoPrincess(int n, char grid[n][n]){
int i;
    if(grid[0][0]=='p')
    {for(i=1;i<=(n-1)/2;i++)
       printf("LEFT\n");
     for(i=1;i<=(n-1)/2;i++)
       printf("UP\n");}
    else if(grid[0][n-1]=='p')
    {for(i=1;i<=(n-1)/2;i++)
        printf("RIGHT\n");
     for(i=1;i<=(n-1)/2;i++)
       printf("UP\n");
    }
    else if(grid[n-1][0]=='p')
    {for(i=1;i<=(n-1)/2;i++)
        printf("LEFT\n");
     for(i=1;i<=(n-1)/2;i++)
         printf("DOWN\n");
    }
    else if(grid[n-1][n-1]=='p')
    {for(i=1;i<=(n-1)/2;i++)
      printf("RIGHT\n");
     for(i=1;i<=(n-1)/2;i++)
      printf("DOWN\n");}
}
/* Tail starts here */
int main(void) {

    int m;
    scanf("%d", &m);
    char grid[m][m];
    char line[m];

    for(int i=0; i<m; i++) {
        scanf("%s", line);
        strncpy(grid[i], line, m);
    }
    displayPathtoPrincess(m,grid);
    return 0;
}
