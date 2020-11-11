#include <stdio.h>
#include <math.h>

void func1(double *f, double y)
{
    *f = -0.5 * y;
}

void func2(double *f, double y1, double y2)
{
    *f = 4 - 0.3 * y2 - 0.1 * y1;
}

// Simultaneous ordinary differential equations(連立常微分方程式)
void SODE(double x0, double y1_0, double y2_0, double *x1, double *y1, double *y2, double h)
{
    double f1, f2;
    func1(&f1, y1_0);
    func2(&f2, y1_0, y2_0);

    *x1 = x0 + h;
    *y1 = y1_0 + f1 * h;
    *y2 = y2_0 + f2 * h;
}

int main(void) {
    double x[5];
    double y1[5];
    double y2[5];
    // 初期値設定
    x[0] = 0;
    y1[0] = 4;
    y2[0] = 6;
    // ステップ幅
    double h = 0.5;
    int i;

    puts("連立常微分方程式の計算を行います。");
    for (i = 0; i < 5;i++){
        SODE(x[i], y1[i], y2[i], &x[i + 1], &y1[i + 1], &y2[i + 1], h);
        printf("i=%d, x=%f, y1=%f, y2=%f\n", i, x[i], y1[i], y2[i]);
    }

    return 0;
}