/**
 * @author: XiaFan
 * @date: 10-14 00:02
 **/
#include <bits/stdc++.h>
using i64 = long long;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::bitset<32> bit(1e9);
    std::cout << bit.to_string() << "\n";
    std::vector<int> a(10, 1);
    std::accumulate(a.begin(), a.end(), 0);
    
    return 0;
}