#include <iostream>

using namespace std;

int main() {
    int tot, ans;
    double n;
    double t, now;
    ios::sync_with_stdio(false);
    cin >> tot;
    while (tot--) {
        cin >> n;
        ans = 0;
        now = 0;
        t = 0.25;
        while (n >= now) {
            if (n == now) break;
            ans += 4;
            now += t;
            t /= 2;
        }
        if (n == now)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
