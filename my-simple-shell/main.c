//
// Created on my iPhone
// by Kyong Janicke on 21.08.20.
//
// This program gives back all solutions for the famous knight's tour problem.
// https://en.wikipedia.org/wiki/Knight%27s_tour

#include <stdlib.h>
#include <stdio.h>
#include "chessboard.h"

int n = 5;
int start_x = 0;
int start_y = 0;
int solcnt = 0; // solution counter
int moves[8][2] = {{2,1}, {1,2}, {-2,1}, {-1,2}, {2,-1}, {1,-2}, {-2,-1}, {-1,-2}};
struct board_t b;
void knights_tour(struct board_t* b);

int main() {
    if (init_board(&b, n, start_x, start_y) > 0)
        return EXIT_FAILURE;
    knights_tour(&b);
    free_board(&b);
    return EXIT_SUCCESS;
}
void knights_tour(struct board_t* brd) {
    if (visited_fields(brd) >= n*n) {
        printf("Solution %i:\n", ++solcnt);
        print_board(brd);
        printf("\n");
    }
    else {
        int i;
        for (i=0; i<8; i++) {
            if (isfree(brd, moves[i][0], moves[i][1])) {
                new_jump(brd, moves[i][0], moves[i][1]);
                knights_tour(brd);
                remove_jump(brd, moves[i][0], moves[i][1]);
            }
        }
    }
}