/**
 * @author: XiaFan
 * @date: 05-31 22:35
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] % 2 == 1) {
                odd++;
            } else {
                even++;
            }
        }
        cout << min(odd, even) << "\n";
    }

    return 0;
}