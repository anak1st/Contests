/**
 * @author: XiaFan
 * @date: 10-15 00:01
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s = "123.456";
    if (s.find('.') != s.npos) {
        std::cout << std::boolalpha << true << "\n";
    }
    
    return 0;
}