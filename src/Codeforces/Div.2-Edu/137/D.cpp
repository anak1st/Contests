/**
 * @author: XiaFan
 * @date: 10-18 15:35
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

    if (s.find('0') == s.npos) {
        std::cout << s << "\n";
        return 0;
    }
    size_t first_1 = s.find('1');
    if (first_1 == s.npos) {
        std::cout << 0 << "\n";
        return 0;
    }
    s = s.substr(first_1);
    n = s.length();
    
    int p = s.find('0');
    std::string pre = s.substr(0, p);
    std::string suf = s.substr(p);
    int len = suf.size();

    std::string ans = suf;
    for (int i = 0; i < p; i++) {
        std::string tmp = suf;
        std::string sub = s.substr(i, len);
        for (int j = 0; j < len; j++) {
            tmp[j] = std::max(tmp[j], sub[j]);
        }
        ans = std::max(ans, tmp);
    }
    std::cout << pre + ans << "\n";
    
    return 0;
}