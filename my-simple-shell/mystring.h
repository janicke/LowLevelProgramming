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

//compares strings according to lexicographical order. returns 1 if s1>s2; returns -1 if s1>s2; returns 0 if s1==s2
int mystrcmp(const char* s1, const char* s2){
    size_t i=0;
    while (s1[i]!='\0' && s2[i]!='\0'){
        if (s1[i]<s2[i])
            return -1;
        if (s1[i]>s2[i])
            return 1;
        i++;

    }
    if(s1[i]!='\0')
        return -1;
    if (s2[i]!='\0')
        return 1;
    return 0;
}

//function that copies n bytes from src to dest
void *mymemcpy(void *dest, const void *src, size_t n){
    size_t i;
    char* d=dest;
    char* s=src;
    for (i=0;i<=n-1; i++){
        d[i]=s[i];}
    return dest;
}

//function that overwrites n byte from buf with given value
void* mymemset(void* buf, int ch, size_t n){
    char* b=buf;
    while(n--){
        *b++=((char)ch);
    }
    return buf;
}

#endif //LOWLEVELPROGRAMMING_MYSTRING_H
