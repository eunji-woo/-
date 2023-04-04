#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_LENGTH 100

typedef int element;
typedef struct {
	element array[MAX_LIST_LENGTH];
	int length;
} ArrayListType;

void error(char* message);
void init(ArrayListType* L);
int is_empty(ArrayListType* L);
int is_full(ArrayListType* L);
element get_entry(ArrayListType* L, int pos);
void print_list(ArrayListType* L);
void insert_last(ArrayListType* L, element item);
void insert(ArrayListType* L, int pos, element item);
element delete(ArrayListType* L, int pos);
int get_length(ArrayListType* L);
void clear(ArrayListType* L);

int main(void) {
	/*ArrayListType list;

	init(&list);
	insert(&list, 0, 10); print_list(&list);
	insert(&list, 0, 20); print_list(&list);
	insert(&list, 0, 30); print_list(&list);
	insert_last(&list, 40); print_list(&list);
	delete(&list, 0); print_list(&list);
	printf("%d\n", get_length(&list));
	clear(&list);
	print_list(&list); */

    ArrayListType *list;
	list = (ArrayListType*)malloc(sizeof(ArrayListType));
	if (list == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	init(&list);
	insert(&list, 0, 10);
	insert(&list, 0, 20);
	insert(&list, 0, 30); print_list(&list);

	free(list); 
	return 0;
}

void error(char* message)
{
	fprintf(stderr, "%s \n", message);
	exit(1);
}

void init(ArrayListType* L)
{
	L->length = 0;
}

int is_empty(ArrayListType* L)
{
	return L->length == 0;
}

int is_full(ArrayListType* L)
{
	return L->length == MAX_LIST_LENGTH;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->length)
		error("위치 오류");
	return L->array[pos];
}

void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->length; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(ArrayListType* L, element item)
{
	if (L->length >= MAX_LIST_LENGTH) {
		error("리스트 오버플로우");
	}
	L->array[L->length++] = item;
}

void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->length)) {
		for (int i = (L->length - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->length++;
	}
}

element delete(ArrayListType* L, int pos)
{
	element item;
	if (pos < 0 || pos >= L->length)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < L->length - 1; i++)
		L->array[i] = L->array[i + 1];
	L->length--;
	return item;
}

int get_length(ArrayListType* L) {
	int length = L->length;
	return length;
}

void clear(ArrayListType* L) {
	for (int i = 0; i < L->length; i++) 
		L->array[i] = NULL;
	L->length = 0;
}