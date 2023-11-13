/**
 * @author: XiaFan
 * @date: 2023-11-06 19:12
 */
#include <bits/stdc++.h>

using i64 = long long;


int main() {

    std::vector<std::pair<int, std::string>> a(13);

    for (auto &[x, s] : a) {
        std::cin >> s >> x;
    }

    std::cout << (*std::max_element(a.begin(), a.end())).second << '\n';

    return 0;
}