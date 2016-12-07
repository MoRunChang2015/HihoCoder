#include <iostream>
using namespace std;
int a[1020];
int main() {
    int n, i;
    int ans = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1) {
        cout << a[1] << endl;
        return 0;
    }
    i = n;
    while (a[i - 1] < a[i] && i > 2) i--;
    i--;
    for (int j = 1; j < i; j++)
        cout << a[j] << " ";
    cout << a[i] << endl;
    return 0;
}
