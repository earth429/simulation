#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 3
#define PIVOTING 1

void GaussEelimination(double parameters[SIZE][SIZE], double answer[SIZE], double x[SIZE]);
void Translation(double parameters[SIZE][SIZE], double answer[SIZE], int pivot);

int main(void){
    int i,j;
    double parameters[SIZE][SIZE] = {
        {2 ,2, 6},
        {3, 5, 13},
        {5, 8, 24},
    };
    double answer[SIZE] = {24, 52, 93};
    double x[SIZE];
    GaussEelimination(parameters, answer, x);
    for (i = 0; i < SIZE; i++){
        printf("x%d = ",i);
        printf("%lf\n", x[i]);
    }

    printf("解の確認\n");
    printf("右辺\t計算した右辺\n");
    for (i = 0; i < SIZE; i++){
        double temp = 0;
        for (j = 0; j < SIZE; j++){
            temp += parameters[i][j] * x[j];
        }
        printf("%lf\t%lf\n", answer[i], temp);
    }
}

void GaussEelimination(double parameters[SIZE][SIZE], double answer[SIZE], double x[SIZE]) {
    int i, j, k;
    double pivot;
    double temp_p[SIZE][SIZE];
    double temp_a[SIZE];
    //copy
    for (i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++){
            temp_p[i][j] = parameters[i][j];
        }
        temp_a[i] = answer[i];
    }

    for (i = 0; i < SIZE - 1; i++) {
        //pivot選択
        if(PIVOTING)
            Translation(temp_p, temp_a, i);
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
        for (j = i + 1; j < SIZE; j++){
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
    for (i = 0; i < SIZE;i ++) {
        double temp_p;
        temp_p = parameters[pivot][i];
        parameters[pivot][i] = parameters[index][i];
        parameters[index][i] = temp_p;
    }
    temp_a = answer[pivot];
    answer[pivot] = answer[index];
    answer[index] = temp_a;

}