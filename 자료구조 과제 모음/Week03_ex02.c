#include <stdio.h>

double power(double x, int n) {
    if (n == 0) return 1;
    return x * power(x, n - 1);
}

int main(void)
{
    double a, power_result;
    int b;

    printf("x�� n���� ���, x�� n�� �Է��Ͻÿ�: ");
    scanf_s("%lf %d", &a, &b);

    power_result = power(a, b);
    printf("%lf", power_result);

    return 0;
}


