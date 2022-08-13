/**
 * @author: XiaFan
 * @date: 05-02 11:16
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

i64 euler(i64 n) {
    i64 res = n;
    for(i64 i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            res = res / i * (i - 1);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) {
        res = res / n * (n - 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    i64 n;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        cout << euler(n) << "\n";
    }

    return 0;
}