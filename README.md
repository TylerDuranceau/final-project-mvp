# Final Project MVP - Image Blur Optimization

## Description
This project compares a baseline and optimized implementation of a blur filter in C. The optimization improves cache performance using contiguous memory.

## Compile
gcc -Wall baseline.c -o baseline
gcc -Wall optimized.c -o optimized

## Run
./baseline
./optimized

## Output
Both programs print execution time for comparison.