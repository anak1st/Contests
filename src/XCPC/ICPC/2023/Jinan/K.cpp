/**
 * @author: XiaFan
 * @date: 2024-01-21 13:01
 */
#include <bits/stdc++.h>

using i64 = long long;

struct Seq {
    i64 sum1, sum2;
    i64 len1, len2;
    std::multiset<i64> s1, s2;

    Seq() : sum1(0), sum2(0), len1(0), len2(0) {}

    // s1.size() = s2.size() or s1.size() = s2.size() + 1
    void balance() {
        while (s1.size() > s2.size() + 1) {
            s2.insert(*s1.rbegin());
            sum2 += *s1.rbegin();
            sum1 -= *s1.rbegin();
            s1.erase(s1.find(*s1.rbegin()));
            len2 += 1;
            len1 -= 1;
        }
        while (s1.size() < s2.size()) {
            s1.insert(*s2.begin());
            sum1 += *s2.begin();
            sum2 -= *s2.begin();
            s2.erase(s2.begin());
            len1 += 1;
            len2 -= 1;
        }
    }

    void insert(int x) {
        if (s1.empty() || x <= get_middle()) {
            s1.insert(x);
            sum1 += x;
            len1++;
        } else {
            s2.insert(x);
            sum2 += x;
            len2++;
        }
        balance();
    }

    void remove(int x) {
        if (x <= get_middle()) {
            sum1 -= x;
            len1--;
            s1.erase(s1.find(x));
        } else {
            sum2 -= x;
            len2--;
            s2.erase(s2.find(x));
        }
        balance();
    }

    int get_middle() const {
        return *s1.rbegin();
    }

    i64 get_k() {
        i64 k = std::abs(1LL * len1 * get_middle() - sum1) + std::abs(1LL * len2 * get_middle() - sum2);
        // for (int x : s1) {
        //     std::cerr << x << " ";
        // }
        // std::cerr << "| ";
        // for (int x : s2) {
        //     std::cerr << x << " ";
        // }
        // std::cerr << "| ";
        // std::cerr << "len: " << len1 << ", " << len2 << " ";
        // std::cerr << "sum: " << sum1 << ", " << sum2 << " ";
        // std::cerr << "k: " << k << "\n";
        return k;
    }
};

void solve() {
    i64 n;
    i64 k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] -= i;
    }

    // std::cerr << "a: ";
    // for (int i = 0; i < n; i++) {
    //     std::cerr << a[i] << " \n"[i + 1 == n];
    // }
    
    Seq seq;
    i64 ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n) {
            seq.insert(a[j]);
            j++;
            if (seq.get_k() <= k) {
                ans = std::max(ans, seq.len1 + seq.len2);
            } else {
                break;
            }
        }
        seq.remove(a[i]);
        // std::cerr << "finish i=" << i << "\n";
    }

    // std::cerr << "ans: " << ans << "\n";
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