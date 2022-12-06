#pragma once

#define DEBUG_XF

#include <cassert>
#include <iostream>
#include <vector>
#include <array>

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, std::pair<T, U> p);
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v);
template <typename T, size_t S>
std::ostream& operator<<(std::ostream& os, std::array<T, S> a);


template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, std::pair<T, U> p) {
    os << "p( " << p.first << " " << p.second << ")";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    os << "v[ ";
    for (auto it : v) {
        os << it << " ";
    }
    os << "]";
    return os;
}

template <typename T, size_t S>
std::ostream& operator<<(std::ostream& os, std::array<T, S> a) {
    os << "a[ ";
    for (auto it : a) {
        os << it << " ";
    }
    os << "]";
    return os;
}

template<typename T>
void printIn(const T& val) {
    std::cerr << val << "\n";
}

template<typename T, typename... Args>
void printIn(const T& val, const Args&... args) {
    std::cerr << val << " ";
    printIn(args...);
}