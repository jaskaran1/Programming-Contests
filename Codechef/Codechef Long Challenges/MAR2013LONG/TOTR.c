#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{int T;
char byte[26];//byte[i] contains english equivalent of byte letters abcdefghijklmnopqrstuvwxyz
char bytestr[101];
scanf("%d",&T);
getchar();
int j;
for(j=0;j<26;j++)
scanf("%c",&byte[j]);
getchar();
while(T--)
{gets(bytestr);
int c=strlen(bytestr);
int i;
for(i=0;i<c;i++)
{	if(isupper(bytestr[i]))
	{char ch=tolower(bytestr[i]);
	 ch=byte[ch-'a'];
	 printf("%c",toupper(ch));
	}
	else if(bytestr[i]=='_')
	printf(" ");
	else if(islower(bytestr[i]))
	{char ch=byte[bytestr[i]-'a'];
	 printf("%c",ch);}
	else
	printf("%c",bytestr[i]);
	}
printf("\n");	
}
return 0;}