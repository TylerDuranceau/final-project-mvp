# Final Project MVP - Image Blur Optimization

# Final Project MVP - Image Blur Optimization

## Description
This project compares a baseline and optimized blur filter in C. The optimized version improves performance by using contiguous memory and better cache usage.

## Compile
gcc -Wall baseline.c -o baseline
gcc -Wall optimized.c -o optimized

## Run
./baseline
./optimized

## Output
Both programs print execution time for comparison.