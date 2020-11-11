// ルンゲ・クッタ法
#include <stdio.h>
#include <math.h>

void func(double *f, double x, double y)
{
    *f = (2 * y) / (1 + x);
}

// ルンゲ・クッタ法
void RK(double xi, double *xi1, double yi, double *yi1, double h)
{
    double k1,k2,k3,k4;
    double f;

    *xi1 = xi + h;

    func(&f, xi, yi);
    k1 = h * f;
    printf("k1=%f\n", k1);

    func(&f, xi + h / 2, yi + k1 / 2);
    k2 = h * f;
    printf("k2=%f\n", k2);

    func(&f, xi + h / 2, yi + k2 / 2);
    k3 = h * f;
    printf("k3=%f\n", k3);

    func(&f, xi + h, yi + k3);
    k4 = h * f;
    printf("k4=%f\n", k4);

    *yi1 = yi + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}

int main(void) {
    double x0 = 0;
    double y0 = 0.5;
    double h = 0.5;
    double x1, y1;

    puts("ルンゲ・クッタ法で計算を行います。");
    printf("初期値はx0=%f,y0=%fです。\n", x0, y0);
    RK(x0, &x1, y0, &y1, h);
    printf("x1=%f,y1=%f\n", x1, y1);

    return 0;
}