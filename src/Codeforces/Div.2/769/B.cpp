#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        int k = 1;
        while(2 * k < n) {
            k *= 2;
        }

        for(int i = k - 1; i >= 0; i--) {
            cout << i << ' ';
        }
        for(int i = k; i <= n - 1; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}