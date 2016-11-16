#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char sCity[105][25];
char eCity[105][25];
char f[210][25];
int s[205];
int main() {
    int n, i, j;
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++)
        scanf("%s%s", sCity[i], eCity[i]);
    int m = 0;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++) {
            if (strcmp(f[j], sCity[i]) == 0) {
                s[j]++;
                break;
            }
        }
        if (j == m + 1) {
            m++;
            s[m] = 1;
            strcpy(f[m], sCity[i]);
        }
        for (j = 1; j <= m; j++) {
            if (strcmp(f[j], eCity[i]) == 0) {
                s[j]--;
                break;
            }
        }
        if (j == m + 1) {
            m++;
            s[m] = -1;
            strcpy(f[m], eCity[i]);
        }
    }
    for (i = 1; i <= m; i++)
        if (s[i] == 1)
            printf("%s ", f[i]);
    for (i = 1; i <= m; i++)
        if (s[i] == -1)
            printf("%s\n", f[i]);
    return 0;
}
