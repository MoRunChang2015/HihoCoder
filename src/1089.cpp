#include <algorithm>
#include <iostream>
using namespace std;
int map[102][102] = {0};
int main() {
    int i, j, k, x, y, z, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j) map[i][j] = -1;
    for (i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        if (map[x][y] == -1 || map[x][y] > z) {
            map[x][y] = map[y][x] = z;
        }
    }
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (i != j && i != k & j != k)
                    if (map[i][k] != -1 && map[k][j] != -1)
                        if (map[i][j] == -1)
                            map[i][j] = map[i][k] + map[k][j];
                        else
                            map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << map[i][j];
            if (j != n)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}
