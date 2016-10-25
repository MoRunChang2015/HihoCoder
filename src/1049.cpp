#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string first, mid;
void solve(int f, int m, int len) {
    if (len == 0) return;
    int index = 0;
    for (int i = 0; i < len; i++)
        if (mid[i + m] == first[f]) {
            index = i;
            break;
        }
    solve(f + 1, m, index);
    solve(f + index + 1, m + index + 1, len - index - 1);
    cout << first[f];
}
int main() {
    ios::sync_with_stdio(false);
    cin >> first;
    cin >> mid;
    int len = first.length();
    solve(0, 0, len);
    cout << endl;
    return 0;
}
