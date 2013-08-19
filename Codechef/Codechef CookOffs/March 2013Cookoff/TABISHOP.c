#include<stdio.h>
typedef struct point
{int x;
int y;
int LU,RU,LD,RD;
}point;
point bish[100000];

int main()
{int N,K,M;
scanf("%d %d %d",&N,&K,&M);
int i;
int u,v;
int safe=0;
for(i=0;i<K;i++)
{scanf("%d %d",&bish[i].x,&bish[i].y);
int a=bish[i].x;int b=bish[i].y;

}
for(i=0;i<M;i++)
{scanf("%d %d",&u,&v);
int j;
 for(j=0;j<K;j++)
 {int a=bish[j].x;
  int b=bish[j].y;
  if((u-a==v-b||u-a==b-v)&&u-a>0)
  safe+=(u-a-1);
  else if((a-u==v-b||a-u==b-v)&&a-u>0)
  safe+=(a-u-1);
 }
}
safe=safe+K;
printf("%d\n",safe);
return 0;
}