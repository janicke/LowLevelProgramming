//
// Created by Kyong Janicke on 16.08.20.
//
//program that returns the input_arguments backwards and mirrored
#include <stdlib.h> //malloc(), free()
#include <stdio.h> //printf()
#include <string.h> //strlen()
#include "mystddef.h"
#include "mystring.h"

int main (int argc, char** argv){
    char a[7]="aaaaaa";
    char b[7]="bbbbbb";
    int i=mystrcmp(a,b);
    char *buf=&a[2];
    mymemcpy(a,b,2);
    mymemset(buf,'0',2);
    printf ("Das Original ist: %d\n%s\n%s\n", i,a,b);
}