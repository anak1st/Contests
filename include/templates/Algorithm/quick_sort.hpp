#include <vector>

namespace detail {
template <typename T>
void quick_sort(std::vector<T> &a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    T x = a[l];
    while (i < j) {
        while (i < j && a[j] >= x) {
            j--;
        }
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] <= x) {
            i++;
        }
        if (i < j) a[j--] = a[i];
    }
    a[i] = x;
    quick_sort(a, l, i - 1);
    quick_sort(a, i + 1, r);
}
}  // namespace detail
template <typename T>
void quick_sort(std::vector<T> &a) {
    detail::quick_sort(a, 0, (int)a.size() - 1);
}