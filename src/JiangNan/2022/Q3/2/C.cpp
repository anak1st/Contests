/**
 * @author: XiaFan
 * @date: 09-16 19:29
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string a, b;
    std::cin >> a >> b;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int n = a.length();
    int na = (n + 1) / 2;
    int nb = n - na;
    a = a.substr(0, na);
    b = b.substr(na, nb);

    std::string s = std::string(n, '*');
    int last = s.size() - 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (!b.empty() && a.front() < b.back()) {
                s[i] = a.front();
                a.erase(a.begin());
            } else {
                s[last] = a.back();
                last--;
                a.erase(a.end() - 1);
            }
        } else {
            if (!a.empty() && a.front() < b.back()) {
                s[i] = b.back();
                b.erase(b.end() - 1);
            } else {
                s[last] = b.front();
                last--;
                b.erase(b.begin());
            }
        }
    }
    std::cout << s;
    
    return 0;
}