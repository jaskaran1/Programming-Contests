//euler 3
#include<stdio.h>
int main()
{long long int x;
scanf("%lld",&x);
long long int i=2;
while(x!=0&&x!=1)
    {if((x%i)==0)
      {printf("%lld*",i);
       x=x/i;}
     else
       i++;
    }
}