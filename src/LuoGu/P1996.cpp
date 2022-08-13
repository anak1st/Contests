#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> game(n);
    for(int i = 0; i < n; i++) {
        game[i] = i + 1;
    }

    int now = 0;
    auto it = game.begin();
    while(!game.empty()) {
        now++;
        if(it == game.end()) {
            it = game.begin();
        }
        if(now == m) {
            now = 0;
            cout << *it << ' ';
            it = game.erase(it);
        } else {
            it++;
        }
    }
    return 0;
}