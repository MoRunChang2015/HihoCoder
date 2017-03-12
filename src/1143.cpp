#include <iostream>
const int MOD = 19999997;

void multi(long long a[], long long b[]) {
    long long temp[5];
    temp[1] = (a[1] * b[1] % MOD + a[2] * b[3] % MOD) % MOD;
    temp[2] = (a[1] * b[2] % MOD + a[2] * b[4] % MOD) % MOD;
    temp[3] = (a[3] * b[1] % MOD + a[4] * b[3] % MOD) % MOD;
    temp[4] = (a[3] * b[2] % MOD + a[4] * b[4] % MOD) % MOD;
    a[1] = temp[1];
    a[2] = temp[2];
    a[3] = temp[3];
    a[4] = temp[4];
}

void multi_itself(long long a[]) {
    long long temp[5];
    temp[1] = (a[1] * a[1] % MOD + a[2] * a[3] % MOD) % MOD;
    temp[2] = (a[1] * a[2] % MOD + a[2] * a[4] % MOD) % MOD;
    temp[3] = (a[3] * a[1] % MOD + a[4] * a[3] % MOD) % MOD;
    temp[4] = (a[3] * a[2] % MOD + a[4] * a[4] % MOD) % MOD;
    a[1] = temp[1];
    a[2] = temp[2];
    a[3] = temp[3];
    a[4] = temp[4];
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    if (n <= 2) {
        std::cout << n << std::endl;
        return 0;
    }
    --n;
    --n;
    long long matrix[5] = {0, 1, 0, 0, 1};
    long long t_matrix[5] = {0, 0, 1, 1, 1};
    int t = 1;
    while (t <= n) {
        if ((t & n) != 0)
            multi(matrix, t_matrix);
        t <<= 1;
        multi_itself(t_matrix);
    }
    std::cout << (matrix[2] + matrix[4] * 2 % MOD) % MOD << std::endl;
    return 0;
}
