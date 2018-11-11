#include <stdio.h>
#include <string.h>
 
int main()
{
   char string[100];
   int c = 0, count[26] = {0}, y;
 
   printf("Enter a string\n");
   gets(string);
 
   while (string[c] != '\0') {
  
 
      if (string[c] >= 'a' && string[c] <= 'z') {
         y = string[c] - 'a';
         count[y]++;
      }
 
      c++;
   }
 
   for (c = 0; c < 26; c++)
         printf("%c occurs %d times in the string.\n", c + 'a', count[c]);
 
   return 0;
}