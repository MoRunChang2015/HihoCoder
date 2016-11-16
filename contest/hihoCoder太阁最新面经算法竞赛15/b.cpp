#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
vector<string> s;
bool cmp(const string a, const string b) {
    int i = 0, j = 0;
    while (i < a.length() && (a[i] < '0' || a[i] > '9')) i++;
    while (j < b.length() && (b[j] < '0' || b[j] > '9')) j++;
    string as = a.substr(0, i);
    string bs = b.substr(0, j);
    if (as != bs) return as < bs;
    if (i == a.length()) return true;
    if (j == b.length()) return false;
    string an = a.substr(i, a.length() - i);
    string bn = b.substr(j, b.length() - j);
    stringstream ss;
    ss << an;
    int aint, bint;
    ss >> aint;
    ss.clear();
    ss << bn;
    ss >> bint;
    return aint < bint;
}
int main() {
    ios::sync_with_stdio(false);
    int i, j, n;
    string temp;
    cin >> n;
    for (i = 0; i <= n - 1; i++) {
        cin >> temp;
        s.push_back(temp);
        // cout << s[i] << endl;
    }
    sort(s.begin(), s.end(), cmp);
    for (i = 0; i <= n - 1; i++) cout << s[i] << endl;
    return 0;
}
