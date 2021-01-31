#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STEPS 10

double f(double I) {
    return I; 
}

double g(double Q, double I, double r, double l, double c) {
    return -((r * I) / l + Q / (c * l)); 
}

void Heun(double h, double t[], double Q[], double I[], double r, double l,double c, int n) {
    int i;
    double qk1, qk2, ik1, ik2;

    for (i = 1; i < n; i++) {
        qk1 = h * f(I[i - 1]);
        qk2 = h * f(I[i - 1] + qk1);
        t[i] = t[i - 1] + h;
        Q[i] = Q[i - 1] + (qk1 + qk2) / 2;

        ik1 = h * g(Q[i - 1], I[i - 1], r, l, c);
        ik2 = h * g(Q[i - 1] + qk1, I[i - 1] + ik1, r, l, c);
        I[i] = I[i - 1] + (ik1 + ik2) / 2;
    }
}

int main(void) {
    int i;
    double h = 1 / 64.0;
    double r = 0.0;
    double l = 10.0;
    double c = 0.3;
    double t[STEPS];
    double Q[STEPS];
    double I[STEPS];
    double t0, Q0, I0;
    t0 = 0.0;
    Q0 = 10.0;
    I0 = 0.0;

    t[0] = t0;
    Q[0] = Q0;
    I[0] = I0;

    Heun(h, t, Q, I, r, l, c, STEPS);
    printf("t0=%.1lf,Q0=%.1lf,I0=%.1lf\n", t0, Q0, I0);
    printf("r=%.1lf,l=%.1lf,c=%.1lf\n", r, l, c);
    printf("t,Q,I\n");
    for (i = 0; i < STEPS; i++) {
        printf("%lf,%lf,%lf\n",t[i], Q[i], I[i]);
    }
    return 0;
}