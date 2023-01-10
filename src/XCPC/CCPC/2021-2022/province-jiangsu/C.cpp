/**
 * @author: XiaFan
 * @date: 05-28 23:57
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct Timer {
    chrono::time_point<std::chrono::high_resolution_clock> start, end;
    chrono::duration<float> duration;
    Timer() {
        start = chrono::high_resolution_clock::now();
    }
    ~Timer() {
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        cerr << "Timer took " << ms << "ms\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, p;
    cin >> n >> q >> p;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto get_max = [&](int level) -> i64 {
        int m = n / level;
        int k = p / level;
        vector<i64> b(m + 1);
        deque<int> record;
        for (int i = 1; i <= m; i++) {
            if (i <= k) {
                if (!record.empty()) {
                    b[i] = max(b[record.front()], 0LL) + a[i * level];
                } else {
                    b[i] = a[i * level];
                }
                while (!record.empty() && b[i] > b[record.back()]) {
                    record.pop_back();
                }
                record.push_back(i);
            } else {
                b[i] = b[record.front()] + a[i * level];
                while (!record.empty() && b[i] > b[record.back()]) {
                    record.pop_back();
                }
                if (!record.empty() && record.front() <= (i - k)) {
                    record.pop_front();
                }
                record.push_back(i);
            }
        }
        i64 mx = -1e12;
        for (int i = m; i >= 0 && i * level + p > n; i--) {
            mx = max(mx, b[i]);
        }
        return mx;
    };

    vector<i64> ans(n + 1);
    for (int i = 1; i <= n && i <= p; i++) {
        ans[i] = get_max(i);
    }

    while (q--) {
        int x;
        cin >> x;
        if (x <= p) {
            cout << ans[x] << "\n";
        } else {
            cout << "Noob\n";
        }
    }

    return 0;
}