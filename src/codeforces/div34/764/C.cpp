#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int book[64] = {0};
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            while(x > n) {
                x /= 2;  //
            }
            book[x]++;
        }
        bool flag = true;
        for(int i = n; i >= 1; i--) {
            if(book[i] == 0) {
                flag = false;
                break;
            }
            while(book[i] > 1) {
                book[i]--;
                book[i / 2]++;
            }
        }
        if(flag) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}