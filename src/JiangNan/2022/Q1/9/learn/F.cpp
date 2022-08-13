/**
 * @author: XiaFan
 * @date: 05-03 21:38
 **/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    // 23, 28, 33
    // 5544
    // 14421
    // 1288
    /*
    for (int i = 1; true; i++) {
        int num = i * 28 * 33;
        if (num % 23 == 1) {
            cout << num << "\n";
            break;
        }
    }
    for (int i = 1; true; i++) {
        int num = i * 23 * 33;
        if (num % 28 == 1) {
            cout << num << "\n";
            break;
        }
    }
    for (int i = 1; true; i++) {
        int num = i * 23 * 28;
        if (num % 33 == 1) {
            cout << num << "\n";
            break;
        }
    }
    */
    for (int i = 1; true; i++) {
        i64 a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == -1) {
            break;
        }
        a %= 23;
        b %= 28;
        c %= 33;
        i64 p = 1ll * 23 * 28 * 33;
        i64 day = (a * 5544 + b * 14421 + c * 1288 - d + p - 1) % p + 1;
        cout << "Case " << i << ": the next triple peak occurs in " << day << " days.\n";
    }

    return 0;
}