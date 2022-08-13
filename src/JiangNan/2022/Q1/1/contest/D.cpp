#include <iostream>
#include <set>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> rot(n + 1);
    std::vector<std::set<int>> num(n + 1);
    std::set<int> b;
    b.insert(1);
    for(int i = 2; i <= n; i++) {
        int r;
        std::cin >> r;
        rot[i] = r;
        num[r].insert(i);
        num[rot[r]].erase(r);
        b.insert(r);
    }

    for(auto it : b) {
        if(num[it].size() < 3) {
            std::cout << "No\n";
            return 0;
        }
    }
    std::cout << "Yes\n";

    return 0;
}