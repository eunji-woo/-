#include <stdio.h>

int sub(int n) {
    int result = 0;
    for (int i = n; i > 0; (i -= 3))
        result += i;
    return result;
}

int main()
{
    int a;
    a = sub(10);
    printf("%d", a);

    return 0;
}
