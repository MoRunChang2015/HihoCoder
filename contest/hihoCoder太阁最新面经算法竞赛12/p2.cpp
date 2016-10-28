#include <iostream>
#include <algorithm>
using namespace std;
int a[100005], b[100005];
int main() {
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    int l = 0;
    while (a[l] == b[l] && l < n) {
        l++;
    }
    int r = n;
    while (a[r] == b[r] && r >= l) {
        r--;
    }
    cout << r - l + 1 << endl;
    return 0;
}
