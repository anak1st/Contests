/**
 * @author: XiaFan
 * @date: 05-15 19:16
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto i : s) {
        mp[i]++;
    }
    int one = mp['n'];
    int zero = mp['z'];
    for (int i = 0; i < one; i++) {
        cout << "1 ";
    }
    for (int i = 0; i < zero; i++) {
        cout << "0 ";
    }

    return 0;
}