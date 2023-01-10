#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    for(auto &it : num) { cin >> it; }

    if(num[n - 2] > num[n - 1]) {
        cout << -1 << '\n';
        return;
    }

    if(is_sorted(num.begin(), num.end())) {
        cout << 0 << '\n';
        return;
    }

    if(num[n - 1] >= 0) {
        cout << n - 2 << '\n';
        for(int i = n - 2; i >= 1; i--) {
            cout << i << ' ';
            cout << i + 1 << ' ';
            cout << n << ' ';
            cout << '\n';
        }
        return;
    }

    cout << -1 << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Tests;
    cin >> Tests;
    while(Tests--) { solve(); }

    return 0;
}