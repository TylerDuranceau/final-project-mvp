#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1024
#define HEIGHT 1024

int main() {
    int i, j, x, y;

    // Allocate 2D array (inefficient)
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

    clock_t start = clock();

    // Blur filter (3x3 kernel)
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

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

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