// P1553 数字反转(升级版) 普及-
// 模拟 字符串
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int maxN = 1234;

string fun(string str) {
    string ans = str;
    reverse(ans.begin(), ans.end());
    while(ans[0] == '0') { ans.erase(0, 1); }
    while(ans[ans.size() - 1] == '0') { ans.erase(ans.size() - 1, 1); }
    if(ans.size() == 0) { ans.push_back('0'); }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str, ans;
    cin >> str;
    if(str.find('.') != str.npos) {
        int p = str.find('.');
        ans = fun(str.substr(0, p)) + '.' + fun(str.substr(p + 1));
    } else if(str.find('/') != str.npos) {
        int p = str.find('/');
        ans = fun(str.substr(0, p)) + '/' + fun(str.substr(p + 1));
    } else if(str.find('%') != str.npos) {
        ans = fun(str.substr(0, str.size() - 1)) + '%';
    } else {
        ans = fun(str);
    }
    cout << ans << endl;
    return 0;
}