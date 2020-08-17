//
// Created by Kyong Janicke on 17.08.20.
//
#include "mystddef.h"

#ifndef LOWLEVELPROGRAMMING_MYSTRING_H
#define LOWLEVELPROGRAMMING_MYSTRING_H

//function gives back length of string input
size_t mystrlen(char *str){
    size_t i=0;
    while (*str!='\0'){         //strings terminate with /0
            i++;
            str++;
        }
    return i;

}
#endif //LOWLEVELPROGRAMMING_MYSTRING_H
