/**
 * @author: XiaFan
 * @date: 06-07 17:11
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> mp;
    mp["Zi"] = 1;
    mp["Chou"] = 2;
    mp["Yin"] = 3;
    mp["Mao"] = 4;
    mp["Chen"] = 5;
    mp["Si"] = 6;
    mp["Wu"] = 7;
    mp["Wei"] = 8;
    mp["Shen"] = 9;
    mp["You"] = 10;
    mp["Xu"] = 11;
    mp["Hai"] = 12;

    int y, m, d, h;
    string s1, s2;
    cin >> s1 >> m >> d >> s2;
    y = mp[s1], h = mp[s2];

    vector<vector<bool>> b(8 + 1, vector<bool>(3 + 1));
    b[2][1] = true;
    b[3][2] = true;
    b[4][1] = true; b[4][2] = true;
    b[5][3] = true;
    b[6][1] = true; b[6][3] = true;
    b[7][2] = true; b[7][3] = true;
    b[8][1] = true; b[8][2] = true; b[8][3] = true;

    vector<bool> ans(6 + 1);
    int j1 = (y + m + d) % 8; 
    if(j1 == 0) j1 = 8;
    for(int i = 1; i <= 3; i++) {
        ans[i] = b[j1][i];
    }

    int j2 = (y + m + d + h) % 8; 
    if(j2 == 0) j2 = 8;
    for(int i = 1; i <= 3; i++) {
        ans[i + 3] = b[j2][i];
    }

    for(int i = 1; i <= 6; i++) {
        if(ans[i]) {
            cout << "- -\n";
        } else {
            cout << "---\n";
        }
    }
    cout << "\n";

    int j3 = (y + m + d + h) % 6; 
    if(j3 == 0) j3 = 6;
    ans[7 - j3] = !ans[7 - j3];

    for(int i = 1; i <= 6; i++) {
        if(ans[i]) {
            cout << "- -";
        } else {
            cout << "---";
        }
        if(i <= 5) {
            cout << "\n";
        }
    }

    return 0;
}