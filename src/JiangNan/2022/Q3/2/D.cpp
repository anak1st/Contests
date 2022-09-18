/**
 * @author: XiaFan
 * @date: 09-16 19:03
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string a, b;
    std::cin >> a >> b;
    if (a.length() != b.length()) {
        std::cout << "No";
        return 0;
    }

    std::vector<bool> c(26, false);
    c['a' - 'a'] = true;
    c['e' - 'a'] = true;
    c['i' - 'a'] = true;
    c['o' - 'a'] = true;
    c['u' - 'a'] = true;

    bool ok = true;

    for (int i = 0; i < int(a.length()); i++) {
        if (c[a[i] - 'a'] != c[b[i] - 'a']) {
            ok = false;
            break;
        }
    }

    if (ok) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }

    
    return 0;
}