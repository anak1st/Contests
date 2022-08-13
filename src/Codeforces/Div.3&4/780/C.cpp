#include <bits/stdc++.h>

typedef long long i64;

void solve() {
    std::string s;
    std::cin >> s;

    int j = 0, remove = 0;
    std::map<char, int> mp;
    for(int i = 0; i < (int)s.length(); i++) {
        if(mp[s[i]] == 1) {
            remove += (j - 1);

            for(char c = 'a'; c <= 'z'; c++) {
                mp[c] = 0;
            }
            j = 0;
        } else {
            mp[s[i]] = 1;
            j++;
        }
    }

    remove += j;
    std::cout << remove << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}