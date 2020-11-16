#include <stdio.h>
#include <math.h>

#define DIV_NUM 32 // 分割数

void float_func(float *f, float x)
{
    *f = sin(x);
}

void float_Simpson(int n, float *ans, float a, float b, float h)
{
    float y0, y1, y2;
    float x0 = a;
    float x1 = x0 + h;
    float x2 = x1 + h;

    int i;
    for (i = 0; i < n / 2; i++) {
        float_func(&y0, x0);
        float_func(&y1, x1);
        float_func(&y2, x2);

        x0 = x2;
        x1 = x0 + h;
        x2 = x1 + h;

        *ans += h / 3 * (y0 + (4 * y1) + y2);
    }   
}

void double_func(double *f, double x)
{
    *f = sin(x);
}

void double_Simpson(int n, double *ans, double a, double b, double h)
{
    double y0, y1, y2;
    double x0 = a;
    double x1 = x0 + h;
    double x2 = x1 + h;

    int i;
    for (i = 0; i < n / 2; i++) {
        double_func(&y0, x0);
        double_func(&y1, x1);
        double_func(&y2, x2);

        x0 = x2;
        x1 = x0 + h;
        x2 = x1 + h;

        *ans += h / 3 * (y0 + (4 * y1) + y2);
    }   
}

int main(void) {
    int n;
    float float_ans;
    double double_ans;
    float float_true_value = 1.0;
    double double_true_value = 1.0;

    float float_a = 0;
    float float_b = M_PI / 2.0;
    float float_h;

    double double_a = 0;
    double double_b = M_PI / 2.0;
    double double_h;

    printf("シンプソンの公式で数値積分しました。真値は%fです。\n", double_true_value);

    puts("---float型---");
    for (n = 2; n <= DIV_NUM; n = n * 2) {
        float_h = (float_b - float_a) / n;
        float_ans = 0;
        float_Simpson(n, &float_ans, float_a, float_b, float_h);
        printf("n=%dのときSnは%.16lfです。", n, float_ans); // 小数点以下16
        printf("真値との誤差は%.16lfです。\n", fabs(float_ans - float_true_value)); // 誤差=|(計算結果) - (解析解)|
    }

    puts("---double型---");
    for (n = 2; n <= DIV_NUM; n = n * 2) {
        double_h = (double_b - double_a) / n;
        double_ans = 0;
        double_Simpson(n, &double_ans, double_a, double_b, double_h);
        printf("n=%dのときSnは%.16lfです。", n, double_ans); // 小数点以下16
        printf("真値との誤差は%.16lfです。\n", fabs(double_ans - double_true_value)); // 誤差=|(計算結果) - (解析解)|
    }

    return 0;
}
