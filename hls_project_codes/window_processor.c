#define WIDTH 372
#define HEIGHT 286
#include <stdio.h>
const int LL_kernel[2][2] = { {1, 1}, {1, 1} };
const int LH_kernel[2][2] = { {1, -1}, {1, -1} };
const int HL_kernel[2][2] = { {1, 1}, {-1, -1} };
const int HH_kernel[2][2] = { {1, -1}, {-1, 1} };

void window_processor(
    int image[HEIGHT][WIDTH],
    int row_idx,
    int col_idx,
  int *valid_window,
    float *LL,
    float *LH,
    float *HL,
    float *HH)
{

    int window[2][2];
    array_generator(image, valid_window, window, row_idx, col_idx);

    if (*valid_window) {
        int sum_LL = 0, sum_LH = 0, sum_HL = 0, sum_HH = 0;

        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < 2; c++) {
#pragma HLS PIPELINE
                sum_LL += window[r][c] * LL_kernel[r][c];
                sum_LH += window[r][c] * LH_kernel[r][c];
                sum_HL += window[r][c] * HL_kernel[r][c];
                sum_HH += window[r][c] * HH_kernel[r][c];
            }
        }

        *LL = sum_LL * 0.5f;
        *LH = sum_LH * 0.5f;
        *HL = sum_HL * 0.5f;
        *HH = sum_HH * 0.5f;
    } else {
        *LL = 0.0f;
        *LH = 0.0f;
        *HL = 0.0f;
        *HH = 0.0f;
    }
}
