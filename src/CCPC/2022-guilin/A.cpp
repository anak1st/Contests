/**
 * @author: XiaFan
 * @date: 10-31 19:15
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
    for (int i = 0; i < n; i++) {
        bool ok = true;
        if (i > 0 && s[i - 1] == 'L') {
            ok = false;
        }
        if (i < n - 1 && s[i + 1] == 'L') {
            ok = false;
        }
        if (s[i] == '.' && ok) {
            s[i] = 'C';
        }
    }
    std::cout << s;
    
    return 0;
}