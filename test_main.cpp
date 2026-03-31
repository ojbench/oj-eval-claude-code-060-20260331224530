#include <iostream>
#include <string>
#include "src.hpp"

int main() {
    // Test 1: Basic range check
    int num = 200;
    if (expect(num).ge(114).lt(514).Not().toBe(321)) {
        std::cout << "Test 1 passed: num is in range [114, 514) and != 321" << std::endl;
    } else {
        std::cout << "Test 1 failed" << std::endl;
    }

    // Test 2: toBeOneOf
    std::vector<int> options;
    options.push_back(1);
    options.push_back(2);
    options.push_back(3);
    int val = 2;
    if (expect(val).toBeOneOf(options)) {
        std::cout << "Test 2 passed: val is one of {1, 2, 3}" << std::endl;
    } else {
        std::cout << "Test 2 failed" << std::endl;
    }

    // Test 3: String comparison
    std::string str = "hello";
    if (expect(str).toBe(std::string("hello"))) {
        std::cout << "Test 3 passed: str equals 'hello'" << std::endl;
    } else {
        std::cout << "Test 3 failed" << std::endl;
    }

    // Test 4: Not with multiple conditions
    int x = 5;
    if (expect(x).Not().toBe(1).toBe(2)) {
        std::cout << "Test 4 passed: x != 1 && x != 2" << std::endl;
    } else {
        std::cout << "Test 4 failed" << std::endl;
    }

    // Test 5: Failed condition
    int y = 100;
    if (!expect(y).ge(200)) {
        std::cout << "Test 5 passed: y < 200 (should fail validation)" << std::endl;
    } else {
        std::cout << "Test 5 failed" << std::endl;
    }

    // Test 6: Multiple comparisons
    int z = 50;
    if (expect(z).ge(10).le(100).gt(30).lt(80)) {
        std::cout << "Test 6 passed: 10 <= z <= 100 && 30 < z < 80" << std::endl;
    } else {
        std::cout << "Test 6 failed" << std::endl;
    }

    return 0;
}
