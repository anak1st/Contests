#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Tests;
    cin >> Tests;
    while(Tests--) {
        int n;
        cin >> n;

        vector<int> num(n + 1);
        int op = 0;

        cin >> num[1] >> num[2];
        for(int i = 3; i <= n; i++) {
            cin >> num[i];
            if(num[i - 1] > num[i - 2] && num[i - 1] > num[i]) {
                if(i + 1 <= n) {
                    cin >> num[i + 1];
                    if(num[i + 1] > num[i - 1]) {
                        num[i] = num[i + 1];
                    } else {
                        num[i] = num[i - 1];
                    }
                    i++;
                } else {
                    num[i] = num[i - 1];
                }
                op++;
            }
        }

        cout << op << '\n';
        for(int i = 1; i <= n; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}