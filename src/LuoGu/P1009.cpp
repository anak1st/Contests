// P1009 阶乘之和 普及-
// 数论,数学 高精度
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxN = 12345;

struct High {
    int num[maxN];
    High() {
        for(int i = 0; i < maxN; i++) {
            num[i] = 0;
        }
    }
    High(int x) {
        for(int i = 0; i < maxN; i++) {
            num[i] = x % 10;
            x /= 10;
        }
    }
    High operator+(High b) {
        High ans;
        for(int i = 0; i < maxN; i++) {
            ans.num[i] += num[i] + b.num[i];
            while(ans.num[i] >= 10) {
                ans.num[i] -= 10;
                ans.num[i + 1]++;
            }
        }
        return ans;
    }
    High operator*(int b) {
        High ans;
        for(int i = 0; i < maxN; i++) {
            ans.num[i] += num[i] * b;
            while(ans.num[i] >= 10) {
                ans.num[i] -= 10;
                ans.num[i + 1]++;
            }
        }
        return ans;
    }
    High operator*(High b) {
        High ans;
        for(int i = 0; i < maxN; i++) {
            for(int j = 0; i + j < maxN; j++) {
                ans.num[i + j] += num[j] * b.num[i];
                while(ans.num[i + j] >= 10) {
                    ans.num[i + j] -= 10;
                    ans.num[i + j + 1]++;
                }
            }
        }
        return ans;
    }
    void out() {
        bool start = false;
        for(int i = maxN - 1; i >= 0; i--) {
            if(!start && num[i] != 0) {
                start = true;
            }
            if(start) {
                cout << num[i];
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    High a(n);
    for(int i = n - 1; i >= 1; i--) {
        a = a + High(1);
        a = a * i;
    }
    a.out();
    return 0;
}