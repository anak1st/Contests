/**
 * @author: XiaFan
 * @date: 07-07 11:41
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        int y, m, d;
        cin >> y >> m >> d;
        if ((m + d) % 2 == 0 || ((m == 9 || m == 11) && d == 30)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}