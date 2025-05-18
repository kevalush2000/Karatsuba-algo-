#include "karatsuba.hpp"
#include <algorithm>

std::string add(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    int maxLength = std::max(a.length(), b.length());
    for (int i = 0; i < maxLength || carry; ++i) {
        int sum = carry;
        if (i < a.length()) sum += a[a.length() - 1 - i] - '0';
        if (i < b.length()) sum += b[b.length() - 1 - i] - '0';
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string multiply_single(const std::string& x, const std::string& y) {
    int result = (x[0] - '0') * (y[0] - '0'); // Single digit multiplication
    return std::to_string(result);
}

std::string karatsuba_standard(const std::string& x, const std::string& y) {
    if (x.size() == 1 && y.size() == 1)
        return multiply_single(x, y);

    int n = std::max(x.size(), y.size());
    if (n % 2 != 0) ++n;

    std::string x_padded = std::string(n - x.size(), '0') + x;
    std::string y_padded = std::string(n - y.size(), '0') + y;

    int m = n / 2;
    std::string x1 = x_padded.substr(0, m);
    std::string x0 = x_padded.substr(m);
    std::string y1 = y_padded.substr(0, m);
    std::string y0 = y_padded.substr(m);

    std::string z0 = karatsuba_standard(x0, y0);
    std::string z1 = karatsuba_standard(add(x0, x1), add(y0, y1));
    std::string z2 = karatsuba_standard(x1, y1);

    std::string r1 = z2 + std::string(2 * (n - m), '0');
    std::string r2 = add(z1, "-" + add(z2, z0)) + std::string(n - m, '0');
    return add(add(r1, r2), z0);
}

std::string karatsuba_optimized(const std::string& x, const std::string& y) {
    return karatsuba_standard(x, y); // Placeholder for true in-place/lazy optimization
}
