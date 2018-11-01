#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 1024

void encrypt(char*);
void decrypt(char*);

int menu();

int
main(void)
{

char c,
     choice[2],
     s[MAXSIZE];

 while(1)
 {
 menu();

 gets(choice);

 if(choice[0]=='e')
 {
  puts("Input text to encrypt->");
  gets(s);
  encrypt(s);
 }
 else if(choice[0]=='d')
 {
  puts("Input text ->");
  gets(s);
  decrypt(s);
 }
 else
    break;
 }

 return 0;
}

void encrypt(char*str)
{
	int n=0;
	char *p=str,
		 q[MAXSIZE];

	while(*p)
	{
	 if(islower(*p))
	 {
		 if((*p>='a')&&(*p<'x'))
			 q[n]=toupper(*p + (char)3);
		 else if(*p=='x')
			 q[n]='A';
		 else if(*p=='y')
			 q[n]='B';
		 else
			 q[n]='C';
	 }
	 else
	 {
		 q[n]=*p;
	 }
	 n++; p++;
	}
	q[n++]='\0';
	puts(q);
}

void decrypt(char*str)
{
	int   n=0;
	char *p=str,
		 q[MAXSIZE];

	while(*p)
	{
	 if(isupper(*p))
	 {
		 if((*p>='D')&&(*p<='Z'))
			 q[n]=tolower(*p - (char)3);
		 else if(*p=='A')
			 q[n]='x';
		 else if(*p=='B')
			 q[n]='y';
		 else
			 q[n]='z';
	 }
	 else
	 {
		 q[n]=*p;
	 }
	 n++; p++;
	}
	q[n++]='\0';
	puts(q);
}

int menu()
{
 puts("To encrypt, e \n");
 puts("To decrypt, d \n");
 puts("To exit, any other letter\n");
 puts("Your choice:->\n");
 return 0;
}