#include <stdio.h>
#include <string.h>

int main(void) {
	char text[100];
	int i;

	printf("���ϴ� ���ڸ� �Է��ϼ���: ");
	gets_s(text, 100);

    printf("������ ���ŵ� �ؽ�Ʈ:");

    for (i = 0; text[i]; i++) {
        if (text[i] == ' ' && text[i + 1] == ' ') {
            continue;
        }
        printf("%c", text[i]);
    }

    printf("\n");

    return 0;
}