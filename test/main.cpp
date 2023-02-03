/**
 * @author: XiaFan
 * @date: 2023-02-03 15:47
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    
    std::vector<std::string> a;
    for (int i = 1; i <= 19999; i++) {
        a.emplace_back(i, 'a' + i % 10);
    }
    std::cout << __cplusplus << "\n";

    return 0;
}