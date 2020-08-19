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
    char src[7]= "lalala";
    char dest[16]="mimimi";
    dest[0]=mystrcat(dest, src);

    printf ("Das Original ist: %s \nDie Kopie ist: %s ",src,dest);
}