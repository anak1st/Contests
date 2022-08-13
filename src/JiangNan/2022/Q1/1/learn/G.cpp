#include <iostream>
#include <stack>
#include <string>

void solve() {
    std::string str;
    std::getline(std::cin, str);

    if(str.length() == 0) {
        std::cout << "Yes\n";
        return;
    }

    std::stack<char> st;
    for(auto it : str) {
        if(it == '(' || it == '[') {
            st.push(it);
        } else {
            if(st.size() == 0) {
                std::cout << "No\n";
                return;
            } else if(st.top() == '(' && it == ')') {
                st.pop();
            } else if(st.top() == '[' && it == ']') {
                st.pop();
            } else {
                std::cout << "No\n";
                return;
            }
        }
    }

    if(!st.empty()) {
        std::cout << "No\n";
        return;
    }

    std::cout << "Yes\n";
}

int main() {
    int test_cases;
    std::cin >> test_cases;
    getchar();
    while(test_cases--) {
        solve();
    }

    return 0;
}