#pragma comment(linker, "/STACK:102400000,102400000")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ll long long
#define maxn 200005
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mdl 19260817
#define inc(i, a, b) for (int i = a; i < b; i++)
//----------------------------------------------------------------------------------------------------------------------//
template <typename t1, typename t2>
void debug(t1 x, t2 y) {
    cout << x << " : " << y << endl;
}
template <typename t1>
void debug(t1 x) {
    inc(i, 0, x.size()) { cout << x[i] << " "; }
    cout << endl;
}
template <typename t1>
void debug(t1 x, int l, int r) {
    inc(i, l, r) { cout << x[i] << " "; }
    cout << endl;
}

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
ll string2ll(string s) {
    ll tmp = 1;
    ll res = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        res += (ll)(s[i] - '0') * tmp;
        tmp *= 10ll;
    }
    return res;
}
string ll2string(ll num) {
    string res = "";
    while (num) {
        res += (char)(num % 10 + '0');
        num /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
bool pp(string str, string pat) {
    int x = 0;
    inc(i, 0, str.length()) {
        if (str[i] == pat[x]) x++;
        if (x == (int)pat.length()) return true;
    }
    return false;
}
int cnta[10], cntb[10];

int cntta[10], cnttb[10];
int main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--) {
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        ll a, b;
        cin >> a >> b;
        string sa = ll2string(a), sb = ll2string(b);
        inc(i, 0, sa.length()) { cnta[sa[i] - '0']++; }
        inc(i, 0, sb.length()) { cntb[sb[i] - '0']++; }
        //	debug(sa, sb);
        ll lst = a;
        ll g = gcd(a, b);
        ll da = a / g, db = b / g;
        //	debug(da, db);
        int slen = sa.length();
        for (int st = 1; st < (1 << slen); st++) {
            string ssa = "";
            int tmp = st;
            int x = 0;
            while (tmp) {
                if (tmp & 1) ssa += sa[x];
                x++;
                tmp >>= 1;
            }

            ll numa = string2ll(ssa);
            if (numa == 0) continue;
            if (numa % da != 0) continue;
            ll numb = numa / da * db;
            string ssb = ll2string(numb);
            int dif = (int)sb.length() - (int)ssb.length() -
                      ((int)sa.length() - (int)ssa.length());
            inc(i, 0, dif) ssb = '0' + ssb;
            if (!pp(sb, ssb)) continue;
            memset(cntta, 0, sizeof(cntta));
            memset(cnttb, 0, sizeof(cnttb));
            inc(i, 0, ssa.length()) { cntta[ssa[i] - '0']++; }
            inc(i, 0, ssb.length()) { cnttb[ssb[i] - '0']++; }
            int f = 0;
            inc(i, 0, 10) {
                if (cnta[i] - cntta[i] != cntb[i] - cnttb[i]) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) continue;
            //	debug(ssa, ssb);
            lst = min(lst, numa);
        }
        cout << lst << " " << lst / da * db << endl;
    }
}

/*
1
5
2 2 2 2 10
ans is4
*/