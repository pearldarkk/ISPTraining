#include <stdio.h>

int Max(int x, int y)
{
    int r;
    r = x - ((x- y) & ((x - y) >> (sizeof(int)*8 - 1)));
    return r;
}

int Min(int x, int y)
{
    int r;
    r = y + ((x - y) & ((x - y) >> (sizeof(int)*8 - 1)));
    return r;
}
int main()
{
    int a, b, c;
    int max, min;
    scanf("%d%d%d", &a, &b, &c);
    max = Max(a,b);
    max = Max(max,c);

    min = Min(a,b);
    min = Min(min,c);
    printf("So lon nhat: %d \nSo nho nhat: %d", max, min);

    return 0;
}
