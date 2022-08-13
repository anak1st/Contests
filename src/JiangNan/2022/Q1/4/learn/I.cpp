#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

i64 ms(int left, int right, std::vector<int> &a, std::vector<int> &b) {
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;
    i64 res = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++, k++;
        } else {
            res += (j - k);
            b[k] = a[j];
            j++, k++;
        }
    }

    while (i <= mid) {
        b[k] = a[i];
        i++, k++;
    }
    while (j <= right) {
        b[k] = a[j];
        j++, k++;
    }

    for (int i = left; i <= right; i++) {
        a[i] = b[i];
    }
    return res;
}

i64 mergesort(int left, int right, std::vector<int> &a, std::vector<int> &b) {
    i64 res = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        res += mergesort(left, mid, a, b);
        res += mergesort(mid + 1, right, a, b);
        res += ms(left, right, a, b);
    }
    return res;
}

void solve(int n) {
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> b(a);
    std::cout << mergesort(0, n - 1, a, b) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (1) {
        int n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        solve(n);
    }

    return 0;
}