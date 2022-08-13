/**
 * @author: XiaFan
 * @date: 06-27 11:26
 **/
#include <algorithm>
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

    int mx = 1000000;
    vector<int> a(mx, 0);
    for(int i = 1; i < mx; i++) {
        string s = to_string(i);
        if(s.find("62") != s.npos || s.find("4") != s.npos) {
            a[i] = a[i - 1];
        } else {
            a[i] = a[i - 1] + 1;
        }
    }

    while (true) {
        int x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) {
            break;
        }
        cout << a[y] - a[x - 1] << "\n";
    }

    return 0;
}