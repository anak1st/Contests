/**
 * @author: XiaFan
 * @date: 04-26 19:01
 **/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> get_next(string &pat) {
    int n = pat.length();
    vector<int> next(n + 1, 0);
    next[0] = -1;
    for(int i = 0, j = -1; i < n;) {
        if(j == -1 || pat[i] == pat[j]) {
            i++, j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next;  // size (n+1)
}

bool kmp(string &str, string &pat) {
    int n = str.length();
    int m = pat.length();
    vector<int> next = get_next(pat);
    for(int i = 1, j = 0; i < n - 1; i++) {
        while(j > 0 && str[i] != pat[j]) {
            j = next[j];
        }
        if(str[i] == pat[j]) {
            j++;
        }
        if(j == m) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    while(cin >> str) {
        int n = str.length();
        vector<int> next = get_next(str);
        int len = next[n];
        if(len == 0) {
            cout << "Just a legend\n";
            continue;
        }
        string ans = str.substr(0, len);
        if(kmp(str, ans)) {
            cout << ans << "\n";
            continue;
        }
        len = next[len];
        if(len == 0) {
            cout << "Just a legend\n";
            continue;
        }
        ans = str.substr(0, len);
        if(kmp(str, ans)) {
            cout << ans << "\n";
            continue;
        }
        cout << "Just a legend\n";
    }

    return 0;
}