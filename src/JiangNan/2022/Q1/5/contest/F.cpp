/**
 * @author: XiaFan
 * @date: 2022-04-10 20:20:32
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;
    if(n == 1 || isprime(n)) {
        std::cout << "1\n0\n";
        return 0;
    }

    i64 a[2], j = 0;
    i64 nn = n;
    for(i64 i = 2; i <= (int)std::sqrt(n); i++) {
        while(nn % i == 0) {
            a[j] = i;
            j++;
            nn /= i;
            if(j >= 2) {
                break;
            }
        }
        if(j >= 2) {
            break;
        }
    }
    if(j == 2 && a[0] * a[1] != n) {
        std::cout << "1\n" << a[0] * a[1] << '\n';
    } else {
        std::cout << "2\n";
    }

    return 0;
}