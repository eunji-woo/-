#include <stdio.h>

int main(void)
{
	int divisor = 0;
	int number;	
	int i;				

	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &number);

	for (i = 1; i < number; i++)
	{
		if (number % i == 0)		
			divisor += 1;
		
		if (divisor >= 2)
			break;
	}

	if (divisor == 1)
		printf("%d�� �Ҽ��Դϴ�.", number);
	
	else
		printf("%d�� �Ҽ��� �ƴմϴ�.", number);
	
	
	return 0;

}