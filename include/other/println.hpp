#pragma once
#include "XCPC.h"

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, std::pair<T, U> p);
template <typename T> 
std::ostream &operator<<(std::ostream &os, std::vector<T> v);
template <typename T, size_t S>
std::ostream &operator<<(std::ostream &os, std::array<T, S> a);
template <typename T> 
void println(const T &val);
template <typename T, typename... Args> 
void println(const T &val, const Args &...args);

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, std::pair<T, U> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
template <typename T> 
std::ostream &operator<<(std::ostream &os, std::vector<T> v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); it++) {
        os << *it;
        if (it != v.end() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
template <typename T, size_t S>
std::ostream &operator<<(std::ostream &os, std::array<T, S> a) {
    os << "[";
    for (auto it = a.begin(); it != a.end(); it++) {
        os << *it;
        if (it != a.end() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template <typename T> 
void println(const T &val) {
    std::cerr << val << "\n";
}
template <typename T, typename... Args> 
void println(const T &val, const Args &...args) {
    std::cerr << val << " ";
    println(args...);
}
