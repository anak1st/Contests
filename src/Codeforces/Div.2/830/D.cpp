/**
 * @author: XiaFan
 * @date: 10-24 20:06
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::set<i64> st;
    st.insert(0);
    std::map<i64, i64> last;
    std::map<i64, std::set<i64>> del;
    std::map<i64, std::vector<i64>> change;
    while (n--) {
        char op;
        i64 x;
        std::cin >> op >> x;
        if (op == '+') {
            st.insert(x);
            for (i64 y : change[x]) {
                del[y].erase(x);
            }
            // std::cerr << op << "\n";
        } else if (op == '-') {
            st.erase(x);
            for (i64 y : change[x]) {
                del[y].insert(x);
            }
            // std::cerr << op << "\n";
        } else {
            if (!last.count(x)) {
                last[x] = x;
            }
            if (!del[x].empty()) {
                std::cout << *del[x].begin() << "\n";
                continue;
            }
            while (st.count(last[x])) {
                change[last[x]].push_back(x);
                last[x] += x;
            }
            std::cout << last[x] << "\n";
        }
    }

    return 0;
}