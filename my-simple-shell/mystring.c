//
// Created by Kyong Janicke on 17.08.20.
//
#include <stdio.h> //printf()
#include <string.h> //strlen()
#include "mystddef.h"
#include "mystring.h"

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
char* mystrcpy(char* dest, const char* src){
    char*ptr=dest;
    while (*src!='\0'){
        *dest=*src;
        src++;
        dest++;
    }
    *dest='\0';
    return ptr;
}

