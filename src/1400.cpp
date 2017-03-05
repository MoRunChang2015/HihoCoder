#include <iostream>
#include <map>
#include <string>
using namespace std;
int dp[100005][30];
map<int, string> rule;
int main() {
    int n, m, i, j;
    ios::sync_with_stdio(false);
    cin >> n;
    string str, temp;
    cin >> str;
    cin >> m;
    for (i = 1; i <= m; i++) {
        cin >> temp;
        rule[temp[0] - 'a'].push_back(temp[1]);
        rule[temp[1] - 'a'].push_back(temp[0]);
    }
    for (i = 0; i <= 25; i++) dp[0][i] = -1;
    for (i = 0; i < n; i++) {
        dp[i + 1][str[i] - 'a'] = i;
        for (j = 0; j < 26; j++) {
            if (j != str[i] - 'a') {
                dp[i + 1][j] = dp[i][j] == -1 ? -1 : dp[i][j] + 1;
            }
            if (dp[i][j] != -1) {
                if (rule[j].find(str[i]) == string::npos) {
                    if (dp[i + 1][str[i] - 'a'] > dp[i][j])
                        dp[i + 1][str[i] - 'a'] = dp[i][j];
                }
            }
        }
    }
    int ans = -1;
    for (i = 0; i < 26; i++)
        if (dp[n][i] != -1)
            if (ans == -1 || dp[n][i] < ans) ans = dp[n][i];
    cout << ans << endl;
    return 0;
}
