#include <bits/stdc++.h>

int find(int x, std::vector<int> &a) {
    if(a[x] != x) {
        a[x] = find(a[x], a);
    }
    return a[x];
}

void unity(int x, int y, std::vector<int> &a) {
    int fx = find(x, a);
    int fy = find(y, a);
    a[fx] = fy;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }

    for(int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        unity(i, x, a);
    }
    std::set<int> ans;

    for(int i = 1; i <= n; i++) {
        ans.insert(find(i, a));
    }

    std::cout << ans.size() << '\n';
    return 0;
}