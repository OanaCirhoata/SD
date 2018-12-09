#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define VAL(PTR) (*PTR)

typedef char* STRING;
typedef char** STRING_REF;

void encrypt_decrypt(STRING_REF str, char key, int encrypt){
	int strLength, itr_str, nextKey,currentKey, remainder;
	strLength = strlen(VAL(str));
	for(itr_str = 0 ; itr_str < strLength ; ++itr_str){
		if(isalpha(VAL(str)[itr_str])){
			VAL(str)[itr_str] = toupper(VAL(str)[itr_str]);
		}
	}
	nextKey = toupper(key)-'A';
	for(itr_str = 0 ; itr_str < strLength ; ++itr_str){
		if(isalpha(VAL(str)[itr_str])){
			currentKey = nextKey;
			if(encrypt){
				nextKey = VAL(str)[itr_str]-'A';
				VAL(str)[itr_str] = (VAL(str)[itr_str]-'A'+currentKey)%26+'A';
			}
			else{
				remainder = (VAL(str)[itr_str]-'A'-currentKey)%26+'A';
				VAL(str)[itr_str] = remainder < 'A' ? remainder + 26 : remainder ;
				nextKey = VAL(str)[itr_str]-'A';
			}
		}
	}
}

void flush_stdin()
{
	while(fgetc(stdin) != '\n');
}

int main(int argc, char **argv)
{
	int length;
	char key;
	char *str;
	printf("Key used for encryption: ");
	scanf("%c",&key);
	printf("Enter the length of the string: ");
	scanf("%d",&length);
	str = (char*)malloc((length+1)*sizeof(char));
	flush_stdin();
	printf("String you want to encrypt: ");
	fgets(str,length+1,stdin);
	flush_stdin();
	encrypt_decrypt(&str,key,1);
	printf("\nText after encrypting: %s",str);
    encrypt_decrypt(&str,key,0);
	printf("\nAfter decrypting the same encrypted text: %s",str);
	printf("\n");
	free(str);
	return 0;
}