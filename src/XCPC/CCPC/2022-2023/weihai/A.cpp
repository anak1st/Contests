/**
 * @author: XiaFan
 * @date: 11-07 12:57
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::set<std::string> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            std::string s;
            std::cin >> s;
            st.insert(s);
        }
    }

    int m;
    std::cin >> m;
    int c = 0;
    std::vector<int> a(5);
    for (int i = 0; i < m; i++) {
        std::string s;
        std::cin >> s;
        int x;
        std::cin >> x;
        x--;
        a[x]++;
        if (st.count(s)) {
            c++;
        }
    }

    int ans = c;
    
    for (int i = 0; i < 5; i++) {
        ans = std::min(ans, a[i]);
    }

    std::cout << ans;
    
    return 0;
}