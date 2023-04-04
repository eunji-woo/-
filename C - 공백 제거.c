#include <stdio.h>
#include <string.h>

int main(void) {
	char text[100];
	int i;

	printf("원하는 문자를 입력하세요: ");
	gets_s(text, 100);

    printf("공백이 제거된 텍스트:");

    for (i = 0; text[i]; i++) {
        if (text[i] == ' ' && text[i + 1] == ' ') {
            continue;
        }
        printf("%c", text[i]);
    }

    printf("\n");

    return 0;
}