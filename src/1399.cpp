#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int a[1000005] = {0};
    int n, i, cnt = 0, t = 0;;
    long long x;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        t = (x % 2);
        if (cnt != 0) {
            if (t ^ a[cnt] == 1)
                cnt--;
            else {
                cnt++;
                a[cnt] = t;
            }
        } else {
            cnt++;
            a[cnt] = t;
        }
    }
    cout << cnt << endl;
    return 0;
}
