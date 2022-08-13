/**
 * @author: XiaFan
 * @date: 2022-04-16 16:55:04
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::string> s(n), t(n);
    std::map<std::string, int> v;
    for(int i = 0; i < n; i++) {
        std::cin >> s[i] >> t[i];
        v[s[i]]++, v[t[i]]++;
    }

    for(int i = 0; i < n; i++) {
        v[s[i]]--, v[t[i]]--;

        if(v[s[i]] > 0 && v[t[i]] > 0) {
            std::cout << "No\n";
            return 0;
        }

        v[s[i]]++, v[t[i]]++;
    }

    std::cout << "Yes\n";
    return 0;
}