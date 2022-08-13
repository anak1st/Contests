#include <bits/stdc++.h>

typedef long long i64;

int main() {
    std::map<int, std::pair<int, int>> mp;
    int a[6] = {4, 8, 15, 16, 23, 42};
    for(int i = 0; i <= 5; i++) {
        for(int j = 0; j <= 5; j++) {
            mp[a[i] * a[j]] = {a[i], a[j]};
        }
    }

    int ans[4] = {32, 120, 368, 966};
    fflush(stdout);
    std::cout << "? 1 2\n";
    fflush(stdout);
    std::cin >> ans[0];
    fflush(stdout);
    std::cout << "? 2 3\n";
    fflush(stdout);
    std::cin >> ans[1];
    fflush(stdout);
    std::cout << "? 4 5\n";
    fflush(stdout);
    std::cin >> ans[2];
    fflush(stdout);
    std::cout << "? 5 6\n";
    fflush(stdout);
    std::cin >> ans[3];
    fflush(stdout);

    int out[6];
    std::set<int> st;
    auto [x1, y1] = mp[ans[0]];
    st.insert(x1);
    st.insert(y1);

    auto [x2, y2] = mp[ans[1]];
    if(st.count(x2)) {
        out[0] = x1 * y1 / x2;
        out[1] = x2;
        out[2] = x2 * y2 / x2;
    } else {
        out[0] = x1 * y1 / y2;
        out[1] = y2;
        out[2] = x2 * y2 / y2;
    }

    st.clear();
    auto [x3, y3] = mp[ans[2]];
    st.insert(x3);
    st.insert(y3);

    auto [x4, y4] = mp[ans[3]];
    if(st.count(x4)) {
        out[3] = x3 * y3 / x4;
        out[4] = x4;
        out[5] = x4 * y4 / x4;
    } else {
        out[3] = x3 * y3 / y4;
        out[4] = y4;
        out[5] = x4 * y4 / y4;
    }

    std::cout << "! ";
    for(int i = 0; i < 6; i++) {
        std::cout << out[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}