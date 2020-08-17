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
    char string[]= "vier";

    size_t length= mystrlen(string);
    printf ("Die Länge ist: %lu \n",length);
}