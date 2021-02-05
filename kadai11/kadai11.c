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
        printf("x%d = ",i);
        printf("%lf\n", x[i]);
    }

    printf("ans\ttemp\n");
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
    printf("消去後の方程式\n");
    for (i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("%f, " ,tempp[i][j]);
        }
        printf(" %f\n",tempa[i]);
    }
    
    for (i = SIZE - 1; i >= 0; i--){
        double m = tempa[i];
        for (j = i + 1; j < SIZE; j++){
            m -= tempp[i][j] * x[j];
        }
        x[i] = m / tempp[i][i];
    }
}