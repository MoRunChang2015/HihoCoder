#include <iostream>
using namespace std;
int main() {
    int t, ans, i, n;
    cin >> n;
    ans = 0;
    for (i = 1; i <= n; i++) {
        cin >> t;
        ans = (ans ^ t);
    }
    if (ans == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
    return 0;
}
