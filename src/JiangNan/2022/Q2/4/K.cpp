/**
 * @author: XiaFan
 * @date: 07-07 12:13
 **/
#include <iostream>
#include <vector>

using namespace std;
typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n, x = 0;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            x ^= a[i];
        }
        if (x == 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (int i = 0; i < n; i++) {
                int y = x ^ a[i];
                if (y <= a[i]) {
                    cout << a[i] << " " << y << "\n";
                }
            }
        }
    }

    return 0;
}