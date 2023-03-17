#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
void sort_spiral(int **matrix, int n, int m, int **result_matrix);
void swap(int *a, int *b);
void input(int **matrix, int n, int m);
void povorot(int **matrix, int n, int m);
void output(int **matrix, int n, int m);

int main() {
    int **matrix = NULL;

    int **result = NULL;

    int n, m;

    if (scanf("%d%d", &n, &m) == 2 && n > 0 && m > 0) {
        matrix = (int **)calloc(n, sizeof(int *));
        for (int i = 0; i < n; i++) {
            matrix[i] = (int *)calloc(m, sizeof(int));
        }
        input(matrix, n, m);
    }

    if (matrix != NULL) {
        result = (int **)calloc(n, sizeof(int *));
        for (int i = 0; i < n; i++) {
            result[i] = (int *)calloc(m, sizeof(int));
        }
        sort_vertical(matrix, n, m, result);
        // sort_horizontal(matrix, n, m, result);
        output(result, n, m);
        free(matrix);
        free(result);
    } else {
        printf("n/a");
    }
    return 0;
}
void swap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}
void povorot(int **matrix, int n, int m) {
    for (int i = 0; i < n / 2 - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (j % 1 == 0) {
                swap(&matrix[i][j], &matrix[n - i][j]);
            }
        }
    }
}
void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result_matrix[j][i] = matrix[i][j];
        }
    }
    povorot(result_matrix, n, m);
}

void input(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                matrix = NULL;
                break;
            }
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j != m - 1) printf(" ");
            if (j == m - 1) printf("\n");
        }
    }
}

/* int input_t(int **matrix, int n, int m) {

 int rtn = 0;

for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
         if (scanf("%d", &matrix[i][j]) != 1) {
              rtn = 0;
            break;
          } else {
               rtn = 1;
      }
       }
  }
 return rtn;
}
*/