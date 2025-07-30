#include <stdio.h>

struct term {
    int row;
    int col;
    int value;
};

void transpose(struct term sparse[], struct term transpose[]) {
    int n = sparse[0].value;
    transpose[0].row = sparse[0].col;
    transpose[0].col = sparse[0].row;
    transpose[0].value = sparse[0].value;
    int k = 1;

    // For each column in the original matrix
    for (int i = 0; i < sparse[0].col; i++) {
        // Scan through all non-zero elements
        for (int j = 1; j <= n; j++) {
            if (sparse[j].col == i) {
                transpose[k].row = sparse[j].col;
                transpose[k].col = sparse[j].row;
                transpose[k].value = sparse[j].value;
                k++;
            }
        }
    }
}

void display(struct term sparse[]) {
    int n = sparse[0].value;
    printf("Row Col Value\n");
    for (int i = 0; i <= n; i++) {
        printf("%3d %3d %5d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int n, row, col;
    printf("Enter the number of rows, columns and number of non-zero elements:\n");
    scanf("%d%d%d", &row, &col, &n);
    struct term sparse[50], transpose_matrix[50];
    sparse[0].row = row;
    sparse[0].col = col;
    sparse[0].value = n;

    printf("Enter the row, column and value for each non-zero element:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
    }

    printf("The original array is:\n");
    display(sparse);

    transpose(sparse, transpose_matrix);

    printf("The transpose array is:\n");
    display(transpose_matrix);

    return 0;
}
