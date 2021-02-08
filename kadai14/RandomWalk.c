#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TIMES 5
#define MAX 5000
#define H 500
#define L 1

double RandomWalk(int step, double rate);

int main(void) {
    int i, j;
    int step;
    
    double rate = 0.5;
    srand(time(NULL));
    double var[MAX / H];
    for (step = H; step <= MAX; step += H) {
        double varSum = 0;
        for (i = 0; i < TIMES;i++) {
            double sum = 0;
            double squareSum = 0;
            for (j = 0; j < TIMES; j++) {
                double x = RandomWalk(step, rate);
                sum += x;
                squareSum += x * x;
            }

            //分散を求める
            varSum += squareSum / TIMES - pow(sum / TIMES, 2);
        }
        var[step / H - 1] = varSum / TIMES;
    }

    printf("n,v\n");
    for (i = 0; i < MAX / H;i++) {
        printf("%d,%lf\n", H * (i + 1), var[i]);    
    }

    return 0;
}

//rateの確率で正に動く
double RandomWalk(int step, double rate){
    double x = 0;
    int i;
    for (i = 0; i < step;i++) {
        if((double)rand() / RAND_MAX < rate) {
            x += L;
        }
        else {
            x -= L;
        }
    }
    return x;
}