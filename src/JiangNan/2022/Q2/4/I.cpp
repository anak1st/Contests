/**
 * @author: XiaFan
 * @date: 07-07 11:50
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

    int n, m;
    while (cin >> m >> n) {
        if (m % (n + 1) == 0) {
            cout << "none\n";
        } else if (m <= n) {
            for (int i = m; i < n; i++) {
                cout << i << " ";
            }
            cout << n <<"\n";
        } else {
            cout << m % (n + 1) << "\n";
        }
    }

    return 0;
}