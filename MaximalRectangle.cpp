#include <stdio.h>
#include <stdlib.h>

int maximalRectangle(char** matrix, int rowSize, int* colSize){
    if (rowSize == 0 || *colSize == 0)
        return 0;

    int cols = *colSize;
    int* height = (int*)malloc(sizeof(int) * cols);
    int* left   = (int*)malloc(sizeof(int) * cols);
    int* right  = (int*)malloc(sizeof(int) * cols);

    int maxArea = 0;

    // Initialize arrays
    for (int i = 0; i < cols; i++) {
        height[i] = 0;
        left[i] = 0;
        right[i] = cols;
    }

    // Process row by row
    for (int i = 0; i < rowSize; i++) {
        int currentLeft = 0, currentRight = cols;

        // Update heights & left bounds
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                height[j]++;
                left[j] = (left[j] > currentLeft) ? left[j] : currentLeft;
            } else {
                height[j] = 0;
                left[j] = 0;
                currentLeft = j + 1;
            }
        }

        // Update right bounds
        for (int j = cols - 1; j >= 0; j--) {
            if (matrix[i][j] == '1') {
                right[j] = (right[j] < currentRight) ? right[j] : currentRight;
            } else {
                right[j] = cols;
                currentRight = j;
            }
        }

        // Calculate max area for this row
        for (int j = 0; j < cols; j++) {
            int area = (right[j] - left[j]) * height[j];
            maxArea = (maxArea > area) ? maxArea : area;
        }
    }

    free(height);
    free(left);
    free(right);

    return maxArea;
}


// ------------------ TESTING ------------------
int main(){
    char* matrix[] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };
    
    int cols = 5;
    int rows = 4;

    int result = maximalRectangle(matrix, rows, &cols);
    printf("Maximal Rectangle Area: %d\n", result);  // Expected Output: 6

    return 0;
}
