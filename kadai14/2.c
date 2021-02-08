#include<stdio.h>
#include <stdlib.h>
#include <math.h>

//近似多項式の次数+1
#define SIZE 3
#define DATA 10
#define PIVOTING 1

void GaussEelimination(double parameters[SIZE][SIZE], double answer[SIZE], double x[SIZE]);
void Translation(double parameters[SIZE][SIZE], double answer[SIZE], int pivot);
void leastSquares(double x[DATA], double y[DATA], double ans[SIZE]);

int main(void){
    int i;
    double x[DATA] = {500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000};
    double y[DATA] = {328.512000, 499.776000, 846.464000, 1896.896000, 2361.536000, 1441.856000, 2901.568000, 3786.368000, 4446.400000, 5056.000000};
    double ans[SIZE];
    leastSquares(x, y, ans);
    printf("%d次多項式で近似\n",SIZE - 1);
    for(i = 0; i < SIZE;i++){
        switch (i) {
            case 0:
                printf("a = %lf\n", ans[i]);
                break;
            case 1:
                printf("b = %lf\n", ans[i]);
                break;
            case 2:
                printf("c = %lf\n", ans[i]);
                break;
        }
    }
    return 0;
}

void leastSquares(double x[DATA], double y[DATA], double ans[SIZE]){
    int i,j,k;
    double parameters[SIZE][SIZE];
    double answer[SIZE];
    //行列生成
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            double sum = 0;
            for(k = 0; k < DATA;k++){
                sum += pow(x[k], i + j);
            }
            parameters[i][j] = sum;
        }
        double sum = 0;
        for(k = 0; k < DATA;k++){
            sum += y[k] * pow(x[k],i);
        }
        answer[i] = sum;
    }
    //連立を解く
    GaussEelimination(parameters, answer, ans);
}

void GaussEelimination(double parameters[SIZE][SIZE], double answer[SIZE], double x[SIZE]){
    int i,j,k;
    double pivot;
    double tempp[SIZE][SIZE];
    double tempa[SIZE];
    //copy
    for (i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            tempp[i][j] = parameters[i][j];
        }
        tempa[i] = answer[i];
    }

    for (i = 0; i < SIZE - 1; i++){
        //pivot選択
        if(PIVOTING)
            Translation(tempp, tempa, i);
        pivot = tempp[i][i];
        for (j = 1 + i; j < SIZE; j++){
            double m = tempp[j][i] / pivot;
            //parameter消去
            for (k = 0; k < SIZE; k++){
                tempp[j][k] = tempp[j][k] - tempp[i][k] * m;
            }
            //answer更新
            tempa[j] = tempa[j] - tempa[i] * m;
        }
    }
    
    for (i = SIZE - 1; i >= 0; i--){
        double m = tempa[i];
        for (j = i + 1; j < SIZE; j++){
            m -= tempp[i][j] * x[j];
        }
        x[i] = m / tempp[i][i];
    }
}

void Translation(double parameters[SIZE][SIZE], double answer[SIZE],int pivot){
    double tempa;
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
        double tempp;
        tempp = parameters[pivot][i];
        parameters[pivot][i] = parameters[index][i];
        parameters[index][i] = tempp;
    }
    tempa = answer[pivot];
    answer[pivot] = answer[index];
    answer[index] = tempa;

}