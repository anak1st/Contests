#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct High {
    static constexpr int maxL = 1000;
    int num[maxL];

    High() {
        for(int i = 0; i < maxL; i++) {
            num[i] = 0;
        }
    }

    High(int x) {
        for(int i = 0; i < maxL; i++) {
            num[i] = x % 10;
            x /= 10;
        }
    }

    High operator+(High another) {
        High ans;
        for(int i = 0; i < maxL; i++) {
            ans.num[i] += num[i] + another.num[i];
            while(ans.num[i] >= 10) {
                ans.num[i + 1]++;
                ans.num[i] -= 10;
            }
        }
        return ans;
    }

    void out() {
        bool flag = false;
        for(int i = maxL - 1; i >= 0; i--) {
            if(!flag && num[i] != 0) {
                flag = true;
            }
            if(flag) {
                cout << num[i];
            }
        }
        cout << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    High x, y, z;
    x = High(1);
    y = High(1);
    for(int i = a + 2; i <= b; i++) {
        z = x + y;
        x = y;
        y = z;
    }
    z.out();
    return 0;
}