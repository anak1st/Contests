/**
 * @author: XiaFan
 * @date: 05-11 19:06
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 merge_sort_do(int left, int right, vector<int> &a, vector<int> &b) {
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;
    i64 res = 0;
    while (i <= mid && j <= right) {
        if (a[i] < a[j]) {
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

i64 merge_sort_dfs(int left, int right, vector<int> &a, vector<int> &b) {
    i64 res = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        res += merge_sort_dfs(left, mid, a, b);
        res += merge_sort_dfs(mid + 1, right, a, b);
        res += merge_sort_do(left, right, a, b);
    }
    return res;
}

i64 merge_sort(vector<int> &a) {
    std::vector<int> b(a);
    return merge_sort_dfs(0, a.size() - 1, a, b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    i64 ans = merge_sort(a);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}