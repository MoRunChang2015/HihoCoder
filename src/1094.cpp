#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

char map[202][202];
char target[5][4][4];
int n, m;

void getAllPossibleTarget() {
    int i, j;
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3; j++) {
            target[2][i][j] = target[1][j][4 - i];
        }
    }

    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++) {
            target[3][i][j] = target[1][4 - i][4 - j];
        }

    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++) {
            target[4][i][j] = target[1][4 - j][i];
        }
}

int main() {
    int i, j;
    char c;
    cin >> n >> m;
    getchar();
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            c = getchar();
            map[i][j] = c;
        }
        getchar();
    }

    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3; j++) {
            c = getchar();
            target[1][i][j] = c;
        }
        getchar();
    }

    getAllPossibleTarget();

    for (i = 1; i <= n - 2; i++)
        for (j = 1; j <= m - 2; j++) {
            bool flag = false;
            for (int k = 1; k <= 4; k++) {
                flag = true;
                for (int x = 1; x <= 3; x++) {
                    for (int y = 1; y <= 3; y++) {
                        if (map[i + x - 1][j + y - 1] != target[k][x][y])
                            flag = false;
                    }
                    if (flag == false) break;
                }
                if (flag) {
                    cout << i + 1 << " " << j + 1 << endl;
                    break;
                }
            }
        }
    return 0;
}
