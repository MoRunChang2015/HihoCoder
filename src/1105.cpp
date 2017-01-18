#include <algorithm>
#include <cstdio>
#include <iostream>
int a[100020];
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int i, j, n, m;
    cin >> n;
    char c;
    m = 0;
    for (int k = 0; k < n; k++) {
        cin >> c;
        if (c == 'A') {
            int w;
            cin >> w;
            a[m] = w;
            m++;
            push_heap(a, a + m);
        } else {
            cout << a[0] << endl;
            pop_heap(a, a + m);
            m--;
        }
    }
    return 0;
}
