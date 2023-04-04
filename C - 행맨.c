#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	srand((unsigned)time(NULL));

	char dic[10][100] = { "meet at midnight", "thanks god it is friday", "close the door", "enemy at the gate", "superman returns", "return of jedi", "phantom of the opera", "sex and the city", "lord of the rings", "fourth of july" };
	char answer[100]="_____";
	int i,k;
	char solution[100];
	char ch;
	strcpy(solution, dic[rand() % 10]);

	for (k = 0; solution[k] != NULL; k++) {
		if (solution[k] == ' ')
			answer[k] = ' ';
		else
			answer[k] = '_';
	}

	while (1) {

		printf("\n문자열을 입력하시오: %s \n", answer);
		printf("글자를 추측하시오: ");

		ch = getch();

		for (i = 0; solution[i] != NULL; i++) {

			if (solution[i] == ch)
				answer[i] = ch;
		}
		if (strcmp(solution, answer) == 0) break;
	}
	return 0;
}