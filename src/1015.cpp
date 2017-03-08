#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> next_pos;

int kmp(string& pattern, string& str) {
    int ans = 0;
    next_pos[0] = -1;
    int i, j = 0, k = -1;
    while (j < pattern.size() ) {
        if (k == -1 || pattern[j] == pattern[k]) {
            j++;
            k++;
            next_pos[j] = k;
        } else {
            k = next_pos[k];
        }
    }

    i = 0; j = 0;
    while (i < str.size()) {
        if (j == -1 || pattern[j] == str[i]) {
            i++;
            j++;
        } else {
            j = next_pos[j];
        }
        if (j == pattern.size()) {
            //j = next_pos[j - 1] + 1;
            ans++;
        }
    }
    return ans;
}

int main() {
    int t;
    string str, pattern;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> pattern;
        cin >> str;
        next_pos.clear();
        next_pos.resize(pattern.size() + 1);
        cout << kmp(pattern, str) << endl;
    }
    return 0;
}
