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
        {2 ,4, 2},
        {1, 2, 3},
        {4, 6, 2},
    };
    double answer[SIZE] = {6, 9, 8};
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