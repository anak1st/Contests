// P3811 乘法逆元 普及/提高-
// 数论,数学 递推 素数判断,质数,筛法 逆元
#include <ctime>
#include <iostream>
#include <tuple>

using i64 = long long;
std::tuple<int, int> Exgcd(int a, int b) {  // ax + by = 1 full
    int x, y;
    if(b == 0) {
        x = 1, y = 0;
    } else {
        std::tie(x, y) = Exgcd(b, a % b);
        int t = x;
        x = y;
        y = t - (a / b) * y;
    }
    return std::make_tuple(x, y);
}

void FExgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if(b == 0) {
        x = 1;
        y = 0;
    } else {
        FExgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

int main() {
    std::clock_t start, finish;
    int n, p;
    std::cin >> n >> p;
    start = clock();
    for(int i = 1; i <= n; i++) {
        long long x, y;
        // std::tie(x, y) = Exgcd(i, p);
        FExgcd(i, p, x, y);
        std::cout << (x % p + p) % p << std::endl;
    }
    finish = clock();
    double Times = (double)(finish - start) / CLOCKS_PER_SEC;
    // std::cout << Times << std::endl;
    return 0;
}