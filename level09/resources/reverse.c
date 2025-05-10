#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>
char token[] = "f4kmm6p|=<82>^?p<82>n<83><82>DB<83>Du{^?<8c><89>";


/*
-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~^?<80><81><82><83><84><85><86><87><88><89><8a><8b><8c><8d><8e><8f><90><91><92><93><94><95><96><97><98><99><9a><9b><9c><9d><9e><9f> ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúúûüýþÿ^@^A^B^C^D^E^F^G^H
^K^L^M^N^O^P^Q^R^S^T^U^V^W^X^Y^Z^[^\^]^^^_ !"#$%&'()*+,-./0123456789:;<=>?
*/

/* ~^?<80><81><82><83><84><85><86><87><88><89><8a><8b><8c><8d><8e><8f><90><91><92><93><94><95><96><97><98><99><9a><9b><9c><9d><9e><9f> ¡ */
// f4kmm6p|=<82>^?p<82>n<83><82>DB<83>Du{^?<8c><89>

// Colors
#define RED "\033[31m"// Delete
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"// Hexadecimal
#define END "\033[0m"
int main(void){
    int total_chars = 0;
    for (int i = 0; i < strlen(token); i++){
       if (token[i] == '<'){
            i++;
            int j = 0;
            char hex[3];
            while (token[i] != '>'){
                hex[j++] = token[i++];
            }
            hex[j] = '\0';
            printf( "%c" , (char)strtol(hex, NULL, 16) - total_chars);
            total_chars++;
        }
        else if (token[i] == '^'){
            i++;
            if (token[i] == '?'){
                int character = 127;
                printf( "%c" , character - total_chars);
                total_chars++;
            }
        }
        else{
            printf("%c", token[i] - total_chars);
            total_chars++;
        }
    }
    printf("\n");
    return 0;
}
