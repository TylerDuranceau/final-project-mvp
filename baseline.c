#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 2048
#define HEIGHT 2048
#define RUNS 100

int main() {
    int i, j, x, y;

    // Inefficient 2D allocation
    int** image = malloc(HEIGHT * sizeof(int*));
    int** output = malloc(HEIGHT * sizeof(int*));

    for (i = 0; i < HEIGHT; i++) {
        image[i] = malloc(WIDTH * sizeof(int));
        output[i] = malloc(WIDTH * sizeof(int));
    }

    // Initialize image
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Repeat work
    for (int r = 0; r < RUNS; r++) {
        for (i = 1; i < HEIGHT - 1; i++) {
            for (j = 1; j < WIDTH - 1; j++) {
                int sum = 0;

                for (x = -1; x <= 1; x++) {
                    for (y = -1; y <= 1; y++) {
                        sum += image[i + x][j + y];
                    }
                }

                output[i][j] = sum / 9;
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_spent =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Baseline Time: %f seconds\n", time_spent);

    // Free memory
    for (i = 0; i < HEIGHT; i++) {
        free(image[i]);
        free(output[i]);
    }
    free(image);
    free(output);

    return 0;
}