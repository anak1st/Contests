/**
 * @author: XiaFan
 * @date: 09-09 19:06
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

typedef long long i64;

void solve() {
    std::string s, t;
    std::cin >> s;
    bool flag = true;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 's') {
            flag = false;
        }
        if (s[i] == '(') {
            flag = true;
        }
        if (flag) {
            t.push_back(s[i]);
        }
    }
    std::cout << t << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}