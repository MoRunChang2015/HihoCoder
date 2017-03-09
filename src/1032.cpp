#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int f[2000020] = {0};

int main() {
    int i, j, t, ans;
    string str, s;
    cin >> t;
    while (t--) {
        cin >> s;
        str.clear();
        str.resize(s.size() * 2 + 1);
        str[0] = ' ';
        for (int i = 0; i < s.size(); i++) {
            str[i * 2 + 1] = s[i];
            str[i * 2 + 2] = ' ';
        }
        f[0] = 1;
        int max_j = 0;
        int max = 0;
        ans = 3;
        for (int i = 1; i < str.length(); ++i) {
            f[i] = 0;
            if (max > i)
                f[i] = min(f[2 * max_j - i], f[max_j] + (max_j - i) * 2);
            int r = f[i] / 2;
            while (i - r - 1 >= 0 && i + r + 1 < str.length())
                if (str[i - r - 1] == str[i + r + 1])
                    ++r;
                else
                    break;
            f[i] = r * 2 + 1;
            if (max < i + (f[i] / 2)) {
                max = i + (f[i] / 2);
                max_j = i;
            }
            if (f[i] > ans) ans = f[i];
        }
        cout << ans / 2 << endl;
    }
    return 0;
}
