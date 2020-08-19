//
// Created by Kyong Janicke on 17.08.20.
//
#include "mystddef.h"

#ifndef LOWLEVELPROGRAMMING_MYSTRING_H
#define LOWLEVELPROGRAMMING_MYSTRING_H

//function returns length of string input
size_t mystrlen(char *str){
    size_t i=0;
    while (*str!='\0'){
        i++;
        str++;
    }
    return i;

}

//function copies string from src to dest and returns dest address
//Security Problem: If 'dest' has not enough memory allocated, risk of Bufferoverflow
char* mystrcpy(char* dest, const char* src){
    char*tmp=dest;
//my own version (it works), but I found a cool shorter version by the man himself
    /*
    while (*src!='\0'){
        *dest=*src;
        src++;
        dest++;    }
    *dest='\0';

*/
    while ((*dest++=*src++)!='\0'); //source: https://github.com/torvalds/linux/blob/master/lib/string.c
    return tmp;

}

// concatenates src onto dest.
// Example: char src[7]= "lalala";
//          char dest[16]="mimimi";
//          dest[0]=mystrcat(dest, src);
// returns mimimilalala

char *mystrcat(char *dest, const char *src){
    char* tmp=*dest;  
    while (*dest!='\0'){
        dest++;
    }
    while(*src!='\0'){
        *dest=*src;
        dest++;
        src++;
    }
    return tmp;
}


#endif //LOWLEVELPROGRAMMING_MYSTRING_H
