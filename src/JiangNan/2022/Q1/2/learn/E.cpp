#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

struct data {
    int index;
    int l, r;
    bool operator<(const data &a) const {
        return l < a.l;
    }
};

struct myque {
    int last, no;
    bool operator<(const myque &a) const {
        return last > a.last;
    }
    myque() : last(0) {
        // ...
    }
    myque(int i, int no, std::vector<data> &a) : last(a[i].r), no(no) {
        // ...
    }
    void push(int i, std::vector<data> &a) {
        last = a[i].r;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<data> a(n + 1);
    for(int i = 1; i <= n; i++) {
        a[i].index = i;
        std::cin >> a[i].l >> a[i].r;
    }
    std::sort(a.begin() + 1, a.end());

    std::vector<int> ans(n + 1);
    std::priority_queue<myque> q;
    ans[a[1].index] = 1;
    q.push(myque(1, 1, a));
    for(int i = 2; i <= n; i++) {
        if(q.top().last < a[i].l) {
            myque temp = q.top();
            q.pop();
            ans[a[i].index] = temp.no;
            temp.push(i, a);
            q.push(temp);
        } else {
            ans[a[i].index] = q.size() + 1;
            q.push(myque(i, q.size() + 1, a));
        }
    }

    std::cout << q.size() << '\n';
    for(int i = 1; i <= n; i++) {
        std::cout << ans[i] << '\n';
    }
    return 0;
}