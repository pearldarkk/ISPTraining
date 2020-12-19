#include <bits/stdc++.h>
using namespace std;

bool check(char *a)
{
    if (a[0] == a[strlen(a) - 1])
        return true;
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);

    char s[10];
    while (t--)
    {
        scanf("%s", s);
        if (check(s))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}