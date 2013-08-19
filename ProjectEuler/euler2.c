//euler2
#include<stdio.h>
int main()
{
int x,y;
x=1;
y=2;
int temp,sum=2;
while(y<=4000000)
{x=x+y;
 temp=y;
 y=x;
 x=temp;
 if(y%2==0)
 sum+=y;
}
printf("%d",sum);
return 0;
}