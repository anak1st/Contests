/**
 * @author: XiaFan
 * @date: 04-25 12:41
 **/
#include <algorithm>
#include <cmath>
#include <deque>
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
    deque<int> ans;
    int p = na;
    while(p > 0) {
        ans.push_front(p);
        p = next[p];
    }
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    while(cin >> a) {
        kmp(a);
    }

    return 0;
}