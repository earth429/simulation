#include <stdio.h>
#include <math.h>

#define STEP_NUM 10

void func(double *f, double u)
{
    *f = u;
}

void Euler(double x0, double y0, double *x1, double *y1, double h)
{
    double f;
    func(&f, y0);

    *x1 = x0 + h;
    *y1 = y0 + h * f;
}

int main(void) {

    double tn[STEP_NUM];
    double un[STEP_NUM];
    tn[0] = 0; // t0
    un[0] = 1; // u0
    double h = 0.1;

    int i;
    puts("オイラー法で計算を行いました。");
    printf("初期値はt=%f,u=%fです。\n", tn[0], un[0]);
    for (i = 0;i < STEP_NUM; i++) {
        Euler(tn[i], un[i], &tn[i + 1], &un[i + 1], h);
        printf("%d：t=%f,u=%f\n", i, tn[i + 1], un[i + 1]);
    }
    
    return 0;
}