#include <stdio.h>
#include <stdint.h>

#define WIDTH 372
#define HEIGHT 286
#define ABS_LIMIT 255.0f
#define MIN_STRENGTH 30.0f

uint8_t edge_map_single_value(float val, float abs_limit, float min_strength) {
	float v = (val < 0) ? -val : val;
    if (v > abs_limit) v = abs_limit;
    float norm = (v / abs_limit) * 255.0f;
    return (norm >= min_strength) ? 255 : 0;
}
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
	  ){

	float LL_val, LH_val, HL_val, HH_val;
	 window_processor(image, row_idx, col_idx, valid_window, &LL_val, &LH_val, &HL_val, &HH_val);
	 *norm_LL = edge_map_single_value(LL_val,510.0f,40.0f);
	 *norm_LH = edge_map_single_value(LH_val,ABS_LIMIT,MIN_STRENGTH);
	 *norm_HL = edge_map_single_value(HL_val,ABS_LIMIT,MIN_STRENGTH);
	 *norm_HH = edge_map_single_value(HH_val,ABS_LIMIT,MIN_STRENGTH);
	 float f_norm_LL = (float)(*norm_LL);
	 float f_norm_LH = (float)(*norm_LH);
	 float f_norm_HL = (float)(*norm_HL);
	 float f_norm_HH = (float)(*norm_HH);

	 float norm_ll_hh = (f_norm_LL + f_norm_HH);
	 float norm_lh_hl = (f_norm_LH + f_norm_HL);
	 float norm_lh_hl_hh = (f_norm_HH + f_norm_LH + f_norm_HL);

	 *combined_ll_hh = (norm_ll_hh > 255.0f) ? 255 : (uint8_t)norm_ll_hh;
	 *combined_lh_hl = (norm_lh_hl > 255.0f) ? 255 : (uint8_t)norm_lh_hl;
	 *combined_lh_hl_hh = (norm_lh_hl_hh > 255.0f) ? 255 : (uint8_t)norm_lh_hl_hh;


}
