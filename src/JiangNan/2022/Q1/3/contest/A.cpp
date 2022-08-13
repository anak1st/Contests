#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

typedef long long i64;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    for(int i = 0; i < n; i++) {
        int len1 = s[i] - 'a';
        int len2 = 'z' - s[i];

        if(std::max(len1, len2) < k) {
            if(len1 > len2) {
                s[i] = 'a';
                k -= len1;
            } else {
                s[i] = 'z';
                k -= len2;
            }
        } else {
            if(len1 >= k) {
                s[i] -= k;
            } else {
                s[i] += k;
            }
            k = 0;
            break;
        }
    }

    if(k > 0) {
        std::cout << -1;
    } else {
        std::cout << s;
    }
    return 0;
}