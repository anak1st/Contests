/**
 * @author: XiaFan
 * @date: 2023-10-18 15:37
 */
#include <bits/stdc++.h>

using i64 = long long;

std::string t = "SPR";

bool check(char a, char b) {
    int x = t.find(a);
    int y = t.find(b);
    return y == (x + 1) % 3;
}

void solve() {
    std::string s;
    std::cin >> s;

    std::deque<char> st;
    for (int i = 0; i < s.size(); i++) {
        while (!st.empty() && !check(st.back(), s[i])) {
            // std::cerr << st.back() << " " << s[i] << "\n";
            st.pop_back();
        }
        st.push_back(s[i]);
    }
    // std::cerr << "\n";
    std::cout << st.front() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}