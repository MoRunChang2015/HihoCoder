#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[102], b[102], c[10052];
int main() {
    char aStr[105], bStr[105];
    scanf("%s %s", aStr, bStr);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    int i, j , k, la, lb, l;
    la = strlen(aStr);
    lb = strlen(bStr);
    for (int i = 0; i < strlen(aStr); i++)
        a[i + 1] = aStr[strlen(aStr) - i - 1] - '0';
    for (int i = 0; i < strlen(bStr); i++)
        b[i + 1] = bStr[strlen(bStr) - i - 1] - '0';


    int temp;
    for (i = 1; i <= la; i++)
        for (j = 1; j <= lb; j++) {
            temp = c[i + j - 1] + a[i] * b[j];
            c[i + j - 1] = temp % 10;
            c[i + j] = c[i + j] + temp / 10;
        }

    l = 10002;
    while (c[l] == 0 && l > 1)
        l--;
    for (i = l; i >= 1; i--)
        printf("%d", c[i]);
    printf("\n");
    return 0;
}
