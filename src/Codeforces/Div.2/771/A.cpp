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
        vector<int> num(n + 1);
        int l, r;
        bool start = false;
        for(int i = 1; i <= n; i++) {
            cin >> num[i];
            if(!start && num[i] != i) {
                start = true;
                l = i;
            }
            if(start && num[i] == l) { r = i; }
        }
        if(start) {
            for(int i = 1; i <= l - 1; i++) { cout << num[i] << ' '; }
            for(int i = r; i >= l; i--) { cout << num[i] << ' '; }
            for(int i = r + 1; i <= n; i++) { cout << num[i] << ' '; }
        } else {
            for(int i = 1; i <= n; i++) { cout << num[i] << ' '; }
        }
        cout << '\n';
    }
    return 0;
}