#include "karatsuba.hpp"
#include <algorithm>
#include <iostream>

// Helper: Remove leading zeros
std::string trim_leading_zeros(const std::string& s) {
    size_t pos = s.find_first_not_of('0');
    if (pos == std::string::npos) return "0";
    return s.substr(pos);
}

// Helper: Pad with leading zeros
std::string pad_left(const std::string& s, size_t n) {
    if (s.length() >= n) return s;
    return std::string(n - s.length(), '0') + s;
}

// String addition
std::string add(const std::string& a, const std::string& b) {
    std::string res;
    int carry = 0;
    int n = std::max(a.size(), b.size());
    std::string a_pad = pad_left(a, n);
    std::string b_pad = pad_left(b, n);
    for (int i = n - 1; i >= 0; --i) {
        int sum = (a_pad[i] - '0') + (b_pad[i] - '0') + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry) res.push_back(carry + '0');
    std::reverse(res.begin(), res.end());
    return trim_leading_zeros(res);
}

// String subtraction (assumes a >= b)
std::string subtract(const std::string& a, const std::string& b) {
    std::string res;
    int n = std::max(a.size(), b.size());
    std::string a_pad = pad_left(a, n);
    std::string b_pad = pad_left(b, n);
    int borrow = 0;
    for (int i = n - 1; i >= 0; --i) {
        int diff = (a_pad[i] - '0') - (b_pad[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_back(diff + '0');
    }
    std::reverse(res.begin(), res.end());
    return trim_leading_zeros(res);
}

// Single-digit multiplication
std::string multiply_single(const std::string& x, const std::string& y) {
    int result = (x[0] - '0') * (y[0] - '0');
    return std::to_string(result);
}

// Karatsuba multiplication
std::string karatsuba_standard(const std::string& x, const std::string& y) {
    std::string a = trim_leading_zeros(x);
    std::string b = trim_leading_zeros(y);

    // Base case
    if (a.size() == 1 && b.size() == 1)
        return multiply_single(a, b);

    // Pad to equal even length
    int n = std::max(a.size(), b.size());
    if (n % 2 != 0) ++n;
    a = pad_left(a, n);
    b = pad_left(b, n);

    int m = n / 2;
    std::string a1 = a.substr(0, n - m);
    std::string a0 = a.substr(n - m);
    std::string b1 = b.substr(0, n - m);
    std::string b0 = b.substr(n - m);

    std::string z2 = karatsuba_standard(a1, b1);
    std::string z0 = karatsuba_standard(a0, b0);
    std::string sum_a = add(a1, a0);
    std::string sum_b = add(b1, b0);
    std::string z1 = karatsuba_standard(sum_a, sum_b);
    std::string z1_sub = subtract(subtract(z1, z2), z0);

    // Shift z2 by 2*m, z1_sub by m
    z2 += std::string(2 * m, '0');
    z1_sub += std::string(m, '0');

    std::string result = add(add(z2, z1_sub), z0);
    return trim_leading_zeros(result);
}

// For demonstration, optimized just calls standard
std::string karatsuba_optimized(const std::string& x, const std::string& y) {
    return karatsuba_standard(x, y);
}