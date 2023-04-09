#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    int smin = 0, smax = 0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        
        const int one = std::count(s.begin(), s.end(), '1');
        int two = 0;
        for (int j = 0; j < m - 1; j++) {
            if (s[j] == '1' && s[j + 1] == '1') {
                j++;
                two++;
            }
        }
        two = std::min(two, m / 4);
        smin += one - two;
        
        two = 0;
        for (int j = 0; j < m - 1; j++) {
            if (s[j] != '1' || s[j + 1] != '1') {
                j++;
                two++;
            }
        }
        two = std::min(two, m / 4);
        smax += one - (m / 4 - two);
    }
    
    std::cout << smin << " " << smax << "\n";
    
    return 0;
}
