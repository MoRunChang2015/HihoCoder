#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> name;
vector<int> f, r;

int getFather(int x) {
    if (f[x] == x)
        return x;
    else
        return f[x] = getFather(f[x]);
}

void unit(int x, int y) {
    int fx = getFather(x);
    int fy = getFather(y);
    if (fx == fy) return;
    if (r[fx] > r[fy]) {
        f[fy] = x;
    }
    if (r[fx] < r[fy]) {
        f[fx] = y;
    }
    if (r[fx] == r[fy]) {
        r[fx]++;
        f[fy] = x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t, id1, id2;
    string name1, name2, op;
    cin >> t;
    while (t--) {
        cin >> op >> name1 >> name2;
        id1 = -1;
        id2 = -1;
        for (int i = 0; i < name.size(); i++) {
            if (name[i] == name1) {
                id1 = i;
            } else if (name[i] == name2) {
                id2 = i;
            }
        }
        if (id1 == -1) {
            name.push_back(name1);
            f.push_back(name.size() - 1);
            r.push_back(0);
            id1 = name.size() - 1;
        }
        if (id2 == -1) {
            name.push_back(name2);
            f.push_back(name.size() - 1);
            r.push_back(0);
            id2 = name.size() - 1;
        }
        if (op == "0") {
            unit(id1, id2);
        } else {
            if (getFather(id1) == getFather(id2)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}
