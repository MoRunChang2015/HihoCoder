#include <iostream>
#include <algorithm>
using namespace std;
int dp[100010] = { 0 };
int v, w;
int main() {
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> w >> v;
        for (j = w; j <= m; j++)
            dp[j] = max(dp[j], dp[j - w] + v);
    }
    cout << dp[m] << endl;
    return 0;
}
