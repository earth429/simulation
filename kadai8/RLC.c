#include <stdio.h>
#include <math.h>

void func1(double *I, double Q_dash)
{
    *I = Q_dash;
}

// I_dash = dI(t)/dt
void func2(double *I_dash, double I, double Q, double R, double L, double C)
{
    *I_dash = (0 - R * I - Q / C) / L;
}

// ホイン法を用いてRLC共振回路の微分方程式を解く
// tがx,Iがyと考える
void RLC(double t, double *t_dash, double h, double *I_ans, double Q, double Q_dash, double R, double L, double C)
{
    double k1, k2;
    double I, I_dash;
    func1(&I, Q_dash);
    func2(&I_dash, I, Q, R, L, C);

    k1 = h * I_dash;
    func1(&I, Q_dash + k1);
    func2(&I_dash, I, Q, R, L, C);
    k2 = h * I_dash;
    *t_dash = t + h;
    *I_ans = I_dash + 1.0 / 2.0 * (k1 + k2);
}

int main(void) {
    double R = 1; // 1kR
    double C = 0.3; // 0.3nF
    double L = 10; // 10mH
    double Q0 = 10; // 10pC
    double t = 0;
    double Q = Q0;
    double Q_dash = 0;
    double h = 0.1; // 0.1より小さいと誤差が少なくていい
    double I, t_dash; // 今回の結果
    int i;

    puts("RLC共振回路の微分方程式の計算を行います。");
    for (i = 0; i < 5;i++){
        RLC(t, &t_dash, h, &I, Q, Q_dash, R, L, C);
        printf("i=%d, t=%lf, I=%lf\n", i, t, I);
        t = t_dash;
    }

    return 0;
}