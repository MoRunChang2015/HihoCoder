#include <iostream>
#include <algorithm>
using namespace std;
int p[1005] = {0};
int n, m, w, h;
int countPages(int size) {
    int lines = 0;
    int lettersPerLine = w / size;
    for (int i = 0; i <= n; i++) {
        lines += p[i] / lettersPerLine;
        if (p[i] % lettersPerLine != 0)
            lines++;
    }
    int linesPerPage = h / size;
    int pages = lines / linesPerPage;
    if (lines % linesPerPage != 0)
        pages++;
    return pages;
}
int main() {
    int i, j, t, l, r;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m >> w >> h;
        for (i = 1; i <= n; i++)
            cin >> p[i];
        l = 1;
        r = min(w, h) + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int pages = countPages(mid);
            if (pages <= m) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << endl;
    }
    return 0;
}
