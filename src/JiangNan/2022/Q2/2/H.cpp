/**
 * @author: XiaFan
 * @date: 06-29 10:43
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr i64 mod = 1e8 - 3;

template <typename T, typename U>
T MergeSortDo(int left, int right, std::vector<U> &a, std::vector<U> &b) {
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;
    T res = 0;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++, k++;
        } else {
            res = (res + (j - k)) % mod;
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

template <typename T, typename U>
T MergeSortDFS(int left, int right, std::vector<U> &a, std::vector<U> &b) {
    T res = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        res = (res + MergeSortDFS<T, U>(left, mid, a, b)) % mod;
        res = (res + MergeSortDFS<T, U>(mid + 1, right, a, b)) % mod;
        res = (res + MergeSortDo<T, U>(left, right, a, b)) % mod;
    }
    return res;
}

template <typename T, typename U>
T MergeSort(std::vector<U> &a) {
    std::vector<U> b(a);
    return MergeSortDFS<T, U>(0, a.size() - 1, a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n ; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[a[i].second] = b[i].second;
    }

    i64 res = MergeSort<i64, int>(c);
    cout << res % mod;

    return 0;
}