// オイラー法
#include <stdio.h>
#include <math.h>

void func(double *f, double x, double y)
{
    *f = y / (1 + x);
}

void Euler(double x0, double y0, double h, double *x1, double *y1)
{
    double f;
    func(&f, x0, y0);

    *x1 = x0 + h;
    *y1 = y0 + h * f;
}

int main(void) {
    double x0 = 0;
    double y0 = 1;
    double h = 0.5;
    double x1, y1;

    Euler(x0, y0, h, &x1, &y1);

    puts("オイラー法で計算を行いました。");
    printf("初期値はx0=%f,y0=%fです。\nx1=%f,y1=%fです。\n", x0, y0, x1, y1);

    return 0;
}