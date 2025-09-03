#include <stdio.h>

#define WIDTH 372
#define HEIGHT 286


void array_generator(
    int image[HEIGHT][WIDTH],
    int *valid_window,
    int window[2][2],
    int row_idx,
    int col_idx)
{

    *valid_window = 0;

    if (row_idx < HEIGHT - 1 && col_idx < WIDTH - 1) {
        genout: for (int r = 0; r < 2; r++) {
            genin: for (int c = 0; c < 2; c++) {
#pragma HLS PIPELINE
                window[r][c] = image[row_idx + r][col_idx + c];
            }
        }

        *valid_window = 1;
    }
}
