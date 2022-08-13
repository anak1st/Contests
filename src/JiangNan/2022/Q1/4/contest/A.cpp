#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

typedef long long i64;

bool equal(std::string a, std::string b) {
    if(a.length() != b.length()) {
        return false;
    }
    if(a.length() == 1) {
        return (a == b);
    }

    if(a == b) {
        return true;
    }

    if(a.length() % 2 == 1) {
        return false;
    }

    int mid = a.length() / 2;
    std::string a1 = a.substr(0, mid);
    std::string a2 = a.substr(mid, a.length());
    std::string b1 = b.substr(0, mid);
    std::string b2 = b.substr(mid, b.length());

    if(equal(a1, b1) && equal(a2, b2)) {
        return true;
    }
    if(equal(a2, b1) && equal(a1, b2)) {
        return true;
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string a, b;
    std::cin >> a >> b;
    if(a.length() == b.length() && equal(a, b)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}