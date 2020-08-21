//
// Created on my iPhone
// by Kyong Janicke on 21.08.20.
//

#ifndef LOWLEVELPROGRAMMING_CHESSBOARD_H
#define LOWLEVELPROGRAMMING_CHESSBOARD_H
#include <stdlib.h>
#include <stdio.h>
//struct defines chessfield of size nxn, and startpos of knight
struct board_t {
    int startpos_x, startpos_y, size;
    int **fields;
};
//initializes chessboard by allocating memory for the fields
int init_board (struct board_t *b, int n, int x, int y){
    b->size=n;
    b->startpos_x=x;
    b->startpos_y=y;
    //initialization of board
    int i,j;
    b->fields=((int**)malloc(n*sizeof(int*)));
    for(i=0;i<=n-1;i++)
        b->fields[i]=(int*)malloc(sizeof(int));
    //setting fields to 0
    for(i=0; i<=n-1;i++){
        for(j=0;j<=n-1;j++){
            b->fields[i][j]=0;
        }
    }
    //setting knight to poisiton x,y
    b->fields[x][y]=1;
    return 0;
}

//frees allocated memory of the chessboard
void free_board (struct board_t *b){
    int i;
    for (i=0; i<b->size; i++){
        free(b->fields[i]);
    }
    free(b->fields);
}

//moves knight (x and y) and marks new position of knight
void new_jump(struct board_t* b, int x, int y){
    //save current jump-number
    int num =b->fields[b->startpos_x][b->startpos_y];
    //if jump is outside of board
    if (x>b->size||y>b->size) {
        printf("Error: Outside Chessboard");
        return;
    }
    //set new position of knight
    b->startpos_x+=x;
    b->startpos_y+=y;
    //save new jump number in field-matrix
    b->fields[b->startpos_x][b->startpos_y]=num+1;
}

//removes jump and jump-number
void remove_jump(struct board_t* b, int x, int y){
    b->fields[b->startpos_x][b->startpos_y]=0;
    b->startpos_x-=x;
    b->startpos_y-=y;
}

//returns isfree= true (1) / false (0)  for intended jump (x,y)
int isfree(struct board_t* b, int x, int y){
    if (b->startpos_x + x < b->size && b->startpos_x + x>=0){
        if(b->startpos_y + y < b->size && b->startpos_y + y >= 0){
            if(b->fields[b->startpos_x+x][b->startpos_y + y] == 0)
                return 1;
        }
    }
    return 0;
}

//returns number of visited fields
int visited_fields (struct board_t* b){
    int visited=0;
    int x,y;
    for (x=0;x<b->size;x++){
        for (y=0;y<b->size;y++){
            if (b->fields[x][y])
                visited++;
        }
    }
    return visited;
}

//prints chessboard, with numerated number of fields
void print_board(struct board_t* b){
    int i,j;

    for(i=0; i<b->size; i++){
        printf("+");
        for(j=0; j<b->size; j++)
            printf("---+");
        printf("\n+");
        for(j=0; j<b->size; j++)
            printf("%3i+", b->fields[i][j]);
        printf("\n");
    }
    printf("+");
    for(j=0; j<b->size; j++)
        printf("---+");
    printf("\n\n");
}


#endif //LOWLEVELPROGRAMMING_CHESSBOARD_H
