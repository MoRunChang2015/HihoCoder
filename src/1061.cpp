#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int i, j, t;
    ios::sync_with_stdio(false);
    cin >> t;
    vector<pair<char, int>> v;
    while (t--) {
        v.clear();
        string s;
        int n;
        cin >> n;
        cin >> s;
        int cnt = 1;
        char last = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == last) {
                cnt++;
            } else {
                v.push_back({last, cnt});
                last = s[i];
                cnt = 1;
            }
        }
        v.push_back({last, cnt});
        bool flag = false;
        for (int i = 1; i < v.size() - 1; i++) {
            if (v[i - 1].first + 1 == v[i].first &&
                v[i].first + 1 == v[i + 1].first &&
                v[i - 1].second >= v[i].second &&
                v[i].second <= v[i + 1].second) {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
