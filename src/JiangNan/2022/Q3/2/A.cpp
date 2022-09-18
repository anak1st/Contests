/**
 * @author: XiaFan
 * @date: 09-16 19:18
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    if (s.length() == 2) {
        if (s[0] == s[1]) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    } else {
        if (s.front() == 'A' && s.back() == 'B') {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }

    return 0;
}