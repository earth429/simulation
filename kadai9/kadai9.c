#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STEPS 15

// dx/dt
double xp(double vx) {
    return vx; 
}

// dVx/dt
double vxp(double vy, double b) {
    return vy * b; 
}

// dy/dt
double yp(double vy) {
    return vy; 
}

// dVy/dt
double vyp(double vx, double b) {
    return -vx * b; 
}

void Heun(double h, double t[], double x[], double vx[], double y[], double vy[], double b, int n) {
    int i;
    double k1, l1, m1, n1, k2, l2, m2, n2;

    for (i = 1; i < n; i++) {
        t[i] = t[i - 1] + h;
        k1 = h * vxp(vy[i - 1], b);
        l1 = h * xp(vx[i - 1]);
        m1 = h * vyp(vx[i - 1], b);
        n1 = h * yp(vy[i - 1]); 

        k2 = h * vxp(vy[i - 1] + k1, b);
        l2 = h * xp(vx[i - 1] + l1);
        m2 = h * vyp(vx[i - 1] + m1, b);
        n2 = h * yp(vy[i - 1] + n1);
        
        vx[i] = vx[i - 1] + (k1 + k2) / 2;
        x[i] = x[i - 1] + (l1 + l2) / 2;
        vy[i] = vy[i - 1] + (m1 + m2) / 2;
        y[i] = y[i - 1] + (n1 + n2) / 2;
    }
}

int main(void) {
    int i;
    double h = 0.001;
    double b = 10.0;
    double t[STEPS];
    double vx[STEPS];
    double x[STEPS];
    double vy[STEPS];
    double y[STEPS];
    double t0, x0, vx0, y0, vy0;
    t0 = 0.0;
    x0 = 0.1;
    vx0 = 0.0;
    y0 = 0.0;
    vy0 = 0.1;

    t[0] = t0;
    x[0] = x0;
    vx[0] = vx0;
    y[0] = y0;
    vy[0] = vy0;

    Heun(h, t, x, vx, y, vy, b, STEPS);
    printf("t0=%.1lf,x0=%.1lf,vx0=%.1lf,y0=%.1lf,vy0=%.1lf\n", t0, x0, vx0, y0, vy0);
    printf("t,x,vx,y,vy\n");
    for (i = 0; i < STEPS; i++) {
        printf("%lf,%lf,%lf,%lf,%lf\n",t[i], x[i], vx[i], y[i], vy[i]);
    }
    
    return 0;
}