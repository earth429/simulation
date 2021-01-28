#include <stdio.h>
#include <math.h>

#define L 70

double f1(double y1, double y2, double a, double c){
    return a * y1 - c * y1 * y2;
}
double f2(double y1, double y2, double b, double d){
    return -b * y2 + d * y1 * y2;
}

// nは配列サイズ
void Euler(double h, double x0, double y01, double y02,double x[], double y1[],double y2[], double a, double b, double c, double d, int n) {
    int i;
    x[0] = x0;
    y1[0] = y01;
    y2[0] = y02;
    for (i = 1; i < n; i++) {
        x[i] = x[i - 1] + h;
        y1[i] = y1[i - 1] + h * f1(y1[i - 1], y2[i - 1], a, c);
        y2[i] = y2[i - 1] + h * f2(y1[i - 1], y2[i - 1], b, d);
    }
}

int main(void) {
    int i;
    double h = 0.1;
    double x[L];
    double y1[L];
    double y2[L];
    //y1 = 2, y2 = 2
    // a = 1, b = 1, c = 1, d = 1
    //y2 > a / c, y1 > b / d

    //y1 = 2, y2 = 2
    // a = 1, b = 3, c = 1, d = 1
    //y2 > a / c, y1 < b / d
    
    //y1 = 2, y2 = 2
    // a = 3, b = 1, c = 1, d = s1
    //y2 < a / c, y1 > b / d

    //y1 = 2, y2 = 2
    // a = 3, b = 3, c = 1, d = 1
    //y2 < a / c, y1 < b / d
    Euler(h, 0.0, 2, 2, x, y1, y2, 3, 3, 1, 1, L);
    printf("x,y1,y2\n");
    for (i = 0; i < L; i++) {
        printf("%.10lf,%.10lf,%.10lf\n", x[i], y1[i], y2[i]);
    }
    return 0;
}