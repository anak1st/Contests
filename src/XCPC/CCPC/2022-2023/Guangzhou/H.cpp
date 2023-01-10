/**
 * @author: XiaFan
 * @date: 11-15 20:14
 **/
#include <bits/stdc++.h>

using i64 = long long;

template<typename T>
void print(const T& val) {
    std::cerr << val << "\n";
}

template<typename T, typename... Args>
void print(const T& val, const Args&... args) {
    std::cerr << val << " ";
    print(args...);
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::set<int> st;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        st.insert(a[i]);
    }
    int end[2] = {1, 0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            while (st.count(end[j])) {
                end[j] += 2;
            }
            end[j] += 2;
            while (st.count(end[j])) {
                end[j] += 2;
            }
        }
    }

    // print(end[0], end[1]);
    if (end[0] > end[1]) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}