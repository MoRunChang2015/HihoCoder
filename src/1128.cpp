#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n, k;

int findIndex(int l, int r, int k) {
    if (l == r) {
        if (v[l] == k)
            return 1;
        else {
            cout << -1 << endl;
            exit(0);
        }
    }
    int mid = v[(l + r) / 2];
    int i, j;
    i = l;
    j = r;
    while (i <= j) {
        while (v[i] < mid) i++;
        while (v[j] > mid) j--;
        if (i <= j) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
    if (v[i] == mid)
        i++;
    if (mid == k) return i - l;
    if (mid > k)
        return findIndex(l, i - 1, k);
    else
        return findIndex(i, r, k) + i - l;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    v.clear();
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v.push_back(x);
    }
    cout << findIndex(0, n - 1, k) << endl;
    return 0;
}
