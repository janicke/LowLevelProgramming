//
// Created by Kyong Janicke on 17.08.20.
//
#include <stdio.h> //printf()
#include <string.h> //strlen()
#include "mystddef.h"
#include "mystring.h"
//Program that returns the length of string, using function mystrlen(char*) defined in mystring.h
int main (int argc, char** argv){
    char string[]= "vier";

    size_t length= mystrlen(string);
    printf ("Die Länge ist: %lu \n",length);
}
