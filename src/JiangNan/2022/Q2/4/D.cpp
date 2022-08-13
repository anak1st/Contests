/**
 * @author: XiaFan
 * @date: 07-05 17:43
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

    int n, p, q;
    while (cin >> n >> p >> q) {
        int a = n % (p + q);
        if (0 < a && a <= p) {
            cout << "LOST\n";
        } else {
            cout << "WIN\n";
        }
    }

    return 0;
}