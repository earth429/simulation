#include <stdio.h>
#include <math.h>

void func1(double *v, double y_dash)
{
    *v = y_dash;
}

void func2(double *v_dash, double v, double y, double m, double k, double l)
{
    *v_dash = -l * y - k * v / m;
}

//  Higher-order differential equation(高階微分方程式)
void HODE(double m, double k, double l, double *y, double *y_dash, double *t, double h)
{
    double v_dash, v;

    func1(&v, *y_dash);
    func2(&v_dash, v, *y, m, k, l);
    *y = v;
    *y_dash = v_dash;
}

int main(void) {
    double m = 1;
    double k = 2;
    double l = 3;
    double y = 10;
    double y_dash = 0;
    double t = 0;
    double h = 0.1; // 0.1より小さいと誤差が少なくていい
    int i;

    puts("高階微分方程式の計算を行います。");
    for (i = 0; i < 5;i++){
        printf("i=%d, y=%f, y_dash=%f\n", i, y, y_dash);
        HODE(m, k, l, &y, &y_dash, &t, h);
        //printf("i=%d, x=%f, y1=%f, y2=%f\n", i, x[i], y1[i], y2[i]);
    }

    return 0;
}