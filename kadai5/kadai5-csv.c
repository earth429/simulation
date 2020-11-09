#include <stdio.h>
#include <math.h>

#define STEP_NUM 10

void func(double *f, double u)
{
    *f = u;
}

// オイラー法
void Euler(double x0, double y0, double *x1, double *y1, double h)
{
    double f;
    func(&f, y0);

    *x1 = x0 + h;
    *y1 = y0 + h * f;
}

// ホイン法
void Heun(double xi, double yi,  double *xi1, double *yi1, double h)
{
    double k1, k2;
    double f;
    func(&f, yi);
    
    k1 = h * f;
    func(&f, yi + k1);
    k2 = h * f;
    *xi1 = xi + h;
    *yi1 = yi + 1.0 / 2.0 * (k1 + k2);
}

// ルンゲ・クッタ法
void RK(double xi, double yi, double *xi1, double *yi1, double h)
{
    double k1,k2,k3,k4;
    double f;

    *xi1 = xi + h;

    func(&f, yi);
    k1 = h * f;

    func(&f, yi + k1 / 2);
    k2 = h * f;

    func(&f, yi + k2 / 2);
    k3 = h * f;

    func(&f, yi + k3);
    k4 = h * f;

    *yi1 = yi + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
}
// ネイピア数(2.71828182846)
int main(void) {

    double tn[STEP_NUM];
    double un[STEP_NUM];
    double tn_H[STEP_NUM];
    double un_H[STEP_NUM];
    double tn_R[STEP_NUM];
    double un_R[STEP_NUM];
    tn[0] = 0.0; // t0
    un[0] = 1.0; // u0
    tn_H[0] = 0.0; // t0
    un_H[0] = 1.0; // u0
    tn_R[0] = 0.0; // t0
    un_R[0] = 1.0; // u0
    double h = 0.1;

    int i;
    /*for (i = 0;i < STEP_NUM; i++) {
        Euler(tn[i], un[i], &tn[i + 1], &un[i + 1], h);
        printf("%.14lf,%.14lf\n", tn[i + 1], un[i + 1]);
    }
    puts("");

    h = 0.1;
    for (i = 0;i < STEP_NUM; i++) {
        Heun(tn_H[i], un_H[i], &tn_H[i + 1], &un_H[i + 1], h);
        printf("%.14lf,%.14lf\n", tn_H[i + 1], un_H[i + 1]);
    }
    puts("");

    h = 0.1;*/
    for (i = 0;i < STEP_NUM; i++) {
        RK(tn_R[i], un_R[i], &tn_R[i + 1], &un_R[i + 1], h);
        printf("%.14lf,%.14lf\n", tn_R[i + 1], un_R[i + 1]);
    }

    return 0;
}