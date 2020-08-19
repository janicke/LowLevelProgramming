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
    char a[7]= "aaa";
    char b[7]="bbb";
    int i=mystrcmp(a,b);
    mymemcpy(a,b,2);

    printf ("Das Original ist: %d\n%s\n%s", i,a,b);
}