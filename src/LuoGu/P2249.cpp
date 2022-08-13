// P2249 查找 普及-
// 二分答案
#include <iostream>
int find(int n, int *arry, int num) {
    int left = 0, right = n - 1;
    int ans = -2;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arry[mid] >= num) {
            if(arry[mid] == num) { ans = mid; }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n, m;
    std::cin >> n >> m;
    int *arry = new int[n];
    for(int i = 0; i < n; i++) { std::cin >> arry[i]; }
    for(int i = 0; i < m; i++) {
        int num;
        std::cin >> num;
        std::cout << find(n, arry, num) + 1 << ' ';
    }
    delete[] arry;
    return 0;
}