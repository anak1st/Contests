/**
 * @author: XiaFan
 * @date: 2023-12-14 12:38
 */
#include <bits/stdc++.h>

using i64 = long long;

struct submission {
    std::string c;
    int p;
    int t;
    int s;
};

struct score {
    int solved;
    int penalty;

    friend bool operator<(const score &lhs, const score &rhs) {
        if (lhs.solved != rhs.solved) {
            return lhs.solved > rhs.solved;
        }
        return lhs.penalty < rhs.penalty;
    }
};


struct team {
    std::string name;
    score s;
    std::vector<std::vector<std::pair<int, int>>> submissions;

    team(std::string _name) : name(_name), submissions(26) {}
};


void solve() {
    int m;
    std::cin >> m;
    
    std::vector<submission> submissions(m);

    for (int i = 0; i < m; ++i) {
        auto &[c, p, t, s] = submissions[i];
        char problem;
        std::string status;
        std::cin >> c >> problem >> t >> status;
        p = problem - 'A';
        s = (status == "accepted");
    }

    std::map<std::string, int> teams_id;
    std::vector<team> teams;
    for (auto &[c, p, t, s] : submissions) {
        if (!teams_id.count(c)) {
            teams_id[c] = teams.size();
            teams.push_back(team(c));
        }
        teams[teams_id[c]].submissions[p].push_back({t, s});
    }

    for (auto &team : teams) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < team.submissions[i].size(); ++j) {
                auto [t, s] = team.submissions[i][j];
                if (s) {
                    team.s.solved++;
                    team.s.penalty += t + 20 * j;
                    break;
                }
            }
        }
    }

    std::sort(teams.begin(), teams.end(), [](const team &lhs, const team &rhs) {
        return lhs.s < rhs.s;
    });

    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}