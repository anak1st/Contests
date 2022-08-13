#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::map<std::string, std::string> mp;

    std::string a, b, sline;
    while(std::getline(std::cin, sline)) {
        if(sline.length() == 0) break;
        std::istringstream newstream(sline);
        newstream >> b >> a;
        mp[a] = b;
    }

    while(std::cin >> b) {
        if(mp.count(b)) {
            std::cout << mp[b] << '\n';
        } else {
            std::cout << "eh\n";
        }
    }

    return 0;
}