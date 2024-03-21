/**
 * @author: XiaFan
 * @date: 2024-03-20 16:32
 */
#include <bits/stdc++.h>

using i64 = long long;

class Singleton {
public:
    Singleton() = default;

    static Singleton* getInstance() {
        if (instance == nullptr) {
            // std::lock_guard<std::mutex> lock(m);

            instance = new Singleton();
        }
        return instance;
    }

    static void print_address() {
        std::cout << instance << std::endl;
    }

private:
    static Singleton* instance;
    // static std::mutex m;
};


Singleton* Singleton::instance = nullptr;


int main() {
    
    Singleton* s1 = Singleton::getInstance();

    s1->print_address();

    Singleton* s2 = Singleton::getInstance();

    s2->print_address();
    

    return 0;
}