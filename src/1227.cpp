#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

double point[102][3];

double distance(int x, int y) {
    double disx = point[x][0] - point[y][0];
    double disy = point[x][1] - point[y][1];
    return sqrt(disx * disx + disy * disy);
}

int count_point(int m, int center, int dis) {
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (dis > distance(center, i)) ans++;
        if (dis == distance(center, i)) return -1;
    }
    return ans;
}

int solve(int m, int n) {
    int ans = -1;
    int longest = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++) {
            longest = max(longest, static_cast<int>(floor(distance(i, j))) + 1);
        }
    for (int center = 1; center <= m; center++) {
        int l = 1;
        int r = longest + 1;
        while (l + 1 <= r) {
            int mid = (l + r) / 2;
            int inside_the_circle = count_point(m, center, mid);
            if (inside_the_circle == n)
                if (ans == -1 || ans > mid) ans = mid;
            if (inside_the_circle >= n)
                r = mid;
            else
                l = mid + 1;
        }
    }
    return ans;
}

int main() {
    int t, n, m;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> m >> n;
        for (int i = 1; i <= m; i++) cin >> point[i][0] >> point[i][1];
        cout << solve(m, n) << endl;
    }
    return 0;
}
