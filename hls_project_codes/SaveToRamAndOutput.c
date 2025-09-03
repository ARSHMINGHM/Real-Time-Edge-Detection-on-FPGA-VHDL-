#include <stdio.h>
#include <stdint.h>

#define WIDTH 372
#define HEIGHT 286

void comparator(
    int image[HEIGHT][WIDTH],
    int row_idx,
    int col_idx,
    int *valid_window,
    uint8_t *combined_lh_hl_hh,
    uint8_t *combined_lh_hl,
    uint8_t *combined_ll_hh,
    uint8_t *norm_HH,
    uint8_t *norm_HL,
    uint8_t *norm_LH,
    uint8_t *norm_LL
);


void SaveToRamAndOutput(int input_image[HEIGHT][WIDTH],uint8_t output_image[HEIGHT - 1][WIDTH - 1]) {

#pragma HLS STREAM variable=input_image dim=2
  uint8_t combined_lh_hl_hh, combined_lh_hl, combined_ll_hh;
    uint8_t norm_HH, norm_HL, norm_LH, norm_LL;
    for (int i = 0; i < HEIGHT - 1; i++) {
        for (int j = 0; j < WIDTH - 1; j++) {
#pragma HLS PIPELINE
      int valid = 0;
            comparator(
                input_image,
                i,
                j,
                &valid,
                &combined_lh_hl_hh,
                &combined_lh_hl,
                &combined_ll_hh,
                &norm_HH,
                &norm_HL,
                &norm_LH,
                &norm_LL
            );

            output_image[i][j] = combined_lh_hl_hh;
        }
    }
}
