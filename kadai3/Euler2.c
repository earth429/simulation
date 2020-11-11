#include <stdio.h>
#include <math.h>

void func(double *f, double x, double y)
{
    *f = (2 * y) / (1 + x);
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
    double y0 = 0.5;
    double h = 0.5;
    double x1, y1, x2, y2;

    Euler(x0, y0, h, &x1, &y1);
    Euler(x1, y1, h, &x2, &y2);

    puts("オイラー法で計算を行いました。");
    printf("初期値はx0=%f,y0=%fです。\nx1=%f,y1=%f\nx2=%f,y2=%f\n", x0, y0, x1, y1, x2, y2);

    return 0;
}