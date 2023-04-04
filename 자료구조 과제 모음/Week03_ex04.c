#include <stdio.h>

int gcd(int a, int b)
{
	if (a > b) {
		if (b == 0) return a;
		else return gcd(a % b, b);
	}
	else {
		if (a == 0) return b;
		else return gcd(a, b % a);
	}

}
int main(void)
{
	int a, b, gcd_result;
	printf("두 개의 수를 입력하시오(a b): ");
	scanf_s("%d %d", &a, &b);

	gcd_result = gcd(a, b);
	printf("%d", gcd_result);

	return 0;
}
