#include<stdio.h>
int main()
{char s[201];
int alpha[26];
int Alpha[26];
int T;
scanf("%d",&T);
getchar();
while(T--)
{scanf("%s",s);
int i;
for(i=0;i<26;i++)
alpha[i]=Alpha[i]=0;
char *p=s;
for(;*p!='\0';p++)
{if(*p>=97)
 alpha[*p-97]++;
 else
 Alpha[*p-65]++;//capitals
 }
int cost=0;
for(i=0;i<26;i++)
{if(alpha[i]%2==0)
  cost+=alpha[i]/2;
 if(alpha[i]%2==1)
  cost+=alpha[i]/2+1;
 if(Alpha[i]%2==0)
  cost+=Alpha[i]/2;
 if(Alpha[i]%2==1)
  cost+=Alpha[i]/2+1;}
printf("%d\n",cost);  
 }
return 0;}