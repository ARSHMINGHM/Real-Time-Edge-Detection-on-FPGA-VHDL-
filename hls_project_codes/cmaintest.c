#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_SIZE 64
#define BLOCK_SIZE 8

typedef unsigned char pixel_t;
typedef float coeff_t;

// --- DWT functions (reuse from above) ---
void dwt_1d(const pixel_t *in, coeff_t *out_low, coeff_t *out_high, int length);
void dwt_2d(pixel_t in[BLOCK_SIZE][BLOCK_SIZE],
            coeff_t out_LL[BLOCK_SIZE/2][BLOCK_SIZE/2],
            coeff_t out_LH[BLOCK_SIZE/2][BLOCK_SIZE/2],
            coeff_t out_HL[BLOCK_SIZE/2][BLOCK_SIZE/2],
            coeff_t out_HH[BLOCK_SIZE/2][BLOCK_SIZE/2]);

// --- Simple PGM loader ---
int read_pgm(const char* filename, pixel_t image[IMG_SIZE][IMG_SIZE]) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    char line[128];
    // Read magic number
    if (!fgets(line, sizeof(line), f)) { fclose(f); return 0; }
    if (strncmp(line, "P5", 2) != 0) { fclose(f); return 0; }

    // Skip comments
    do {
        if (!fgets(line, sizeof(line), f)) { fclose(f); return 0; }
    } while (line[0] == '#');

    // Read width and height
    int width, height;
    sscanf(line, "%d %d", &width, &height);
    if (width != IMG_SIZE || height != IMG_SIZE) {
        printf("Image size mismatch (expected %dx%d)\n", IMG_SIZE, IMG_SIZE);
        fclose(f);
        return 0;
    }

    // Read max grayscale value (usually 255)
    if (!fgets(line, sizeof(line), f)) { fclose(f); return 0; }

    // Read pixel data
    size_t read = fread(image, sizeof(pixel_t), IMG_SIZE * IMG_SIZE, f);
    fclose(f);
    if (read != IMG_SIZE * IMG_SIZE) {
        printf("Failed to read image data\n");
        return 0;
    }
    return 1;
}

// --- Simple PGM writer ---
int write_pgm(const char* filename, coeff_t image[IMG_SIZE][IMG_SIZE]) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        printf("Error opening file %s for writing\n", filename);
        return 0;
    }

    fprintf(f, "P5\n%d %d\n255\n", IMG_SIZE, IMG_SIZE);

    // Normalize float image to 0..255 and write as unsigned char
    unsigned char buffer[IMG_SIZE * IMG_SIZE];
    float min = image[0][0], max = image[0][0];

    // Find min and max for normalization
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            if (image[i][j] < min) min = image[i][j];
            if (image[i][j] > max) max = image[i][j];
        }
    }

    float range = max - min;
    if (range == 0) range = 1.0f; // avoid division by zero

    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            float val = (image[i][j] - min) / range; // normalize 0..1
            int c = (int)(val * 255.0f);
            if (c < 0) c = 0;
            if (c > 255) c = 255;
            buffer[i * IMG_SIZE + j] = (unsigned char)c;
        }
    }

    fwrite(buffer, sizeof(unsigned char), IMG_SIZE * IMG_SIZE, f);
    fclose(f);
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input.pgm output.pgm\n", argv[0]);
        return 1;
    }

    pixel_t image[IMG_SIZE][IMG_SIZE];
    coeff_t output[IMG_SIZE][IMG_SIZE] = {0};

    if (!read_pgm(argv[1], image)) {
        printf("Failed to read input image\n");
        return 1;
    }

    // Process image block by block
    for (int row = 0; row < IMG_SIZE; row += BLOCK_SIZE) {
        for (int col = 0; col < IMG_SIZE; col += BLOCK_SIZE) {
            pixel_t block[BLOCK_SIZE][BLOCK_SIZE];
            coeff_t out_LL[BLOCK_SIZE/2][BLOCK_SIZE/2];
            coeff_t out_LH[BLOCK_SIZE/2][BLOCK_SIZE/2];
            coeff_t out_HL[BLOCK_SIZE/2][BLOCK_SIZE/2];
            coeff_t out_HH[BLOCK_SIZE/2][BLOCK_SIZE/2];

            for (int i = 0; i < BLOCK_SIZE; i++) {
                for (int j = 0; j < BLOCK_SIZE; j++) {
                    block[i][j] = image[row + i][col + j];
                }
            }

            dwt_2d(block, out_LL, out_LH, out_HL, out_HH);

            // Here, just write LL band back into output image
            for (int i = 0; i < BLOCK_SIZE/2; i++) {
                for (int j = 0; j < BLOCK_SIZE/2; j++) {
                    output[row + i][col + j] = out_LL[i][j];
                }
            }
        }
    }

    if (!write_pgm(argv[2], output)) {
        printf("Failed to write output image\n");
        return 1;
    }

    printf("DWT done. Output saved to %s\n", argv[2]);
    return 0;
}
