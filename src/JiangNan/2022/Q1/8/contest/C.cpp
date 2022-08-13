#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

bool judge(int x) {
    int _x = x;
    int y = 0;
    while(_x) {
        y = y * 10 + _x % 10;
        _x /= 10;
    }
    return x == y;
}

void solve() {
    int x;
    cin >> x;
    int y = ceil(x * 0.2);
    int total = x + y;
    while(!judge(total)) {
        total++;
    }

    y = total - x;
    cout << "Input cost: " << x << "\n";
    cout << y << " " << total << "\n";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}