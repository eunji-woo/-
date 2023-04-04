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
	struct library book[30] = { "초기화" };
	FILE* fp;
	int choice, i, r = 0, a = 0;
	char search[30], c;

	fp = fopen("library.txt", "w");
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.\n"); 
		exit(1);
	}

	while (1) {
		printf("\n======================\n");
		printf("1.파일 쓰기\n");
		printf("2.추가\n");
		printf("3.출력\n");
		printf("4.검색\n");
		printf("5.파일 쓰기\n");
		printf("6.종료\n");
		printf("======================\n");

		printf("정수값을 입력하시오:");
		scanf("%d", &choice);

		if (choice == 1) {
			fread(book, 1, a+1, fp);
			printf("파일 오픈 성공!");

			continue;
		}

		else if (choice == 2) {
			printf("제목 : ");
			scanf("%s", book[a].title);
			printf("저자 : ");
			scanf("%s", book[a].author);
			printf("출판사 : ");
			scanf("%s", book[a].publisher);

			fprintf(fp, "%s %s %s", book[a].title, book[a].author, book[a].publisher);
			a++;
			continue;
		}

		else if (choice == 3) {
			for (i = 0; i < a ; i++) {
				printf("제목: %s\n", book[i].title);
				printf("저자: %s\n", book[i].author);
				printf("출판사: %s\n", book[i].publisher);
			}
			continue;
		}

		else if (choice == 4) {
			printf("제목 : ");
			scanf("%s", &search);
			while (1){
				if (strcmp(book[r].title, search) == 0) {
					printf("출판사는 %s\n", book[r].publisher);
					break;
				}
			}continue;
			}
			

		else if (choice == 5) {
			while ((c = fgetc(fp)) !=EOF)
				fputc(c, fp);
			printf("파일 오픈 성공!(2)");
			continue;
		}

		else
			break;
	}
	fclose(fp);
	return 0;
}










