#include <iostream>
#include <string>
using namespace std;

int eraseChars(string s, int tot) {
    int temp[100] = {0};
    int len = s.size();
    bool flag = true;
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            temp[i] = 1;
            flag = false;
            tot++;
            int j = i + 1;
            while (s[i] == s[j]) {
                temp[j] = 1;
                tot++;
                j++;
                if (j >= len) {
                    break;
                }
            }
            i = j - 1;
        }
    }
    if (!flag) {
        string ss = "";
        for (int i = 0; i < len; i++) {
            if (temp[i] == 0) ss += s[i];
        }
        return eraseChars(ss, tot);
    }
    return tot;
}

int main() {
    int t;
    string str;
    cin >> t;
    while (t--) {
        cin >> str;
        int len = str.size();
        int ans = -1;
        int newAns = 0;
        for (int i = 0; i < len + 1; i++) {
            if (i == len) {
                newAns = eraseChars(str + "A", 0);
                if (newAns > ans) ans = newAns;
                newAns = eraseChars(str + "B", 0);
                if (newAns > ans) ans = newAns;
                newAns = eraseChars(str + "C", 0);
                if (newAns > ans) ans = newAns;
            } else {
                newAns = eraseChars(str.substr(0, i) + "A" + str.substr(i), 0);
                if (newAns > ans) ans = newAns;
                newAns = eraseChars(str.substr(0, i) + "B" + str.substr(i), 0);
                if (newAns > ans) ans = newAns;
                newAns = eraseChars(str.substr(0, i) + "C" + str.substr(i), 0);
                if (newAns > ans) ans = newAns;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
