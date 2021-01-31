#include <stdio.h>
#include <stdlib.h>

#define STEPS 800

double f(double v) {
    return v; 
}

double g(double y, double v, double k, double l) {
    return -k * y - l * v; 
}

void Euler(double h, double t[], double y[],double v[], double k, double l, int n) {
    int i;

    for (i = 1; i < n; i++) {
        t[i] = t[i - 1] + h;
        y[i] = y[i - 1] + h * f(v[i - 1]);
        v[i] = v[i - 1] + h * g(y[i - 1], v[i - 1], k , l);
    }
}

int main(void) {
    int i;
    double h = 1 / 64.0;
    double k = 3.0;
    double l = 1.0;
    double t[STEPS];
    double y[STEPS];
    double v[STEPS];
    double t0, y0, v0;
    t0 = 0.0;
    y0 = 10.0;
    v0 = 0.0;

    t[0] = t0;
    y[0] = y0;
    v[0] = v0;

    Euler(h, t, y, v, k, l, STEPS);
    printf("t0=%.1lf,y0=%.1lf,v0=%.1lf\n", t0, y0, v0);
    printf("k=%.1lf,l=%.1lf\n", k, l);
    printf("t,y,v\n");
    for (i = 0; i < STEPS; i++) {
        printf("%lf,%lf,%lf\n", t[i], y[i], v[i]);
    }
    return 0;
}