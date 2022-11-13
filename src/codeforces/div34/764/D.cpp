#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int maxN = 1e3 + 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        int book[26] = {0};
        for(int i = 1; i <= n; i++) {
            char ch;
            cin >> ch;
            book[ch - 'a']++;
        }
        int len = 0;
        int temp = 0;
        for(int i = 0; i < 26; i++) {
            while(book[i] >= 2) {
                if(len + 2 > n / k) { break; }
                temp++;
                book[i] -= 2;
                if(temp == k) {
                    temp = 0;
                    len += 2;
                }
            }
        }
        for(int i = 0; i < 26; i++) {
            while(book[i] >= 1) {
                temp++;
                book[i]--;
                if(temp == k) {
                    len++;
                    goto endFlag;
                }
            }
        }
    endFlag:
        cout << len << '\n';
    }
    return 0;
}