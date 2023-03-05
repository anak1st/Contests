#pragma once
#include "XCPC.h"

class Iter {
private:
    int val_, step_;

public:
    Iter(int val, int step = 1) : val_(val), step_(step) {}

    int &operator*() {
        return val_;
    }

    Iter& operator++() {
        val_ += step_;
        return *this;
    }

    Iter operator++(int) {
        Iter tmp = *this;
        ++*this;
        return tmp;
    }

    bool operator!=(const Iter& other) const {
        return val_ != other.val_;
    }
};

class Range {
private:
    int begin_, end_, step_;
public:
    Range(int end) : Range(0, end) {}
    Range(int begin, int end) : Range(begin, end, 1) {}
    Range(int begin, int end, int step) 
    : begin_(begin), end_(end), step_(step) {
        assert((end - step) * step > 0);
        assert(std::abs(end - step) % std::abs(step) == 0);
    }

    Iter begin() const {
        return Iter(begin_, step_);
    }
    Iter end() const {
        return Iter(end_, step_);
    }
};