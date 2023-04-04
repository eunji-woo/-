#include <stdio.h>

int fib(int n) {
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;
    else return (fib(n - 1) + fib(n - 2));
}

int main(void) {
    int a;
    printf("양의 정수를 입력하시오: ");
    scanf_s("%d", &a);

    int fib_result = fib(a);
    printf("%d", fib_result);
    return 0;
}
