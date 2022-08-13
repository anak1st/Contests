#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

/*
void solve_with_vector() {
    int num, n;
    std::cin >> num >> n;
    std::cout << num << ' ' << (n + 1) / 2 << '\n';

    std::vector<int> a;
    for(int i = 1, j = 0; i <= n; i++) {
        int x;
        std::cin >> x;
        a.insert(upper_bound(a.begin(), a.end(), x), x);

        if(i & 1) {
            j++;
            std::cout << a[(i - 1) / 2] << ' ';
            if(j == 10) {
                j = 0;
                std::cout << '\n';
            }
        }
    }
    if(n % 10 != 0) std::cout << '\n';
}
*/

void solve() {
    int num, n;
    std::cin >> num >> n;
    std::cout << num << ' ' << (n + 1) / 2 << '\n';

    std::priority_queue<int, std::vector<int>> q1;                     //大根堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> q2;  //小根堆

    int input;
    std::cin >> input;
    q1.push(input);
    std::cout << q1.top() << ' ';
    for(int i = 2; i <= n; i++) {
        std::cin >> input;
        if(input > q1.top()) {
            q2.push(input);
        } else {
            q1.push(input);
        }

        if((int)q1.size() - (int)q2.size() > 1) {
            q2.push(q1.top());
            q1.pop();
        }
        if((int)q2.size() - (int)q1.size() > 0) {
            q1.push(q2.top());
            q2.pop();
        }

        if(i & 1) {
            std::cout << q1.top() << ' ';
        }
        if(i % 20 == 0) std::cout << '\n';
    }
    if(n % 20 != 0) std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases;
    std::cin >> test_cases;
    while(test_cases--) {
        solve();
    }

    return 0;
}