//FB interview question.Sort an array of 1s,2s,3s(Dutch National Flag problem)
//In this case the invariant is that a[0] to a[low-1] are all 1s.
//a[high+1] to a[size-1] are all 3s
//a[low] to a[high] is unknown
#include<iostream>
#include<cstdio>
using namespace std;
void swap(int &a,int &b)
{int temp=a;
a=b;
b=temp;
}
int main()
{int a[20];
int size,low,high;
scanf("%d",&size);
//So we find out the position of any 1 and  any 3.then swap the 1 to the beginning and 3 to the end.
for(int i=0;i<size;i++)
scanf("%d",&a[i]);
int i;
for(i=0;i<size;i++)
{if(a[i]==1)
 {swap(a[0],a[i]);
  low=1;
  while(a[low]==1)
  low++;//
  break;
 }
 }
//so low points to the first elment from the left not 1.before it all 1s 
for(i=0;i<size;i++)
{if(a[i]==3)
 {swap(a[size-1],a[i]);
  high=size-2;
  while(a[high]==3)
  high--;
  break;}
  }
  //elemnts after high are all 3s
//The invariant has been established at the start ie altleast one 1 is on extreme left and one 3 is on extreme right  
int j;
for(j=low;j<=high;j++)
{if(a[j]==1)
 {swap(a[low],a[j]);
  low++;}
 if(a[j]==3)
 {swap(a[high],a[j]);
  if(a[j]==1)
  {swap(a[low],a[j]);
   low++;
  }
  while(a[high]==3)
  high--;
  } 
}
for(int i=0;i<size;i++)
printf("%d",a[i]);
return 0;
}