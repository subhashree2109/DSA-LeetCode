#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculateArea(int height, int width) {
    return height * width;
}

int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int stackSize = 0;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        int currentHeight = (i == heightsSize) ? 0 : heights[i];

        while (stackSize > 0 && currentHeight < heights[stack[stackSize - 1]]) {
            int poppedIndex = stack[--stackSize];
            int poppedHeight = heights[poppedIndex];
            int width = (stackSize == 0) ? i : i - stack[stackSize - 1] - 1;

            maxArea = fmax(maxArea, calculateArea(poppedHeight, width));
        }
        stack[stackSize++] = i;
    }

    free(stack);
    return maxArea;
}

int main() {
    int heights[] = {2,1,5,6,2,3};
    int n = sizeof(heights) / sizeof(heights[0]);

    printf("Largest Rectangle Area = %d\n", largestRectangleArea(heights, n));
    return 0;
}
