/**
 * @author: XiaFan
 * @date: 04-17 19:35
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    if(s == "FILO") {
        std::stack<int> s;
        for(int i = 0; i < n; i++) {
            std::string op;
            std::cin >> op;
            if(op == "IN") {
                int num;
                std::cin >> num;
                s.push(num);
            } else {
                if(s.empty()) {
                    std::cout << "None\n";
                } else {
                    std::cout << s.top() << "\n";
                    s.pop();
                }
            }
        }
    } else {
        std::queue<int> s;
        for(int i = 0; i < n; i++) {
            std::string op;
            std::cin >> op;
            if(op == "IN") {
                int num;
                std::cin >> num;
                s.push(num);
            } else {
                if(s.empty()) {
                    std::cout << "None\n";
                } else {
                    std::cout << s.front() << "\n";
                    s.pop();
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}