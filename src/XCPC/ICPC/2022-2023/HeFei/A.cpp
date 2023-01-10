/**
 * @author: XiaFan
 * @date: 11-20 12:30
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string S;
    std::cin >> S;

    int u = S.find('U');
    int s = S.find('S');
    int t = S.find('T');
    int c = S.find('C');
    int ans = (s - u - 1) + (t - s - 1) * 2 + (c - t - 1);
    std::cout << ans;
    
    return 0;
}