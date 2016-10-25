#include <algorithm>
#include <iostream>
using namespace std;

struct edge {
    int s, t, d;
} e[1000005];

int f[100005], r[100005];
int n, m;
int ans;

bool operator<(edge a, edge b) { return a.d < b.d; }

int initSet(int n) {
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        r[i] = 0;
    }
}

int getFather(int x) {
    if (f[x] == x)
        return x;
    else
        return f[x] = getFather(f[x]);
}

void unionSet(int x, int y) {
    x = getFather(x);
    y = getFather(y);
    if (x == y) return;
    if (r[x] > r[y]) {
        f[y] = x;
    } else {
        if (r[x] == r[y]) {
            r[y]++;
        }
        f[x] = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int i, j, x, y, z;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> e[i].s >> e[i].t >> e[i].d;
    }
    sort(e + 1, e + m);
    initSet(n);
    i = 1;
    ans = 0;
    for (int k = 1; k <= n - 1; k++) {
        while (getFather(e[i].s) == getFather(e[i].t)) i++;
        ans += e[i].d;
        unionSet(e[i].s, e[i].t);
        i++;
    }
    cout << ans << endl;
    return 0;
}
