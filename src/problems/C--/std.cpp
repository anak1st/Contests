/**
 * @author: XiaFan
 * @date: 2023-01-17 19:16
 **/
#include <bits/stdc++.h>
using i64 = long long;

std::string mk_fmt(std::string line) {
    if (!line.empty()) {
        int p = line.find_first_not_of(' ');
        if (p != std::string::npos) {
            line = line.substr(p);
        } else {
            line = "";
        }
    }
    while (!line.empty() && line.back() == ' ') {
        line.pop_back();
    }
    return line;
}
std::string next(std::string &line, char c) {
    int p = line.find('\"');
    if (p != std::string::npos) {
        p = line.find('\"', p + 1);
    }
    int e = line.find(c, p + 1);
    std::string word = line.substr(0, e);
    line = line.substr(e + 1);
    // std::cerr << "next: " << word << "\n";
    return word;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<std::string, std::string> vals;

    auto let = [&](std::string s) {
        s = mk_fmt(s);
        s = s.substr(4, s.size() - 4);
        int p = s.find('=');
        std::string k = mk_fmt(s.substr(0, p));
        std::string v = mk_fmt(s.substr(p + 1, s.size() - p - 1));
        if (v.front() == '"') {
            v = v.substr(1, v.size() - 2);
        }
        vals[k] = v;
        // std::cerr << "let[" << k << "]=[" << v << "]\n";
    };
    auto println = [&](std::string s) {
        s = mk_fmt(s);
        s = s.substr(9, s.size() - 10);
        // std::cerr << "println[" << s << "]\n";
        int p = s.find(',');
        std::string names = mk_fmt(s.substr(p + 1));
        std::string o;
        for (int i = 1; i < p - 1; i++) {
            if (s[i] == '{') {
                i++;
                std::string k = mk_fmt(next(names, ','));
                o += vals[k];
            } else {
                o.push_back(s[i]);
            }
        }
        std::cout << o << "\n";
    };

    std::string line, words;
    while (std::getline(std::cin, line)) {
        while (!line.empty()) {
            line = mk_fmt(line);
            if (!line.empty()) {
                words = next(line, ';');
            }
            if (!words.empty() && words.front() == 'l') {
                let(words);
            }
            if (!words.empty() && words.front() == 'p') {
                println(words);
            }
        }
    }
    
    return 0;
}