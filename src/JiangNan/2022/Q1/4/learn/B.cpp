#include <algorithm>
#include <iostream>
#include <map>
#include <string>

typedef long long i64;

int palindrome(std::string &str, int begin, int end) {
    if(begin > end) {
        return 0;
    }

    int i, d1, d2, step = 0;
    for(i = begin; i < end; i++) {
        if(str[i] == str[end]) {
            break;
        }
    }
    d1 = i - begin;

    for(i = end; i > begin; i--) {
        if(str[i] == str[begin]) {
            break;
        }
    }
    d2 = end - i;

    if(d1 < d2) {
        step += d1;
        for(int i = d1 + begin; i > begin; i--) {
            std::swap(str[i], str[i - 1]);
        }
    } else {
        step += d2;
        for(int i = end - d2; i < end; i++) {
            std::swap(str[i], str[i + 1]);
        }
    }
    return step + palindrome(str, begin + 1, end - 1);
}

void solve() {
    std::string str;
    std::cin >> str;
    std::map<char, int> mp;
    for(int i = 0; i < (int)str.length(); i++) {
        mp[str[i]]++;
    }

    int judge = 0;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        judge += (mp[ch] % 2);
        if(judge > 1) {
            std::cout << "Impossible\n";
            return;
        }
    }
    std::cout << palindrome(str, 0, str.length() - 1) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}