#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct library
{
	char title[30];
	char author[30] ;
	char publisher[30];         
};


int main(void)
{
	struct library book[30] = { "�ʱ�ȭ" };
	FILE* fp;
	int choice, i, r = 0, a = 0;
	char search[30], c;

	fp = fopen("library.txt", "w");
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.\n"); 
		exit(1);
	}

	while (1) {
		printf("\n======================\n");
		printf("1.���� ����\n");
		printf("2.�߰�\n");
		printf("3.���\n");
		printf("4.�˻�\n");
		printf("5.���� ����\n");
		printf("6.����\n");
		printf("======================\n");

		printf("�������� �Է��Ͻÿ�:");
		scanf("%d", &choice);

		if (choice == 1) {
			fread(book, 1, a+1, fp);
			printf("���� ���� ����!");

			continue;
		}

		else if (choice == 2) {
			printf("���� : ");
			scanf("%s", book[a].title);
			printf("���� : ");
			scanf("%s", book[a].author);
			printf("���ǻ� : ");
			scanf("%s", book[a].publisher);

			fprintf(fp, "%s %s %s", book[a].title, book[a].author, book[a].publisher);
			a++;
			continue;
		}

		else if (choice == 3) {
			for (i = 0; i < a ; i++) {
				printf("����: %s\n", book[i].title);
				printf("����: %s\n", book[i].author);
				printf("���ǻ�: %s\n", book[i].publisher);
			}
			continue;
		}

		else if (choice == 4) {
			printf("���� : ");
			scanf("%s", &search);
			while (1){
				if (strcmp(book[r].title, search) == 0) {
					printf("���ǻ�� %s\n", book[r].publisher);
					break;
				}
			}continue;
			}
			

		else if (choice == 5) {
			while ((c = fgetc(fp)) !=EOF)
				fputc(c, fp);
			printf("���� ���� ����!(2)");
			continue;
		}

		else
			break;
	}
	fclose(fp);
	return 0;
}










