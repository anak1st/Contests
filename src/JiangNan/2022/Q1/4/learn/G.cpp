#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

i64 fpower(i64 a, i64 x, i64 p) {
    i64 res = 1;
    a %= p;
    while(x) {
        if(x % 2) {
            res = (res * a) % p;
        }
        x /= 2;
        a = (a * a) % p;
    }
    return res;
}

bool isprime(i64 x) {
    if(x <= 1) {
        return false;
    } else if(x == 2) {
        return true;
    } else if(x % 2 == 0) {
        return false;
    } else {
        for(i64 i = 3; i * i <= x; i += 2) {
            if(x % i == 0) {
                return false;
            }
        }
        return true;
    }
}

void solve(i64 p, i64 a) {
    if(!isprime(p) && fpower(a, p, p) % p == a % p) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while(1) {
        i64 p, a;
        std::cin >> p >> a;
        if(p == 0 && a == 0) {
            break;
        }
        solve(p, a);
    }
    return 0;
}
