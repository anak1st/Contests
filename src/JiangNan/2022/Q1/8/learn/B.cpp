/**
 * @author: XiaFan
 * @date: 04-25 12:41
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

vector<int> get_nex(string &s) {
    int n = s.size();
    vector<int> next(n + 1, 0);
    next[0] = -1;
    for(int i = 0, j = -1; i < n;) {
        if(j == -1 || s[i] == s[j]) {
            i++, j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next;  // size (n+1)
}

void kmp(string &a) {
    int na = a.length();

    vector<int> next = get_nex(a);
    int ans = 1;
    int mxsize = na - next[na];
    if(na % mxsize == 0) {
        ans = na / mxsize;
    }
    cout << ans << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true) {
        string a;
        cin >> a;
        if(a == ".") {
            break;
        }
        kmp(a);
    }

    return 0;
}