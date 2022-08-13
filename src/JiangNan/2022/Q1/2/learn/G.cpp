#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> s;
    for(int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        s.emplace_back(l, -1);
        s.emplace_back(r, 1);
    }
    std::sort(s.begin(), s.end());
    int size = s.size();
    std::vector<std::pair<int, int>> ans;
    int start, end;
    for(int i = 0, pre = 0; i < size; i++) {
        if(pre == k - 1 && s[i].second == -1) {
            start = s[i].first;
        } else if(pre == k && s[i].second == 1) {
            end = s[i].first;
            ans.emplace_back(start, end);
        }
        // std::cerr << i << ':' << pre << '\n';
        pre -= s[i].second;
    }

    std::cout << ans.size() << '\n';
    for(auto [a, b] : ans) {
        std::cout << a << ' ' << b << '\n';
    }

    return 0;
}