#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
double* createMatrix(int rows, int cols) {
    double *matrix = (double*)malloc(rows * cols * sizeof(double));
    return matrix;
}

// Function to free memory allocated for a matrix
void freeMatrix(double *matrix) {
    free(matrix);
}

// Function to print a matrix
void dumpMatrix(double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

// Function to transpose a matrix
double* transpose(double *matrix, int rows, int cols) {
    double *result = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + j * rows + i) = *(matrix + i * cols + j);
        }
    }
    return result;
}

// Function to add two matrices
double* add(double *matrix1, double *matrix2, int rows, int cols) {
    double *result = createMatrix(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        *(result + i) = *(matrix1 + i) + *(matrix2 + i);
    }
    return result;
}

// Function to multiply two matrices
double* multiply(double *matrix1, double *matrix2, int rows1, int cols1, int cols2) {
    double *result = createMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            *(result + i * cols2 + j) = 0;
            for (int k = 0; k < cols1; k++) {
                *(result + i * cols2 + j) += (*(matrix1 + i * cols1 + k)) * (*(matrix2 + k * cols2 + j));
            }
        }
    }
    return result;
}

int main() {
    int rows1 = 2, cols1 = 3;
    double matrix1[] = {1, 2, 3, 4, 5, 6};

    int rows2 = 3, cols2 = 2;
    double matrix2[] = {7, 8, 9, 10, 11, 12};

    printf("Matrix 1:\n");
    dumpMatrix(matrix1, rows1, cols1);

    printf("\nMatrix 2:\n");
    dumpMatrix(matrix2, rows2, cols2);

    printf("\nTranspose of Matrix 1:\n");
    double *transposed = transpose(matrix1, rows1, cols1);
    dumpMatrix(transposed, cols1, rows1);
    freeMatrix(transposed);

    printf("\nMatrix 1 + Matrix 2:\n");
    double *added = add(matrix1, matrix2, rows1, cols1);
    dumpMatrix(added, rows1, cols1);
    freeMatrix(added);

    printf("\nMatrix 1 * Matrix 2:\n");
    double *multiplied = multiply(matrix1, matrix2, rows1, cols1, cols2);
    dumpMatrix(multiplied, rows1, cols2);
    freeMatrix(multiplied);

    return 0;
}
