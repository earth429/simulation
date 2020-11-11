#include <stdio.h>
#include <math.h>

void func(double *S, double x)
{
    *S = 4 / (1 + x * x);
}

void integral(int n, double *ans)
{
    double a = 0;
    double b = 1.0;
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
}

int main(void)
{
    int n;
    double ans;
    double pi = 3.141592; // p164より

    puts("台形公式で数値積分しました。");

    for (n = 1; n <= 3; n++)
    {
        integral(n, &ans);
        printf("n=%dのときSnは%fです。", n, ans);
        printf("πとの誤差は%fです。\n", fabs(ans - pi)); // 誤差=|(計算結果) - (解析解)|
    }

    n = 8;
    integral(n,&ans);
    printf("n=%dのときSnは%fです。",n,ans);
    printf("πとの誤差は%fです。\n", fabs(ans - pi));

    n = 16;
    integral(n,&ans);
    printf("n=%dのときSnは%fです。",n,ans);
    printf("πとの誤差は%fです。\n", fabs(ans - pi));

    n = 32;
    integral(n,&ans);
    printf("n=%dのときSnは%fです。",n,ans);
    printf("πとの誤差は%fです。\n", fabs(ans - pi));

    n = 10000;
    integral(n, &ans);
    printf("n=%dのときSnは%fです。", n, ans);
    printf("πとの誤差は%fです。\n", fabs(ans - pi));

    return 0;
}
