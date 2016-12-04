#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = -1;

struct edge {
    int to, len, bro;
} e[1000020];

int f[100020] = {0};
int dis[100020] = {0};
int n, m, s, t, cnt;

void addEdge(int x, int y, int z) {
    cnt++;
    e[cnt].to = y;
    e[cnt].len = z;
    e[cnt].bro = f[x];
    f[x] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    cnt = 0;
    int i, j, x, y, z;
    for (i = 0; i < m; i++) {
        cin >> x >> y >> z;
        addEdge(x, y, z);
        addEdge(y, x, z);
    }

    for (i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        i = f[index];
        while (i != 0) {
            if (dis[index] + e[i].len < dis[e[i].to] || dis[e[i].to] == INF) {
                dis[e[i].to] = dis[index] + e[i].len;
                q.push(e[i].to);
            }
            i = e[i].bro;
        }
    }
    cout << dis[t] << endl;
    return 0;
}
