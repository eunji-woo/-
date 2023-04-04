#include <stdio.h>

double power(double x, int n) {
    if (n == 0) return 1;
    return x * power(x, n - 1);
}

int main(void)
{
    double a, power_result;
    int b;

    printf("x의 n제곱 계산, x와 n을 입력하시오: ");
    scanf_s("%lf %d", &a, &b);

    power_result = power(a, b);
    printf("%lf", power_result);

    return 0;
}


