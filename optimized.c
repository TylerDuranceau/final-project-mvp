#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 2048
#define HEIGHT 2048
#define RUNS 100

int main() {
    int i, j;

    // Contiguous allocation
    int* image = malloc(WIDTH * HEIGHT * sizeof(int));
    int* output = malloc(WIDTH * HEIGHT * sizeof(int));

    // Initialize
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i * WIDTH + j] = rand() % 256;
        }
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Repeat work
    for (int r = 0; r < RUNS; r++) {
        for (i = 1; i < HEIGHT - 1; i++) {
            int base = i * WIDTH;

            for (j = 1; j < WIDTH - 1; j++) {
                int idx = base + j;

                int sum = 0;

                sum += image[idx];
                sum += image[idx - 1];
                sum += image[idx + 1];
                sum += image[idx - WIDTH];
                sum += image[idx + WIDTH];
                sum += image[idx - WIDTH - 1];
                sum += image[idx - WIDTH + 1];
                sum += image[idx + WIDTH - 1];
                sum += image[idx + WIDTH + 1];

                output[idx] = sum / 9;
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_spent =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Optimized Time: %f seconds\n", time_spent);

    free(image);
    free(output);

    return 0;
}