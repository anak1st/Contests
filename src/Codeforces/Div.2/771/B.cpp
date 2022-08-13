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
        int odd = 0, even = 0;
        bool happy = true;

        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if(x % 2 == 0) {
                if(even && x < even) { happy = false; }
                even = x;
            } else {
                if(odd && x < odd) { happy = false; }
                odd = x;
            }
        }

        cout << (happy ? "Yes" : "No") << '\n';
    }
    return 0;
}