#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);

    for(int i = 0; i < n; i++) {
        double input;
        std::cin >> input;
        a[i] = (int)(input * 100.0);
    }
    std::sort(a.begin(), a.end());

    int ans = 0;
    int left = 1, right = a[n - 1];
    while(left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += (a[i] / mid);
        }
        if(sum >= k) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }
    std::cerr << left << '\n' << ans << '\n' << right << '\n';
    double output = (double)ans / 100.0;
    std::cout << std::fixed << std::setprecision(2) << output << '\n';

    return 0;
}