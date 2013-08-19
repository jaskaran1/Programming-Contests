//euler 1
#include<stdio.h>
int main()
{int sum3,sum5,sum15;
sum3=sum5=sum15=0;
int i;
int sum;
for(i=1;i<1000;i++)
{if(i%3==0)
 sum3+=i;
 if(i%5==0)
 sum5+=i;
 if(i%15==0)
 sum15+=i;
}
sum=sum3+sum5-sum15;
printf("%d",sum);
}