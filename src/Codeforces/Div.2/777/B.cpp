#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n, std::vector<int>(m));
    for(int i = 0; i < n; i++) {
        std::string input;
        std::cin >> input;
        for(int j = 0; j < m; j++) {
            v[i][j] = (int)(input[i] - '0');
        }
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            int judge = 0;
            judge += v[i][j];
            judge += v[i + 1][j];
            judge += v[i][j + 1];
            judge += v[i + 1][j + 1];
            if(judge == 3) {
                std::cout << "NO\n";
                return;
            }
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}