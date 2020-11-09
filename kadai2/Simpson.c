#include <stdio.h>
#include <math.h>

void func(double *S, double x)
{
    *S = 4 / (1 + (x * x));
}

void Trapezoidal(int n, double *ans)
{
    double a = 0;
    double b = 1.0;
    double fa, fb, fs;
    func(&fa, a);
    func(&fb, b);
    double siguma = 0;
    double h = (b - a) / n;
    int i;

    for (i = 1; i <= n - 1; i++) {
        double xs = a + i * h;
        func(&fs, xs);
        siguma += fs;
    }

    *ans = h * (fa / 2 + siguma + fb / 2);
}

void Simpson(int n, double *ans)
{
    double a = 0;
    double b = 1.0;
    double h = (b - a) / n;
    double y0, y1, y2;
    double x0 = a;
    double x1 = x0 + h;
    double x2 = x1 + h;

    int i;
    for (i = 0; i < n / 2; i++) {
        func(&y0, x0);
        func(&y1, x1);
        func(&y2, x2);

        x0 = x2;
        x1 = x0 + h;
        x2 = x1 + h;

        *ans += (h / 3) * (y0 + (4 * y1) + y2);
    }   
    
}  

int main(void) {
    int n;
    double ans;
    double pi = 3.1415926535;

    int flag;

    printf("どちらで計算しますか(0:台形則,1:シンプソンの公式)：");
    scanf("%d", &flag);

    if (flag == 0) {
        printf("台形公式で数値積分しました。πの値は%fです。\n", pi);
    
        for (n = 1; n <= 8; n = n * 2) {
            ans = 0;
            Trapezoidal(n, &ans);
            printf("n=%dのときSnは%fです。", n, ans);
            printf("πとの誤差は%fです。\n", fabs(ans - pi)); // 誤差=|(計算結果) - (解析解)|
        }
    } else if (flag == 1) {
        printf("シンプソンの公式で数値積分しました。πの値は%fです。\n", pi);
    
        for (n = 2; n <= 8; n = n * 2) {
            ans = 0;
            Simpson(n, &ans);
            printf("n=%dのときSnは%fです。", n, ans);
            printf("πとの誤差は%fです。\n", fabs(ans - pi)); // 誤差=|(計算結果) - (解析解)|
        }
    } else {
        puts("入力した値が不正です。");
    }
    
    return 0;
}
