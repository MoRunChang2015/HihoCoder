#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int f[100002] = { 0 };
int main() {
    cin >> n >> m;
    int i , j, c , v;
    for (j = 1; j <= n; j++) {
        cin >> c >> v;
        for (i = m; i >= c; i--) {
            f[i] = max(f[i], f[i - c] + v);
        }
    }
    cout << f[m] << endl;
    return 0;
}
