#include<stdio.h>
#include<string.h>
 
int main(){
    char message[] = "AUTOMATION";
    char key[] = "HELLO";
    int messageLen = strlen(message), key_len = strlen(key), i, j;
 
    char new_key[messageLen], encrypted_message[messageLen], decrypted_message[messageLen];
 
    //generating new key
    for(i = 0, j = 0; i < messageLen; ++i, ++j){
        if(j == key_len)
            j = 0;
 
        new_key[i] = key[j];
    }
 
    new_key[i] = '\0';
 
    //encryption
    for(i = 0; i < messageLen; ++i)
        encrypted_message[i] = (( new_key[i]-message[i] ) % 26) + 'A';
 
    encrypted_message[i] = '\0';
 
    //decryption
    for(i = 0; i < messageLen; ++i)
        decrypted_message[i] = ((( new_key[i]-encrypted_message[i]) + 26) % 26) + 'A';
 
    decrypted_message[i] = '\0';
 
    printf("Original Message: %s", message);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", new_key);
    printf("\nEncrypted Message: %s", encrypted_message);
    printf("\nDecrypted Message: %s", decrypted_message);
 
    return 0;
}