//
// Created by janicke on 16.08.20.
//
//program that returns the input_arguments backwards and mirrored
#include <stdlib.h> //malloc(), free()
#include <stdio.h> //printf()
#include <string.h> //strlen()


char *buffer, *destination;
int main (int argc, char** argv){
    int i,j;
    buffer=malloc(BUFSIZ); //reserves memory
    destination = buffer;       //remember pointer to buffer
    for (i=argc-1;i>0;i--){    //takes arguments last to first, zero argument is name
        for (j=strlen(argv[i])-1;j>=0;j--){ //goes from back to front of argv
            *destination=argv[i][j];
            *destination++;

        }
        *destination++=' ';
    }
    *destination=0;         //terminates with 0
    printf("%s\n", buffer); //give out result
    free(buffer);
}