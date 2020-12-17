#include <stdio.h>
#include <math.h>

#define STEPS 101

// dx/dt
double f(double x_dash)
{
    double V = x_dash;
    return V;
}

// dV/dt
double g(double V)
{
    double V_dash = 2.0 * V; // qB/m = 2.0
    return V_dash;
}

// ホイン法を用いてローレンツ力
void Lorentz(double t[], double x[], double v[], double h, int i)
{
    double k1, k2;

    // tの計算
    t[i + 1] = t[i] + h;

    // xの計算
    k1 = h * f(v[i]);
    k2 = h * f(v[i] + k1);
    x[i + 1] = x[i] + (k1 + k2) / 2;

    // vの計算
    k1 = h * g(v[i]);
    k2 = h * g(v[i] + k1);
    v[i + 1] = v[i] + (k1 + k2) / 2;
}

int main(void) {
    double t0 = 0.0;
    double x0 = 0.0;
    double v0 = 1.0;
    double t[STEPS + 1], x[STEPS + 1], v[STEPS + 1];
    t[0] = t0;
    x[0] = x0;
    v[0] = v0;
    double h = 0.01; // 0.1より小さいと誤差が少なくていい
    int i;

    puts("ローレンツ力の計算を行います。");
    for (i = 0; i < STEPS; i++) {
        Lorentz(t, x, v, h, i);
        printf("i=%d, t=%lf, x=%lf, v=%lf\n", i, t[i], x[i], v[i]);
    }

    return 0;
}