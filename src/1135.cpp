#include <iostream>
#include <string>

int x, y, z;

bool check(int a, int b, int c) {
    return abs(a - b) == x && abs(b - c) == y && abs(a - c) == z;
}

int main() {
    int i, j, r_ball, b_ball, y_ball, total, ans;
    std::ios::sync_with_stdio(false);

    std::cin >> x >> y >> z;
    std::string str;
    std::cin >> str;
    ans = 0;
    r_ball = b_ball = y_ball = total = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'R') ++r_ball;
        if (str[i] == 'B') ++b_ball;
        if (str[i] == 'Y') ++y_ball;
        ++total;
        if (total > ans) ans = total;
        if (check(r_ball, b_ball, y_ball) || check(r_ball, y_ball, b_ball) ||
            check(b_ball, r_ball, y_ball) || check(b_ball, y_ball, r_ball) ||
            check(y_ball, b_ball, r_ball) || check(y_ball, r_ball, b_ball))
            r_ball = b_ball = y_ball = total = 0;
    }
    std::cout << ans << std::endl;
    return 0;
}
