#include <iostream>
using namespace std;
int f[10020] = {0};
int main() {
    ios::sync_with_stdio(false);
    int i, n, m, x, y;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        f[x]++;
        f[y]++;
    }
    int temp = 0;
    for (i = 1; i <= n; i++)
        if (f[i] % 2 != 0)
            temp++;
    if (temp == 0 || temp == 2)
        cout << "Full" << endl;
    else
        cout << "Part" << endl;
    return 0;
}
