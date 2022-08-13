#include <iostream>

typedef long long i64;
constexpr int P = 1000000007;

i64 A(int n, int m) {
    i64 ans = 1;
    for(int i = n; i >= n - m + 1; i--) {
        ans = (ans * i) % P;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, pos;
    std::cin >> n >> x >> pos;

    int left = 0, right = n;
    int small = 0, big = 0;
    while(left < right) {
        int mid = (left + right) / 2;

        if(mid <= pos) {
            if(mid < pos) {
                small++;
            }
            left = mid + 1;
        } else {
            big++;
            right = mid;
        }
    }
    // std::cerr << big << ' ' << small << '\n';

    // clang-format off
    int remain = n - big - small - 1;
    std::cout << A(n - x, big) % P * 
                 A(x - 1, small) % P *
                 A(remain, remain) % P
              << '\n';
    // clang-format on
    return 0;
}