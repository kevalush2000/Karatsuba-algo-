#include "karatsuba.hpp"
#include <iostream>
#include <chrono>

void test_case(const std::string& a, const std::string& b) {
    std::cout << "Inputs: " << a << " * " << b << "\n";

    auto start = std::chrono::high_resolution_clock::now();
    std::string result_standard = karatsuba_standard(a, b);
    auto mid = std::chrono::high_resolution_clock::now();
    std::string result_optimized = karatsuba_optimized(a, b);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Standard Result: " << result_standard << "\n";
    std::cout << "Optimized Result: " << result_optimized << "\n";
    std::cout << "Correct: " << (result_standard == result_optimized ? "Yes" : "No") << "\n";

    std::chrono::duration<double, std::milli> t1 = mid - start;
    std::chrono::duration<double, std::milli> t2 = end - mid;
    std::cout << "Standard Time: " << t1.count() << " ms\n";
    std::cout << "Optimized Time: " << t2.count() << " ms\n\n";
}

int main() {
    std::cout << "Karatsuba Multiplication Test\n\n";
    test_case("1234", "5678");
    test_case("31415926", "27182818");
    test_case("9876543210123456", "1234567890987654");
    return 0;
}
