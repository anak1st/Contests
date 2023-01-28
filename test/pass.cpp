#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
#define edl '\n'

using namespace std;
using ll = long long;

constexpr int MXN = 1e6 + 10;

ll n, m;
ll a[MXN];
vector<ll> ve;
 
void Init(void)
{
    a[1] = 1;
    FOR(i, 2, MXN - 3)
    a[i] = a[i - 1] + i;
    return;
}
void Solve(void)
{
    ve.clear();
    cin >> n >> m;
    ll row = (n * n + n) / 2;
    ll col = (m * m + m) / 2;
    ll tot = row * col;
    if (tot & 1)
    {
        cout << "No" << edl;
        return;
    }
    ll f = 0;
    if (col % 2 == 0)
    {
        ll aim = col / 2 - m;
        ll sum = 0;
        ROF(i, m + 1, 1)
        {
            if (aim == 0)
                break;
            ll k = aim / a[i];
            FOR(j, 1, k)
            {
                ve.push_back(i + 1);
                sum += i + 1;
            }
            aim %= a[i];
        }
        f = 1;
        FOR(i, 1, m - sum)
        ve.push_back(1);
    }
    else if (row % 2 == 0)
    {
        ll aim = row / 2 - n;
        ll sum = 0;
        ROF(i, n + 1, 1)
        {
            if (aim == 0)
                break;
            ll k = aim / a[i];
            FOR(j, 1, k)
            {
                ve.push_back(i + 1);
                sum += (i + 1);
            }
            aim %= a[i];
        }
        f = 2;
        FOR(i, 1, n - sum)
        ve.push_back(1);
    }
    if (f == 0)
    {
        cout << "No" << edl;
        return;
    }
    cout << "Yes" << edl;
    if (f == 1)
    {
        FOR(i, 1, n)
        {
            bool flag = true;
            ll ch = 1;
            for (auto it : ve)
            {
                FOR(j, 1, it)
                {
                    if (flag)
                        flag = false;
                    else
                        cout << ' ';
                    cout << ch;
                }
                ch = 1 - ch;
            }
            cout << edl;
        }
    }
    if (f == 2)
    {
        ll ch = 1;
        for (auto it : ve)
        {
            FOR(i, 1, it)
            {
                bool flag = true;
                FOR(j, 1, m)
                {
                    if (flag)
                        flag = false;
                    else
                        cout << ' ';
                    cout << ch;
                }
                cout << edl;
            }
            ch = 1 - ch;
        }
    }
}
int main(void)
{
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // #ifdef cincoutcmd
    //  freopen("cin.txt", "r", stdin);
    //  freopen("cout.txt", "w", stdout);
    // #endif
    Init();
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}