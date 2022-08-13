#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define iset std::set<int>                  // infinity set
#define ALL(T) T.begin(), T.end()           // simplify 1
#define INS(T) std::inserter(T, T.begin())  // simplify 2

std::map<iset, int> key;
std::vector<iset> value;

int get_key(const iset& a) {
    if(!key.count(a)) {
        value.push_back(a);
        key[a] = value.size() - 1;
    }

    return key[a];
}

void solve() {
    int N;
    std::cin >> N;

    std::stack<int> set_stack;
    while(N--) {
        std::string op;
        std::cin >> op;

        if(op == "PUSH") {
            set_stack.push(get_key(iset()));
        } else if(op == "DUP") {
            set_stack.push(set_stack.top());
        } else {
            iset a = value[set_stack.top()];
            set_stack.pop();
            iset b = value[set_stack.top()];
            set_stack.pop();

            if(op == "UNION") {
                iset c;
                set_union(ALL(a), ALL(b), std::inserter(c, c.begin()));
                set_stack.push(get_key(c));
            } else if(op == "INTERSECT") {
                iset c;
                set_intersection(ALL(a), ALL(b), std::inserter(c, c.begin()));
                set_stack.push(get_key(c));
            } else if(op == "ADD") {
                b.insert(get_key(a));
                set_stack.push(get_key(b));
            }
        }

        std::cout << value[set_stack.top()].size() << '\n';
    }
    std::cout << "***\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}