#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int test_cases;
    std::cin >> test_cases;
    while(test_cases--) {
        int m, n;
        std::cin >> m >> n;
        // 小顶堆
        std::priority_queue<int, std::vector<int>, std::greater<int>> ans;

        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            ans.push(x);
        }

        for(int i = 1; i < m; i++) {
            std::vector<int> a(n);
            for(int j = 0; j < n; j++) std::cin >> a[j];
            // 大顶堆
            std::priority_queue<int, std::vector<int>, std::less<int>> tmp;

            while(!ans.empty()) {
                int btop = ans.top();
                ans.pop();

                for(int j = 0; j < n; j++) {
                    if((int)tmp.size() == n && tmp.top() > btop + a[j]) {
                        tmp.pop();
                        tmp.push(btop + a[j]);
                    } else if((int)tmp.size() < n) {
                        tmp.push(btop + a[j]);
                    }
                }
            }

            while(!tmp.empty()) {
                ans.push(tmp.top());
                tmp.pop();
            }
        }

        while(!ans.empty()) {
            std::cout << ans.top() << ' ';
            ans.pop();
        }

        std::cout << '\n';
    }

    return 0;
}