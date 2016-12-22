#include <cstring>
#include <iostream>
using namespace std;
struct point {
    int x, y;
};

point l[5][2];
bool isUsed[5];

bool operator==(const point& a, const point& b) {
    if (a.x == b.x && a.y == b.y)
        return true;
    else
        return false;
}

istream& operator>>(istream& in, point& a) {
    in >> a.x >> a.y;
    return in;
}

bool isVertical(int a, int b) {
    point tempa, tempb;
    tempa.x = l[a][0].x - l[a][1].x;
    tempa.y = l[a][0].y - l[a][1].y;
    tempb.x = l[b][0].x - l[b][1].x;
    tempb.y = l[b][0].y - l[b][1].y;
    return (tempa.x * tempb.x + tempa.y * tempb.y) == 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(isUsed, 0, sizeof isUsed);
        for (int i = 1; i <= 4; i++) cin >> l[i][0] >> l[i][1];
        point now;
        point next = l[1][1];
        int line = 1;
        int nextLine = 1;
        isUsed[1] = true;
        bool flag = true;
        for (int i = 1; i <= 3; i++) {
            now = next;
            line = nextLine;
            for (int j = 1; j <= 4; j++)
                if (!isUsed[j]) {
                    if (l[j][0] == now && isVertical(line, j)) {
                        next = l[j][1];
                        isUsed[j] = true;
                        nextLine = j;
                        break;
                    } else if (l[j][1] == now && isVertical(line, j)) {
                        next = l[j][0];
                        isUsed[j] = true;
                        nextLine = j;
                        break;
                    }
                }
            if (next == now) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
