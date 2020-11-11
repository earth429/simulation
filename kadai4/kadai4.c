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
/*void Heun(double *ans, double xi, double xi1, double yi, double yi1, double h)
{
    double fi1;
    func(&fi1, yi1);

    *ans = yi + h * ((yi1 + fi1) / 2); // このときyi=y0,yi1はfi(yi1がxiとyiから求めたfだから),fi1はfi+1*
}*/

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

int main(void) {

    double tn[STEP_NUM];
    double un[STEP_NUM];
    double tn_H[STEP_NUM];
    double un_H[STEP_NUM];
    tn[0] = 0.0; // t0
    un[0] = 1.0; // u0
    tn_H[0] = 0.0; // t0
    un_H[0] = 1.0; // u0
    double h = 0.1;

    int i;
    //puts("オイラー法で計算を行いました。");
    printf("初期値はt=%f,u=%fです。\n", tn[0], un[0]);
    for (i = 0;i < STEP_NUM; i++) {
        Euler(tn[i], un[i], &tn[i + 1], &un[i + 1], h);
        printf("%d：t=%f,u=%f\n", i, tn[i + 1], un[i + 1]);
    }

    /*tn[0] = 0; // t0
    un[0] = 1; // u0
    double h = 0.1;
    

    puts("ホイン法で計算を行いました。");
    printf("初期値はt=%f,u=%fです。\n", tn[0], un[0]);*/
    h = 0.1;
    puts("ホイン法で計算を行いました。");
    for (i = 0;i < STEP_NUM; i++) {
        Heun(tn_H[i], un_H[i], &tn_H[i + 1], &un_H[i + 1], h);
        printf("%d：t=%f,u=%f\n", i, tn_H[i + 1], un_H[i + 1]);
    }
    
    return 0;
}