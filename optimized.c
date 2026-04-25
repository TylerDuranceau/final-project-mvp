#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1024
#define HEIGHT 1024

int main() {
    int i, j, x, y;

    // Single contiguous allocation (optimized)
    int* image = malloc(WIDTH * HEIGHT * sizeof(int));
    int* output = malloc(WIDTH * HEIGHT * sizeof(int));

    // Initialize
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i * WIDTH + j] = rand() % 256;
        }
    }

    clock_t start = clock();

    // Blur filter
    for (i = 1; i < HEIGHT - 1; i++) {
        for (j = 1; j < WIDTH - 1; j++) {
            int sum = 0;
            for (x = -1; x <= 1; x++) {
                for (y = -1; y <= 1; y++) {
                    sum += image[(i + x) * WIDTH + (j + y)];
                }
            }
            output[i * WIDTH + j] = sum / 9;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Optimized Time: %f seconds\n", time_spent);

    free(image);
    free(output);

    return 0;
}