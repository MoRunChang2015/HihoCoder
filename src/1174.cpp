#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct {
    int to, b;
} e[500020];

int f[100020] = {0};
int in[100020] = {0};

int n, m, cnt;

void addEdge(int x, int y) {
    cnt++;
    e[cnt].to = y;
    e[cnt].b = f[x];
    f[x] = cnt;
    in[y]++;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(in, 0, sizeof in);
        memset(f, 0, sizeof f);
        cnt = 0;
        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            addEdge(x, y);
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (in[i] == 0) q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int i = f[x];
            while (i != 0) {
                --in[e[i].to];
                if (in[e[i].to] == 0) q.push(e[i].to);
                i = e[i].b;
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
            if (in[i] != 0) {
                flag = false;
                break;
            }
        if (flag)
            cout << "Correct" << endl;
        else
            cout << "Wrong" << endl;
    }
    return 0;
}
