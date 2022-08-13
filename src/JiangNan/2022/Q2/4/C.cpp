/**
 * @author: XiaFan
 * @date: 07-04 13:56
 **/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        i64 a = 1, b = 1;
        bool flag = false;
        while (b <= n) {
            int na = b;
            int nb = a + b;
            if (nb == n) {
                flag = true;
            }
            a = na;
            b = nb;
        }
        if (flag) {
            cout << "Second win\n";
        } else {
            cout << "First win\n";
        }
    }

    return 0;
}