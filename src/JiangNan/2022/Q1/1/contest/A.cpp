#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    std::map<std::string, int> mp;
    while(T--) {
        std::string str;
        std::cin >> str;
        if(!mp.count(str)) {
            std::cout << "OK\n";
            mp[str] = 1;
        } else {
            std::cout << str << mp[str] << '\n';
            mp[str]++;
        }
    }

    return 0;
}