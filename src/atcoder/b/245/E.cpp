#include <bits/stdc++.h>

typedef long long i64;
typedef std::pair<int, int> rectangle;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<rectangle> choco(n), box(m);
    for(int i = 0; i < n; i++) {
        std::cin >> choco[i].first;
    }
    for(int i = 0; i < n; i++) {
        std::cin >> choco[i].second;
    }
    for(int i = 0; i < m; i++) {
        std::cin >> box[i].first;
    }
    for(int i = 0; i < m; i++) {
        std::cin >> box[i].second;
    }
    std::sort(choco.begin(), choco.end(), std::greater());
    std::sort(box.begin(), box.end(), std::greater());

    std::multiset<int> s;
    int i = 0, j = 0;
    while(i < n) {
        while(j < m && box[j].first >= choco[i].first) {
            s.insert(box[j].second);
            j++;
        }

        auto it = s.lower_bound(choco[i].second);
        if(it == s.end()) {
            // std::cerr << "break\n";
            break;
        }
        s.erase(it);
        i++;
    }

    if(i == n) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}