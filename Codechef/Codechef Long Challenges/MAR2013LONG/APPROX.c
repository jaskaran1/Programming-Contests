#include<stdio.h>
int main()
{char str[52]="415926530119026040722614947737296840070086399613316";
int T;
scanf("%d",&T);
while(T--)
{int k;
 scanf("%d",&k);
 if(k==0)
    printf("3");
 else if(k==1)
    printf("3.1");
 else if(k<=52)
	{k=k-2;
	 printf("3.1");
	 int i;
	 for(i=0;i<=k;i++)
	 printf("%c",str[i]);}
 else
	{k=k-1;
     printf("3.1");
	 int s=k/51;
	 int i;
	 for(i=1;i<=s;i++)//print the entire array s times
		{int j;
	     for(j=0;j<=50;j++)
		 printf("%c",str[j]);
		 }
		int r=k%51;//the remaining elements to be printed
	 for(i=0;i<r;i++)
		 printf("%c",str[i]);
	 }
 printf("\n");} 
return 0;
}