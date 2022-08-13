#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Tests;
    cin >> Tests;
    while(Tests--) {
        int n;
        cin >> n;
        int a = 0;
        for(int i = 1; i <= n; i++) {
            int b;
            cin >> b;
            a = a | b;
        }
        cout << a << '\n';
    }
    return 0;
}