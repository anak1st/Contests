#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    set<i64> arr;
    arr.insert(0);
    i64 now = 0, ans = 0;
    while(T--) {
        i64 n;
        cin >> n;
        now += n;
        if(arr.count(now)) {
            ans++;
            arr.clear();
            arr.insert(0);
            now = n;
        }
        arr.insert(now);
    }
    cout << ans << endl;
    return 0;
}