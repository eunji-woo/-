#include <stdio.h>

int main(void)
{
	int divisor = 0;
	int number;	
	int i;				

	printf("숫자를 입력하세요 : ");
	scanf("%d", &number);

	for (i = 1; i < number; i++)
	{
		if (number % i == 0)		
			divisor += 1;
		
		if (divisor >= 2)
			break;
	}

	if (divisor == 1)
		printf("%d는 소수입니다.", number);
	
	else
		printf("%d는 소수가 아닙니다.", number);
	
	
	return 0;

}