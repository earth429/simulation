#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 4

void GaussEelimination(double parameters[SIZE][SIZE], double answer[SIZE], double x[SIZE]);

int main(void){
    int i,j;
    double parameters[SIZE][SIZE] = {
        {1 ,2, 1, 5},
        {8, 1, 3, 1},
        {1, 7, 1, 1},
        {1, 1, 6, 1}
    };
    double answer[SIZE] = {20.5, 14.5, 18.5, 9.0};
    double x[SIZE];
    GaussEelimination(parameters, answer, x);
    for (i = 0; i < SIZE; i++){
        printf("x%d = ",i + 1);
        printf("%lf\n", x[i]);
    }

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
    // コピー
    for (i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            tmpp[i][j] = parameters[i][j];
        }
        tmpa[i] = answer[i];
    }

    for (i = 0; i < SIZE - 1; i++){
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