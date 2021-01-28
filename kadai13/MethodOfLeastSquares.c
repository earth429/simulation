#include<stdio.h>
#include <stdlib.h>
#include <math.h>

//近似多項式の次数+1
#define SIZE 2
#define DATA 4
#define PIVOTING 1

void GaussEelimination(double parameters[SIZE][SIZE], double answer[SIZE], double x[SIZE]);
void Translation(double parameters[SIZE][SIZE], double answer[SIZE], int pivot);
void leastSquares(double x[DATA], double y[DATA], double ans[SIZE]);

int main(void){
    int i;
    double x[DATA] = {1, 2, 3, 4};
    double y[DATA] = {0, 1, 2, 4};
    double ans[SIZE];
    leastSquares(x, y, ans);
    printf("%d次多項式で近似\n",SIZE - 1);
    for(i = 0; i < SIZE;i++){
        printf("a%d = %lf\n", i, ans[i]);
    }
    return 0;
}

void leastSquares(double x[DATA], double y[DATA], double ans[SIZE]) {
    int i, j, k;
    double parameters[SIZE][SIZE];
    double answer[SIZE];
    //行列生成
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            double sum = 0;
            for (k = 0; k < DATA;k++) {
                sum += pow(x[k], i + j);
            }
            parameters[i][j] = sum;
        }
        double sum = 0;
        for (k = 0; k < DATA;k++) {
            sum += y[k] * pow(x[k],i);
        }
        answer[i] = sum;
    }
    //連立を解く
    GaussEelimination(parameters, answer, ans);
}


void GaussEelimination(double parameters[SIZE][SIZE], double answer[SIZE], double x[SIZE]) {
    int i, j, k;
    double pivot;
    double temp_p[SIZE][SIZE];
    double temp_a[SIZE];
    //copy
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            temp_p[i][j] = parameters[i][j];
        }
        temp_a[i] = answer[i];
    }

    for (i = 0; i < SIZE - 1; i++) {
        //pivot選択
        if (PIVOTING) {
            Translation(temp_p, temp_a, i);
        }
        pivot = temp_p[i][i];
        for (j = 1 + i; j < SIZE; j++) {
            double m = temp_p[j][i] / pivot;
            //parameter消去
            for (k = 0; k < SIZE; k++) {
                temp_p[j][k] = temp_p[j][k] - temp_p[i][k] * m;
            }
            //answer更新
            temp_a[j] = temp_a[j] - temp_a[i] * m;
        }
    }
    
    for (i = SIZE - 1; i >= 0; i--) {
        double m = temp_a[i];
        for (j = i + 1; j < SIZE; j++) {
            m -= temp_p[i][j] * x[j];
        }
        x[i] = m / temp_p[i][i];
    }
}

void Translation(double parameters[SIZE][SIZE], double answer[SIZE],int pivot) {
    double temp_a;
    int i;
    double max = fabs(parameters[pivot][pivot]);
    int index = pivot;
    //絶対最大値探索
    for (i = pivot; i < SIZE;i++) {
        if (max < fabs(parameters[i][pivot])) {
            max = parameters[i][pivot];
            index = i;
        }
    }
    //入れ替え
    for(i = 0; i < SIZE;i ++) {
        double temp_p;
        temp_p = parameters[pivot][i];
        parameters[pivot][i] = parameters[index][i];
        parameters[index][i] = temp_p;
    }
    temp_a = answer[pivot];
    answer[pivot] = answer[index];
    answer[index] = temp_a;
}