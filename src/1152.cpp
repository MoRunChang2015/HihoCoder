#include <iostream>
#include <set>
#include <string>

using namespace std;

int fib[55] = {1, 1};

int fibonacci(int i) {
    if (fib[i] != 0)
        return fib[i];
    else
        return fib[i] = fibonacci(i - 1) + fibonacci(i - 2);
}

int main() {
    string str, temp;
    set<string> ans;
    set<char> s;
    cin >> str;
    for (int index = 0; index < str.length(); index++) {
        s.clear();
        int fibindex = 1;
        int i = index;
        temp = "";
        while (i < str.length()) {
            temp.push_back(str[i]);
            s.insert(str[i]);
            while (s.size() > fibonacci(fibindex)) fibindex++;
            if (s.size() == fibonacci(fibindex)) ans.insert(temp);
            i++;
        }
    }
    for (auto& word : ans) {
        cout << word << endl;
    }
    return 0;
}
