#include <stdio.h>
#include <math.h>

//#define COLS 10 //行(横)
//#define ROWS 10 //列(縦)
#define N 3

double x[N] = {0, 0, 0};

double A[N][N] = {{2, 2, 6},
                  {4, 5, 13},
                  {5, 8, 24}};
double b[N] = {24, 52, 93};

void disp(double A[N][N],double b[N]) {
    int i, j;
    printf("--------------------\n");
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("%.2lf ",A[i][j]);
        }
        printf("| %.2lf\n",b[i]);
    }
    printf("--------------------\n");
}

// 前進消去
void ForwardElimination(void) {
    int i, j, k;
    double m;

    for (k = 0; k < N - 1; k++) {
        for (i = k + 1; i < N; i++) {
            m = A[i][k] / A[k][k];
            printf("m = %lf\n", m);
            A[i][k] = 0;
            for (j = k + 1; j < N; j++) {
                A[i][j] = A[i][j] - A[k][j] * m;
                printf("A[%d][%d] = %lf\n", i, j, A[i][j]);
            }
            b[i] = b[i] - b[k] * m;
            printf("b[%d] = %lf\n\n", i, b[i]);
        }
        disp(A, b);
    }

    /*for (i = 0; i < COLS; i++)
        {
            for (j = 0; j < ROWS; j++)
            {
            }
        }*/
}

void dispAns(void) {
    int i;
    printf("Answer\n");
    for (i = 0; i < N; i++) {
        printf("x[%d] = %lf\n", i + 1, x[i]);
    }
}

void BackwardSubstitution(void) {
    int k, j;
    x[N - 1] = b[N - 1] / A[N - 1][N - 1];
    for (k = N - 2; k >= 0; k--) {
        x[k] = b[k];
        for (j = k + 1; j <= N; j++) {
            x[k] -= A[k][j] * x[j];
        }
        x[k] /= A[k][k];
    }
}



int main(void) {
    /*int A[COLS][ROWS];

    int i;

    puts("ガウスの消去法で連立一次方程式を計算しました。");*/
    disp(A, b);
    ForwardElimination();
    disp(A, b);
    BackwardSubstitution();
    dispAns(); 
    return 0;
}