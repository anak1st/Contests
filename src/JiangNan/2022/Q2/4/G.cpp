/**
 * @author: XiaFan
 * @date: 07-06 12:09
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
typedef std::set<std::pair<int, int> >::iterator Iterator;

pair<int, int> fun(string s) {
    char c1 = s[0], c2 = s[1];
    int x = 0, y = 0;
    if ('2' <= c1 && c1 <= '9') {
        x = c1 - '0';
    } else if (c1 == 'T') {
        x = 10;
    } else if (c1 == 'J') {
        x = 11;
    } else if (c1 == 'Q') {
        x = 12;
    } else if (c1 == 'K') {
        x = 13;
    } else if (c1 == 'A') {
        x = 14;
    }
    if (c2 == 'C') {
        y = 1;
    } else if (c2 == 'D') {
        y = 2;
    } else if (c2 == 'S') {
        y = 3;
    } else if (c2 == 'H') {
        y = 4;
    }
    assert(x > 0 && y > 0);
    return pair<int, int>{x, y};
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > a;
    set<pair<int, int> > b;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(fun(s));
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        b.insert(fun(s));
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        Iterator it = b.upper_bound(a[i]);
        if (it != b.end()) {
            ans++;
            b.erase(it);
        }
    }
    
    cout << ans << "\n";
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