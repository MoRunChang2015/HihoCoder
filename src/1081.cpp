#include <iostream>
#include <cstring>
using namespace std;
#define MAX_NUM 1000000000
struct edge {
    int to, d, br;
} e[10050];
int v[1050] = { 0 };
int dist[1050] = { 0 };
int n, m, s, t;
int num = 0;
void addEdge(int x, int y, int z) {
    num++;
    e[num].to = y;
    e[num].d = z;
    e[num].br = v[x];
    v[x] = num;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    int x, y, z;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        addEdge(x, y, z);
        addEdge(y, x, z);
    }

    bool isUsed[1050];
    for (int i = 1; i <= n; i++) {
        dist[i] = MAX_NUM;
        isUsed[i] = false;
    }
    isUsed[s] = true;
    dist[s] = 0;
    int i, j;
    i = v[s];
    while (i != 0) {
        if (dist[e[i].to] == MAX_NUM || dist[e[i].to] > e[i].d)
            dist[e[i].to] = e[i].d;
        i = e[i].br;
    }
    for (int k = 1; k <= n - 1; k++) {
        int min, p;
        min = MAX_NUM;
        p = -1;
        for (i = 1; i <= n; i++) {
            if (dist[i] != MAX_NUM && min > dist[i] && isUsed[i] == false) {
                min = dist[i];
                p = i;
            }
        }
        if (p == -1)
            break;
        isUsed[p] = true;
        i = v[p];
        while (i != 0) {
            if (dist[e[i].to] == MAX_NUM || e[i].d + dist[p] < dist[e[i].to])
                dist[e[i].to] = dist[p] + e[i].d;
            i = e[i].br;
        }
    }
    cout << dist[t] << endl;
    return 0;
}
