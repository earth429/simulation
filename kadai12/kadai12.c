#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 3
#define PIVOTING 1 // ピボット0がなし，1があり

void GaussEelimination(double parameters[SIZE][SIZE], double answer[SIZE], double x[SIZE]);
void Translation(double parameters[SIZE][SIZE], double answer[SIZE], int pivot);

int main(void){
    int i,j;
    double parameters[SIZE][SIZE] = {
        {2 ,4, 2},
        {1, 2, 3},
        {4, 6, 2},
    };
    double answer[SIZE] = {6, 9, 8};
    double x[SIZE];
    GaussEelimination(parameters, answer, x);
    for (i = 0; i < SIZE; i++){
        printf("x%d = ",i + 1);
        printf("%lf\n", x[i]);
    }

    puts("解の確認");
    printf("ans\t\tcheck\n");
    for (i = 0; i < SIZE; i++){
        double tmp = 0;
        for (j = 0; j < SIZE; j++){
            tmp += parameters[i][j] * x[j];
        }
        printf("%lf\t%lf\n", answer[i], tmp);
    }
}

void GaussEelimination(double parameters[SIZE][SIZE], double answer[SIZE], double x[SIZE]){
    int i,j,k;
    double pivot;
    double tmpp[SIZE][SIZE];
    double tmpa[SIZE];
    //copy
    for (i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            tmpp[i][j] = parameters[i][j];
        }
        tmpa[i] = answer[i];
    }

    for (i = 0; i < SIZE - 1; i++){
        //pivot選択
        if(PIVOTING) {
            Translation(tmpp, tmpa, i);
        }
        pivot = tmpp[i][i];
        for (j = 1 + i; j < SIZE; j++){
            double m = tmpp[j][i] / pivot;
            //parameter消去
            for (k = 0; k < SIZE; k++){
                tmpp[j][k] = tmpp[j][k] - tmpp[i][k] * m;
            }
            //answer更新
            tmpa[j] = tmpa[j] - tmpa[i] * m;
        }
    }
    
    for (i = SIZE - 1; i >= 0; i--){
        double m = tmpa[i];
        for (j = i + 1; j < SIZE; j++){
            m -= tmpp[i][j] * x[j];
        }
        x[i] = m / tmpp[i][i];
    }
}

void Translation(double parameters[SIZE][SIZE], double answer[SIZE],int pivot){
    double tmpa;
    int i;
    double max = fabs(parameters[pivot][pivot]);
    int index = pivot;
    //絶対最大値探索
    for(i = pivot; i < SIZE;i++){
        if (max < fabs(parameters[i][pivot])){
            max = parameters[i][pivot];
            index = i;
        }
    }

    //入れ替え
    for(i = 0; i < SIZE;i ++){
        double tmpp;
        tmpp = parameters[pivot][i];
        parameters[pivot][i] = parameters[index][i];
        parameters[index][i] = tmpp;
    }
    tmpa = answer[pivot];
    answer[pivot] = answer[index];
    answer[index] = tmpa;
}