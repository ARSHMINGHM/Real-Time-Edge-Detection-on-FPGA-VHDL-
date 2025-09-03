#define WIDTH 372
#define HEIGHT 286
#include <stdio.h>
#include <stdint.h>

void save_pgm(const char *filepath, uint8_t image[HEIGHT - 1][WIDTH - 1]) {
    FILE *f = fopen(filepath, "wb");
    if (!f) {
        perror("Failed to open file");
        return;
    }

    fprintf(f, "P5\n%d %d\n255\n", WIDTH - 1, HEIGHT - 1);

    for (int i = 0; i < HEIGHT - 1; i++) {
        fwrite(image[i], sizeof(uint8_t), WIDTH - 1, f);
    }

    fclose(f);
    printf(" Image saved to: %s\n", filepath);
}

int load_pgm(const char *filepath, int image[HEIGHT][WIDTH]) {
    FILE *f = fopen(filepath, "rb");
    if (!f) {
        perror(" Failed to open input PGM file");
        return -1;
    }

    // Read and ignore PGM header
    char magic[3];
    int maxval, widtht, heightt;

    fscanf(f, "%2s", magic);
    if (magic[0] != 'P' || magic[1] != '5') {
        printf(" Not a P5 PGM file.\n");
        fclose(f);
        return -1;
    }

    fscanf(f, "%d %d", &widtht, &heightt);
    fscanf(f, "%d", &maxval);
    fgetc(f); // consume newline after header


    // Read pixel data
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int pixel = fgetc(f);
            if (pixel == EOF) pixel = 0;
            image[i][j] = pixel;
        }
    }

    fclose(f);
    return 0;
}

int main() {
    int input_image[HEIGHT][WIDTH];
    uint8_t output_image[HEIGHT - 1][WIDTH - 1];
    load_pgm("X:\\pro\\New folder (2)\\outputpgmpython.pgm", input_image);
uint8_t image_copy[HEIGHT - 1][WIDTH - 1];

for (int i = 0; i < HEIGHT - 1; i++) {
    if (i % 512 == 0) {  // Adjust frequency as needed
        printf("Progress: %.2f%%\n", (100.0 * i) / (HEIGHT - 1));
    }
    for (int j = 0; j < WIDTH - 1; j++) {
        int val = input_image[i][j];
        if (val < 0) val = 0;
        if (val > 255) val = 255;
        image_copy[i][j] = (uint8_t)val;
    }
}
    save_pgm("X:\\pro\\New folder (2)\\read_back_check.pgm", image_copy);
    SaveToRamAndOutput(input_image, output_image);
    save_pgm("X:\\pro\\New folder (2)\\output.pgm", output_image);
    printf(" Done writing output image.\n");
    return 0;
}
