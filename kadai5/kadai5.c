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

// k1とk2でホイン法(p193)
void Heun(double xi, double yi,  double *xi1, double *yi1, double h)
{
    double k1, k2;
    double f;
    func(&f, yi); // x(t)によりません
    
    k1 = h * f;
    func(&f, yi + k1);
    k2 = h * f;
    *xi1 = xi + h;
    *yi1 = yi + 1.0 / 2.0 * (k1 + k2);
    printf("%lf, %lf\n", *xi1, *yi1);
}

// ルンゲ・クッタ法
void RK(double xi, double yi, double *xi1, double *yi1, double h)
{
    double k1,k2,k3,k4;
    double f;

    *xi1 = xi + h;

    func(&f, yi);
    k1 = h * f;
    //printf("k1=%f\n", k1);

    func(&f, yi + k1 / 2);
    k2 = h * f;
    //printf("k2=%f\n", k2);

    func(&f, yi + k2 / 2);
    k3 = h * f;
    //printf("k3=%f\n", k3);

    func(&f, yi + k3);
    k4 = h * f;
    //printf("k4=%f\n", k4);

    *yi1 = yi + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
}

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
    //puts("オイラー法で計算を行いました。");
    printf("初期値はt=%f,u=%fです。\n", tn[0], un[0]);
    for (i = 0;i < STEP_NUM; i++) {
        Euler(tn[i], un[i], &tn[i + 1], &un[i + 1], h);
        printf("%d：t=%f,u=%f\n", i, tn[i + 1], un[i + 1]);
    }

    h = 0.1;
    puts("ホイン法で計算を行いました。");
    for (i = 0;i < STEP_NUM; i++) {
        Heun(tn_H[i], un_H[i], &(tn_H[i + 1]), &(un_H[i + 1]), h);
        printf("%d：t=%f,u=%f\n", i, tn_H[i + 1], un_H[i + 1]);
    }

    h = 0.1;
    puts("ルンゲ・クッタ法で計算を行いました。");
    for (i = 0;i < STEP_NUM; i++) {
        RK(tn_R[i], un_R[i], &tn_R[i + 1], &un_R[i + 1], h);
        printf("%d：t=%f,u=%f\n", i, tn_R[i + 1], un_R[i + 1]);
    }

    // ネイピア数(2.71828182846)
    
    return 0;
}