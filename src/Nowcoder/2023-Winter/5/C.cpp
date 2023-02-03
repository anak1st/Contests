/**
 * @author: XiaFan
 * @date: 2023-02-01 15:18
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;
    if (a.length() == b.length()) {
        if (a == b) {
            std::cout << "=";
        } else {
            std::cout << "!";
        }
    } else if (a.length() > b.length()) {
        char c = a.front();
        int pa = std::min(a.length(), a.find_first_not_of(c));
        int pb = std::min(b.length(), b.find_first_not_of(c));
        if (a.length() - pa > b.length() - pb) {
            std::cout << ">";
        }  else {
            std::cout << "!";
        }
    } else if (a.length() < b.length()) {
        char c = b.front();
        int pa = std::min(a.length(), a.find_first_not_of(c));
        int pb = std::min(b.length(), b.find_first_not_of(c));
        if (a.length() - pa < b.length() - pb) {
            std::cout << "<";
        } else {
            std::cout << "!";
        }
    }

    return 0;
}