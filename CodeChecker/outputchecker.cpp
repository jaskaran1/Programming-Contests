//Script to compare 2 files character by character
//To check whether program output is correct or wrong
#include<fstream>
#include<cstdio>
using namespace std;
int main(int argc,char* argv[])
{ifstream in1(argv[1]);//using constructor
 ifstream in2(argv[2]);
 char x,y;
 int c=0;
 while(in1>>x&&in2>>y)//when both the files haven't ended
 {c++;
  if(x!=y)
  {printf("Mismatch at the %d character\n",c);
   return 1;
  }
 }
 printf("Exact match\n");
 return 0;
 }
