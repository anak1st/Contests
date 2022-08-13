/**
 * @author: XiaFan
 * @date: 05-02 18:22
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

struct fair {
    int i, a, b;
    friend bool operator<(const fair &lhs, const fair &rhs) {
        return lhs.a > rhs.a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  // 0 -> nullptr

    int n;
    cin >> n;
    vector<fair> f(n);
    for(int i = 0; i < n; i++) {
        f[i].i = i + 1;
        cin >> f[i].a;
    }
    for(int i = 0; i < n; i++) {
        cin >> f[i].b;
    }
    sort(f.begin(), f.end());
    cout << n / 2 + 1 << "\n";
    cout << f[0].i << " ";
    for(int i = 1; i < n; i += 2) {
        if(i + 1 < n && f[i].b < f[i + 1].b) {
            cout << f[i + 1].i << " ";
        } else {
            cout << f[i].i << " ";
        }
    }
    return 0;
}