/**
 * @author: XiaFan
 * @date: 2023-04-20 23:14
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int k;
    std::cin >> k;
    std::string s;
    std::cin >> s;

    std::deque<int> dq;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            dq.push_back(1);
        } else {
            dq.push_back(2);
        }
    }

    auto work = [&](std::deque<int> t) -> std::deque<int> {
        while (!t.empty() && t[t.size() - 2] == 1 && t[t.size() - 1] == 2) {
            t.pop_back();
            t.pop_back();
        }
        return t;
    };

    int left = 0;
    while (!dq.empty() && k > 0) {
        dq = work(dq);
        if (dq.empty()) {
            break;
        }
        k--;
        if (dq[left + 1] == 2) {
            dq.pop_front();
        } else {
            dq.pop_back();
        }
        dq.pop_back();
    }
    
    int n = dq.size();
    for (int i = 0; i < n; i++) {
        if (dq[i] == 1) {
            std::cerr << "(";
        } else {
            std::cerr << ")";
        }
    }
    std::cerr << "\n";
    int ans = 0;
    for (int i = n - 1, j = 0; i >= 0; i--) {
        if (dq[i] == 2) {
            ans += j;
            j++;
        } else {
            j--;
        }
    }

    std::cout << ans << "\n";
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