#include<stdio.h>//my SPOJ solution for STPAR problem
#include<stdlib.h>
#define max 1000
int stack[max];
int top;
void initialize()
{top=-1;}
int push(int x)
{if(top==max-1)
 {printf("Stack Overflow\n");
  return 0;} 
 else
 stack[++top]=x;
 }
int pop()
{if(top==-1)
 {printf("Stack Underflow\n");
 return 0;}
 else
 return stack[top--];
}

int main()
{int n,I,count;
int *road;
while(1)
{scanf("%d",&n);
if(n==0)
break;
int flag=1;
road=(int *)malloc(n*sizeof(int));
 for(I=0;I<n;I++)
  scanf("%d",&road[I]);
 initialize();
 count=1;
 for(I=0;I<n;I++)
  {while(top!=-1&&stack[top]==count)
   {count++;
    pop();}
   if(road[I]==count)
    count++;
   else if(top!=-1&&stack[top]<road[I])
    {flag=0;//false
	 break;}
   else
    {push(road[I]);}
   }
 if(flag==1)  
 printf("yes\n");  
 else
 printf("no\n");
 }
return 0;
}