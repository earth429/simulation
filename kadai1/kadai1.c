#include <stdio.h>
#include <math.h>

#define DIV_NUM 32768 // 分割数

void func(double *f, double x) {
    *f = 1 / cos(x);
}

/*void integral(int n, double *ans)
{
    double a = 0;
    double b = M_PI / 6;
    double fa, fb, fs;
    func(&fa, a);
    func(&fb, b);
    double siguma = 0;
    double h = (b - a) / n;
    int i;

    for (i = 1; i <= n - 1; i++)
    {
        double xs = a + i * h;
        func(&fs, xs);
        siguma += fs;
    }

    *ans = h * (fa / 2 + siguma + fb / 2);
}*/

// 台形公式
void Trapezoidal(int n, double *ans) {
    double a = 0;
    double b = M_PI / 6; // 0.52359877559
    double h = (b - a) / n;
    double x0, x1, y0, y1;
    x0 = a;
    x1 = x0 + h;

    int i;
    for (i = 0; i < n; i++) {
        func(&y0, x0);
        func(&y1, x1);

        x0 = x1;
        x1 = x0 + h;

        *ans += h / 2 * (y0 + y1);
    }
}

int main(void)
{
    int n;
    double ans;
    double kaisekikai = 0.549306144; // 1/2 loge 3

    printf("台形公式で数値積分しました。解析解の値は%.9lfです。\n", kaisekikai);
    
    /*n = 1;
    ans = 0;
    while(fabs(ans - kaisekikai) >= 0.0000000001) {
        ans = 0;
        Trapezoidal(n, &ans);
        printf("n=%dのときSnは%.9lfです。", n, ans);
        printf("解析解との誤差は%.9lfです。\n", fabs(ans - kaisekikai)); // 誤差=|(計算結果) - (解析解)|
        n = n * 2;
    }*/

    for (n = 1; n <= DIV_NUM; n = n * 2) {
        ans = 0;
        Trapezoidal(n, &ans);
        printf("n=%dのときSnは%.9lfです。", n, ans);
        printf("解析解との誤差は%.9lfです。\n", fabs(ans - kaisekikai)); // 誤差=|(計算結果) - (解析解)|
    }

    return 0;
}
