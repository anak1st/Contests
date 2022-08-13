#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

struct team {
    string name;
    int point;
    std::array<int, 5> s;
    team() {
        point = 0;
        for(int i = 0; i < 5; i++) {
            s[i] = 0;
        }
    }

    friend bool operator<(const team& lhs, const team& rhs) {
        if(lhs.point == rhs.point) {
            int dlhs = lhs.s[3] - lhs.s[4];
            int drhs = rhs.s[3] - rhs.s[4];
            if(dlhs == drhs) {
                if(lhs.s[3] == rhs.s[3]) {
                    return lhs.name < rhs.name;
                }
                return lhs.s[3] > rhs.s[3];
            }
            return dlhs > drhs;
        }
        return lhs.point > rhs.point;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;
    for(int t = 1; t <= test; t++) {
        int n, m;
        cin >> n >> m;
        vector<team> teams(n);
        map<string, int> mp;
        for(int i = 0; i < n; i++) {
            cin >> teams[i].name;
            mp[teams[i].name] = i;
        }

        // 0    1      2      3           4
        // wins losses draws  goalsscored goalsallowed
        for(int i = 0; i < m; i++) {
            string n1, n2;
            int s1, s2;
            cin >> n1 >> s1 >> n2 >> s2;
            teams[mp[n1]].s[3] += s1;
            teams[mp[n1]].s[4] += s2;
            teams[mp[n2]].s[3] += s2;
            teams[mp[n2]].s[4] += s1;
            if(s1 == s2) {
                teams[mp[n1]].s[2]++;
                teams[mp[n2]].s[2]++;
            } else if(s1 > s2) {
                teams[mp[n1]].s[0]++;
                teams[mp[n2]].s[1]++;
            } else {
                teams[mp[n1]].s[1]++;
                teams[mp[n2]].s[0]++;
            }
        }
        for(int i = 0; i < n; i++) {
            teams[i].point = teams[i].s[0] * 3 + teams[i].s[2];
        }
        sort(teams.begin(), teams.end());

        cout << "Group " << t << ":\n";
        for(int i = 0; i < n; i++) {
            cout << teams[i].name << " " << teams[i].point << " ";
            for(int j = 0; j < 5; j++) {
                cout << teams[i].s[j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}