#include<stdio.h>//fast NCR calculation
long long int C(int n,int r)
{if(n-r<r)
r=n-r;
if(r==0)
return 1;
int i;
long long int comb=1;
int j=1;
for(i=n;i>=n-r+1;i--)
{comb=(comb*i)/j;
 j++;}
return comb; 
}
int main()
{int t,n,r;
scanf("%d",&t);
while(t--)
{scanf("%d %d",&n,&r);
printf("%lld\n",C(n-1,r-1));}
return 0;}