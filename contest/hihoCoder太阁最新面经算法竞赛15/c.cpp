#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct edge {
    int to, br;
} e[100050];
int f[100050];
int s[100050];
bool isUsed[100050];
int n, m;
int cnt;
void addEdge(int x, int y) {
    cnt++;
    e[cnt].to = y;
    e[cnt].br = f[x];
    f[x] = cnt;
}
int main() {
    int i, j, t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int x, y;
        cnt = 0;
        memset(f, 0, sizeof f);
        memset(s, 0, sizeof s);
        memset(isUsed, 0, sizeof isUsed);
        for (i = 1; i <= m; i++) {
            cin >> x >> y;
            addEdge(x, y);
            s[y]++;
        }
        bool flag = true;
        int k = 0;
        while (flag) {
            flag = false;
            for (i = 1; i <= n; i++)
                if (s[i] == 0 && isUsed[i] == false) {
                    j = f[i];
                    isUsed[i] = true;
                    k++;
                    flag = true;
                    while (j != 0) {
                        s[e[j].to]--;
                        j = e[j].br;
                    }
                }
        }
        if (k == n)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
