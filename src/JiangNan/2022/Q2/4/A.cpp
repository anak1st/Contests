/**
 * @author: XiaFan
 * @date: 07-04 13:00
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
typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n <= m) {
        cout << "first\n";
        return;
    }
    if (n % (m + 1) == 0) {
        cout << "second\n";
    } else {
        cout << "first\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    

    return 0;
}