#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<int> a, b;
int main() {
    int n, m, i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        if (n % i == 0) a.push_back(i);
    for (i = 1; i <= m; i++)
        if (m % i == 0) b.push_back(i);
    for (i = 0; i < a.size(); i++)
        for (j = 0; j < b.size(); j++)
            cout << a[i] << " " << b[j] << endl;
    return 0;
}
