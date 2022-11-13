/**
 * @author: XiaFan
 * @date: 11-01 19:26
 **/
#include <bits/stdc++.h>

using i64 = long long;

namespace __MS {

template <typename T, typename RT, typename Sequence> 
RT Merge(int left, int right, Sequence &a, Sequence &b) {
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;
    RT res = 0;
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

template <typename T, typename RT, typename Sequence> 
RT Sort(int left, int right, Sequence &a, Sequence &b) {
    RT res = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        res += Sort <T, RT, Sequence>(left,    mid,   a, b);
        res += Sort <T, RT, Sequence>(mid + 1, right, a, b);
        res += Merge<T, RT, Sequence>(left,    right, a, b);
    }
    return res;
}

}  // namespace __MS

template <typename T, typename RT, typename Sequence = std::vector<T>> 
RT MergeSort(Sequence &a) {
    Sequence b(a);
    return __MS::Sort<T, RT, Sequence>(0, a.size() - 1, a, b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::deque<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::string s;
    std::cin >> s;
    std::deque<int> b(a);
    i64 k = MergeSort<int, i64, std::deque<int>>(b);
    std::cout << k << "\n";
    bool rev = false;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'R') {
            k = 1LL * n * (n - 1) - k;
            rev = !rev;
        } else {
            if (!rev) {
                k -= a.front() - 1;
                k += n - a.front();
                a.push_back(a.front());
                a.pop_front();
            } else {
                k -= a.back() - 1;
                k += n - a.back();
                a.push_front(a.back());
                a.pop_back();
            }
        }
        k = (k % 10 + 10) % 10;
        std::cout << k;
    }
    
    return 0;
}