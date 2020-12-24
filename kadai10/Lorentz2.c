#include <stdio.h>
#include <math.h>

#define STEPS 101

// dx/dt
double xp(double x_dash) {
    double Vx = x_dash;
    return Vx;
}

// dVx/dt
double vxp(double Vx, double b) {
    double Vx_dash = b * Vx; // qB/m = 2.0
    return Vx_dash;
}

// dy/dt
double yp(double y_dash) {
    double Vy = y_dash;
    return Vy;
}

// dVy/dt
double vyp(double Vy, double b) {
    double Vy_dash = b * Vy; // qB/m = 2.0
    return Vy_dash;
}

// dz/dt
double zp(double z_dash) {
    double Vz = z_dash;
    return Vz;
}

// dVz/dt
double vzp(double e) {
    return e;
}


// ホイン法を用いてローレンツ力
void Lorentz2(double t[], double x[], double vx[], double y[], double vy[], double z[], double vz[], double h, double b, double e, int i)
{
    double k1, l1, m1, n1, o1, p1;
    double k2, l2, m2, n2, o2, p2;

    // tの計算
    t[i + 1] = t[i] + h;

    k1 = h * vxp(vy[i], b);
    l1 = h * xp(vx[i]);
    m1 = h * vyp(vx[i], b);
    n1 = h * yp(vy[i]);
    o1 = h * vzp(e);
    p1 = h * zp(vz[i]);

    k2 = h * vxp(vy[i] + m1, b);
    l2 = h * xp(vx[i] + k1);
    m2 = h * vyp(vx[i] + k1, b);
    n2 = h * yp(vy[i] + m1);
    o2 = h * vzp(e);
    p2 = h * zp(vz[i] + o1);

    vx[i + 1] = vx[i] + (k1 + k2) / 2;
    x[i + 1] = x[i] + (l1 + l2) / 2;
    vy[i + 1] = vy[i] + (m1 + m2) / 2;
    y[i + 1] = y[i] + (n1 + n2) / 2;
    vz[i + 1] = vz[i] + (o1 + o2) / 2;
    z[i + 1] = z[i] + (p1 + p2) / 2;
}

int main(void) {
    double t0 = 0.0;
    double x0 = 0.1;
    double vx0 = 0.0;
    double y0 = 0.0;
    double vy0 = 0.1;
    double z0 = 0.0;
    double vz0 = 0.0;
    double t[STEPS + 1];
    double x[STEPS + 1], vx[STEPS + 1];
    double y[STEPS + 1], vy[STEPS + 1];
    double z[STEPS + 1], vz[STEPS + 1];
    t[0] = t0;
    x[0] = x0;
    vx[0] = vx0;
    y[0] = y0;
    vy[0] = vy0;
    z[0] = z0;
    vz[0] = vz0;
    double h = 0.1; // 0.1より小さいと誤差が少なくていい
    double b = 0.5;
    double e = 1.0;
    int i;

    puts("ローレンツ力の計算を行います。");
    for (i = 0; i < STEPS; i++) {
        Lorentz2(t, x, vx, y, vy, z, vz, h, b, e, i);
        printf("i=%d, t=%lf, x=%lf, vx=%lf, y=%lf, vy=%lf, z=%lf, vz=%lf\n", i, t[i], x[i], vx[i], y[i], vy[i], z[i], vz[i]);
    }

    return 0;
}