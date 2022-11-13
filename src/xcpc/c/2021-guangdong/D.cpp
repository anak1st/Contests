/**
 * @author: XiaFan
 * @date: 06-07 18:05
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;
    
    if(n <= 2) {
        cout << "1 1";
        return 0;
    }

    i64 a = 1, b = 1;
    while(true) {
        i64 c = a + b;
        if(c > n) {
            break;
        }
        a = b, b = c;
        // cerr << a << " " << b << "\n";
    }

    cout << a << " " << b;

    return 0;
}