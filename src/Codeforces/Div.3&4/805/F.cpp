/**
 * @author: XiaFan
 * @date: 07-20 18:08
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<int>> qa, qb;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        qa.push(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        qb.push(x);
    }
    while (!qa.empty()) {
        if (qa.top() == qb.top()) {
            qa.pop();
            qb.pop();
        } else if (qa.top() < qb.top()) {
            int temp = qb.top() / 2;
            qb.pop();
            qb.push(temp);
        } else {
            if (qa.top() % 2 == 1) {
                cout << "No\n";
                return;
            }
            int temp = qa.top() / 2;
            qa.pop();
            qa.push(temp);
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}