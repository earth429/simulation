#include <stdio.h>
#include <math.h>

#define STEPS 10

double f(double x_dash)
{
    double V = x_dash;
    return V;
}

double g(double V)
{
    double V_dash = 2.0 * V; // qB/m = 2.0
    return V_dash;
}

// ホイン法を用いてローレンツ力
void Lorentz(double t[])
{
    double k1, k2;
    
}

int main(void) {
    double t0 = 0.0;
    double x0 = 0.0;
    double v0 = 1.0;
    double t[STEPS + 1], x[STEPS + 1], v[STEPS + 1];
    double h = 0.1; // 0.1より小さいと誤差が少なくていい
    int i;

    puts("ローレンツ力の計算を行います。");

    return 0;
}