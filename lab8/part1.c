#include <stdio.h>
#include <math.h>

typedef struct {
    double mat[3][3];
    double det;
} matrix;

void print_matrix(matrix initial_matrix) {
    printf("Matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            printf("| %8.4f |", initial_matrix.mat[i][j]);
        }
        printf("|\n");
    }
    printf("Determinant: %8.4f\n", initial_matrix.det);
}

void determinant_of_matrix(matrix* initial_matrix) {
    double a = initial_matrix->mat[0][0], b = initial_matrix->mat[0][1], c = initial_matrix->mat[0][2],
           d = initial_matrix->mat[1][0], e = initial_matrix->mat[1][1], f = initial_matrix->mat[1][2],
           g = initial_matrix->mat[2][0], h = initial_matrix->mat[2][1], i = initial_matrix->mat[2][2];

    initial_matrix->det = a * (e*i - f*h) - b * (d*i - f*g) + c * (d*h - e*g);
}

void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix) {
    determinant_of_matrix(initial_matrix);

    double a = initial_matrix->mat[0][0], b = initial_matrix->mat[0][1], c = initial_matrix->mat[0][2],
           d = initial_matrix->mat[1][0], e = initial_matrix->mat[1][1], f = initial_matrix->mat[1][2],
           g = initial_matrix->mat[2][0], h = initial_matrix->mat[2][1], i = initial_matrix->mat[2][2];

    double det = initial_matrix->det;

    if (det == 0) {
        printf("Error: matrix is not invertible.\n");
        return;
    }

    inverted_matrix->mat[0][0] = (e*i - f*h) / det;
    inverted_matrix->mat[0][1] = (c*h - b*i) / det;
    inverted_matrix->mat[0][2] = (b*f - c*e) / det;
    inverted_matrix->mat[1][0] = (f*g - d*i) / det;
    inverted_matrix->mat[1][1] = (a*i - c*g) / det;
    inverted_matrix->mat[1][2] = (c*d - a*f) / det;
    inverted_matrix->mat[2][0] = (d*h - e*g) / det;
    inverted_matrix->mat[2][1] = (b*g - a*h) / det;
    inverted_matrix->mat[2][2] = (a*e - b*d) / det;

    inverted_matrix->det = 1 / det;
}

int main() {
    matrix m, inv;
    printf("Enter the matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &m.mat[i][j]);
        }
    }
    inverse_matrix(&m, &inv);
    printf("Original ");
    print_matrix(m);
    printf("Inverted ");
    print_matrix(inv);
    return 0;
}