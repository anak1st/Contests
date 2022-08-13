/**
 * @author: XiaFan
 * @date: 07-07 12:04
 **/
#include <iostream>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        if (n % 2 == 0) {
            cout << "8600\n";
        } else {
            cout << "ailyanlu\n";
        }
    }

    return 0;
}