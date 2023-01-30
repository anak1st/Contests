#pragma once
#include "XCPC.h"

struct Integer {
    std::deque<int> data;

    Integer() : Integer(0LL) {}
    Integer(int x) : Integer((i64)x) {} 
    Integer(i64 x) {
        if (x == 0) {
            data.push_back(0);
        }
        while (x) {
            data.push_back(x % 10);
            x /= 10;
        }
    }
    Integer(const std::string &x) {
        resize(x.size());
        for (size_t i = 0; i < x.size(); i++) {
            data[i] = x[i] - '0';
        }
        std::reverse(data.begin(), data.end());
        remove_leading_zero();
    }
    Integer(const std::deque<int> &x) : data(x) {
        std::reverse(data.begin(), data.end());
        remove_leading_zero();
    }
    void resize(int size, int value = 0) {
        data.resize(size, value);
    }
    int size() const {
        return data.size();
    }
    void remove_leading_zero() {
        while (size() > 1 && data.back() == 0) {
            data.pop_back();
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Integer &x) {
        std::deque<int> tmp = x.data;
        std::reverse(tmp.begin(), tmp.end());
        for (auto it : tmp) {
            os << it;
        }
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Integer &x) {
        std::string tmp;
        is >> tmp;
        x = Integer(tmp);
        return is;
    }

    /// @brief for < and > ans =
    friend std::strong_ordering operator<=>(const Integer &lhs, const Integer &rhs) {
        if (lhs.size() != rhs.size()) {
            return lhs.size() <=> rhs.size();
        }
        for (int i = lhs.size() - 1; i >= 0; --i) {
            if (lhs.data[i] != rhs.data[i]) {
                return lhs.data[i] <=> rhs.data[i];
            }
        }
        return std::strong_ordering::equal;
    }
    friend bool operator==(const Integer &lhs, const Integer &rhs) {
        return lhs.data == rhs.data;
    }

    Integer &operator+=(const Integer &lhs) {
        int n = std::max(size(), lhs.size());
        resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (i < lhs.size()) {
                data[i] += lhs.data[i];
            }
            if (data[i] > 9) {
                data[i] -= 10;
                data[i + 1] += 1;
            }
        }
        remove_leading_zero();
        return *this;
    }

    Integer &operator-=(const Integer &lhs) {
        assert(*this >= lhs);
        int n = std::max(size(), lhs.size());
        for (int i = 0; i < n; ++i) {
            if (i < lhs.size()) {
                data[i] -= lhs.data[i];
            }
            if (data[i] < 0) {
                data[i] += 10;
                data[i + 1] -= 1;
            }
        }
        remove_leading_zero();
        return *this;
    }

    Integer &operator*=(const Integer &lhs) {
        Integer res;
        res.resize(size() + lhs.size(), 0);
        for (int i = 0; i < size(); i++) {
            for (int j = 0; j < lhs.size(); j++) {
                res.data[i + j] += data[i] * lhs.data[j] ;
                if (res.data[i + j] > 9) {
                    res.data[i + j + 1] += res.data[i + j] / 10;
                    res.data[i + j] %= 10;
                }
            }
        }
        *this = res;
        remove_leading_zero();
        return *this;
    }

    Integer &operator/=(const Integer &lhs) {
        assert(lhs != Integer(0));
        if (lhs > *this) {
            *this = Integer(0);
            return *this;
        }
        Integer res, tmp;
        res.resize(size(), 0);
        int dif = size() - lhs.size();
        tmp.data.insert(tmp.data.begin(), data.begin() + dif + 1, data.end());
        for (int i = dif; i >= 0; i--) {
            tmp.data.push_front(data[i]);
            tmp.remove_leading_zero();
            int ans = 0;
            for (int j = 1; j <= 9; j++) {
                if (tmp >= lhs * Integer(j)) {
                    ans = j;
                } else {
                    break;
                }
            }
            res.data[i] = ans;
            tmp -= lhs * Integer(ans);
        }
        *this = res;
        remove_leading_zero();
        return *this;
    }

    friend Integer operator+(const Integer &lhs, const Integer &rhs) {
        Integer res = lhs;
        res += rhs;
        return res;
    }
    friend Integer operator-(const Integer &lhs, const Integer &rhs) {
        Integer res = lhs;
        res -= rhs;
        return res;
    }
    friend Integer operator*(const Integer &lhs, const Integer &rhs) {
        Integer res = lhs;
        res *= rhs;
        return res;
    }
    friend Integer operator/(const Integer &lhs, const Integer &rhs) {
        Integer res = lhs;
        res /= rhs;
        return res;
    }
};