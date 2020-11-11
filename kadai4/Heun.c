// ホイン法
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

void Heun(double *ans, double xi, double xi1, double yi, double yi1, double h)
{
    double fi1;
    func(&fi1, xi1, yi1);

    *ans = yi + h * ((yi1 + fi1) / 2); // このときyi=y0,yi1はfi(yi1がxiとyiから求めたfだから),fi1はfi+1*
}

int main(void) {
    double x0 = 0;
    double y0 = 0.5;
    double h = 0.5;
    double x1, y1, ans;

    Euler(x0, y0, h, &x1, &y1); // 仮の値
    Heun(&ans, x0, x1, y0, y1, h);

    puts("ホイン法で計算を行いました。");
    printf("初期値はx0=%f,y0=%fです。\ny1=%f\n", x0, y0, ans);
}