#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t, n, m, i, j;
    int a[102];
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) cin >> a[i];
        a[0] = 0;
        a[n + 1] = 101;
        int len = min(n, m) + 1;
        int ans = 0;
        for (i = len; i <= n + 1; i++) {
            if (ans < a[i] - a[i - len]) ans = a[i] - a[i - len];
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
