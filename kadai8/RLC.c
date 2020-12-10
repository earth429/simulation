#include <stdio.h>
#include <math.h>

#define STEPS 100

// Q' = I
double f(double Q_dash)
{
    return Q_dash;
}

// I_dash = dI(t)/dt
double g(double Q, double I, double R, double L, double C)
{
    return -((R * I) / L + Q / (C * L));
}

// ホイン法を用いてRLC共振回路の微分方程式を解く
// tがx,Iがyと考える
void RLC(double Q[], double I[], double t[], double h, double R, double L, double C, int i)
{
    double qk1, ik1, qk2, ik2;
    qk1 = h * f(I[i]);
    ik1 = h * g(Q[i], I[i], R, L, C);

    qk2 = h * f(I[i] + ik1);
    ik2 = h * g(Q[i] + qk1, I[i] + ik1, R, L, C);

    t[i + 1] = t[i] + h;
    Q[i + 1] = Q[i] + (qk1 + qk2) / 2;
    I[i + 1] = I[i] + (ik1 + ik2) / 2;
    

    //I_dash = g(I, Q, R, L, C);

    //k1 = h * I_dash;
    //I = f(Q_dash + k1);
    //I_dash = g(I, Q, R, L, C);
    //k2 = h * I_dash;
    //*t_dash = t + h;
    //*I_ans = I_dash + 1.0 / 2.0 * (k1 + k2);
}

int main(void) {
    double R = 1; // 1kR
    double C = 0.3; // 0.3nF
    double L = 10; // 10mH
    double Q0 = 10; // 10pC
    double I0 = 0; // dQ/dt
    double t0 = 0;
    double Q[STEPS + 1], I[STEPS + 1], t[STEPS + 1]; // 今回の結果
    Q[0] = Q0;
    I[0] = I0;
    t[0] = t0;
    double h = 0.1; // 0.1より小さいと誤差が少なくていい
    int i;

    puts("RLC共振回路の微分方程式の計算を行います。");
    for (i = 0; i < STEPS;i++){
        RLC(Q, I, t, h, R, L, C, i);
        printf("i=%d, t=%lf, I=%lf, Q=%lf\n", i, t[i], I[i], Q[i]);
    }

    return 0;
}