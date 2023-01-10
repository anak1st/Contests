/**
 * @author: XiaFan
 * @date: 05-19 14:44
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a;
    for (int i = 1; i <= 100; i++) a.push_back(i);
    for (int i = 1; i <= 100; i++) a.push_back(i * 100);
    for (int i = 1; i <= 100; i++) a.push_back(i * 10000);
    cout << a.size() << '\n';
    for (int it : a) {
        cout << it << ' ';
    }
    return 0;

    return 0;
}