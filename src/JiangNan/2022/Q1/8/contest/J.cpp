#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int fun(char c) {
    int x;
    if('0' <= c && c <= '9') {
        x = c - '0';
    } else {
        x = c - 'a' + 10;
    }
    return x;
}

char refun(int x) {
    char c;
    if(x < 10) {
        c = x + '0';
    } else {
        c = x - 10 + 'a';
    }
    return c;
}

bool bighex(string &a, string &b) {
    if(a.length() != b.length()) {
        return a.length() < b.length();
    }

    for(int i = 0; i < (int)a.length(); i++) {
        if(fun(a[i]) != fun(b[i])) {
            return fun(a[i]) < fun(b[i]);
        }
    }
    return a < b;
}

string half(string a) {
    for(int i = 0, j = 0; i < (int)a.length(); i++) {
        int num = fun(a[i]) + j * 16;
        j = num % 2;
        num /= 2;
        a[i] = refun(num);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;
    for(int t = 1; t <= test; t++) {
        string a, b;
        cin >> a >> b;
        while(a.length() > 1 && a[0] == '0') {
            a.erase(a.begin());
        }
        while(b.length() > 1 && b[0] == '0') {
            b.erase(b.begin());
        }
        while(a != b) {
            if(bighex(a, b)) {
                b = half(b);
            } else {
                a = half(a);
            }
            while(a.length() > 1 && a[0] == '0') {
                a.erase(a.begin());
            }
            while(b.length() > 1 && b[0] == '0') {
                b.erase(b.begin());
            }
            // cerr << a << " " << b << "\n";
        }
        string ans = a;
        cout << "Case #" << t << ": " << ans << "\n\n";
    }

    return 0;
}