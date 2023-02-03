/**
 * @author: XiaFan
 * @date: 2023-02-01 18:38
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    
    std::string a, b;
    for (auto c : s) {
        while (k > 0 && !a.empty() && a.back() < c) {
            k--;
            b.push_back(a.back());
            a.pop_back();
        }
        a.push_back(c);
    }
    while (k > 0 && !a.empty()) {
        k--;
        b.push_back(a.back());
        a.pop_back();
    }

    std::sort(b.begin(), b.end(), std::greater<char>());
    // std::cerr << a << " " << b << "\n";
    std::cout << a + b;

    return 0;
}