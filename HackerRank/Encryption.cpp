//encryption
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{char str[82];
 int r,c;
 cin.getline(str,82);
 int len=strlen(str);
 double root=sqrt(len);
 if(floor(root)==ceil(root))//perfect square
 r=c=root;
 else if(floor(root)*ceil(root)>=len)
 {r=floor(root);
  c=ceil(root);}
 else if(ceil(root)*ceil(root)>=len)
 r=c=ceil(root);
 char arr[r][c];
 for(int i=0;i<r;i++)
 {for(int j=0;j<c;j++)
  arr[i][j]='\0';}
 char *p=str;
 bool flag=0;//this is to terminate both the loops when *p=='\0'
 for(int i=0;i<r;i++)
{for(int j=0;j<c;j++)
 {
  if(*p=='\0')
   {flag=1;
    break;}
  
   arr[i][j]=*p;
   p++;
   }
  if(flag)break;
}
for(int i=0;i<c;i++)
{for(int j=0;j<r;j++)
 {if(arr[j][i]=='\0')
  break;
  printf("%c",arr[j][i]);
 }
 printf(" ");
}
printf("\n");
return 0; 
}
