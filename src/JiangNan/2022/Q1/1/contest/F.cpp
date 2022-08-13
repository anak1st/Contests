#include <iostream>
#include <queue>

#define i64 long long

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> q;
    for(int i = 1; i <= n; i++) {
        i64 x;
        std::cin >> x;
        q.push(x);
    }
    if(n == 1) {
        std::cout << q.top() << '\n';
        return 0;
    }
    i64 ans = 0;
    while(1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        int c = a + b;
        ans += c;
        if(q.size() == 0) {
            break;
        }
        q.push(c);
    }
    std::cout << ans << '\n';

    return 0;
}