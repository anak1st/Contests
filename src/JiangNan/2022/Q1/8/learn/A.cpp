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
    return next;
}

void kmp() {
    string a, b;
    cin >> a >> b;
    int na = a.length(), nb = b.length();
    vector<int> next = get_nex(a);
    int ans = 0;
    for(int i = 0, j = 0; j < nb; j++) {
        while(i > 0 && b[j] != a[i]) {
            i = next[i];
        }
        if(b[j] == a[i]) {
            i++;
        }
        if(i == na) {
            ans++;
            i = next[i];
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while(T--) {
        kmp();
    }

    return 0;
}