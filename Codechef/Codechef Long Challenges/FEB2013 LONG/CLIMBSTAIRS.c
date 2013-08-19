#include<stdio.h>
#include<stdlib.h>
void bin_conv(int d,int G)
{int b[50];
 int r,j=0; 
 while(d!=0)  /*we can write sum=0,a=1;
                       while(d!=0)
                          {sum=sum+a*(d%2);;
                          d=d/2;
                          a*=10}
                          return sum*/ 
   {b[j]=d%2;
    d=d/2;
    j++;}
 j--;//This is because in the last iteration of while loop j is incremented by one but then b[j] isn't assigned a value
 int c=0;
 while(j>=0)
   {if(b[j]==1)
     c++;
	 j--;}
if(c==G)
printf("CORRECT\n");
else
printf("INCORRECT\n");}
int main()
{int prime=1000000007;
int *mem=(int *)malloc(1000001*sizeof(int));
mem[1]=1;
mem[2]=2;
int i;
for(i=3;i<1000001;i++)
{mem[i]=(mem[i-1]%prime+mem[i-2]%prime)%prime;//preprocessing done
}
int T,N,G;
scanf("%d",&T);
while(T--)
{scanf("%d %d",&N,&G);
bin_conv(mem[N],G);}
return 0;
}