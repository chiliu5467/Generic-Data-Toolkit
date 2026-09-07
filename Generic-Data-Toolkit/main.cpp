#include <iostream>

#include "GenericAlgorithms.h"

void TestGenericAlgorithms()
{
    std::cout << "=== Testing Generic Algorithms ===" << std::endl;

    // 1. 測試 Contains (int)
    {
        std::vector<int> numbers{ 1, 2, 3, 4 };
        bool result = Contains(numbers, 3);
        std::cout << "[Contains<int>] Searching 3 in {1,2,3,4} -> Result: "
            << std::boolalpha << result
            << " (Expected: true)" << std::endl;
    }

    // 2. 測試 Max
    {
        double maxVal = Max<double>(3, 4.5);
        std::cout << "[Max<double>] Max(3, 4.5) -> Result: "
            << maxVal
            << " (Expected: 4.5)" << std::endl;
    }

    // 3. 測試 Contains (string)
    {
        std::vector<std::string> names{ "Alice", "Bob", "Charlie" };
        bool result = Contains<std::string>(names, "Alice");
        std::cout << "[Contains<string>] Searching 'Alice' in names -> Result: "
            << std::boolalpha << result
            << " (Expected: true)" << std::endl;
    }

    std::cout << "==================================" << std::endl;
}

int main()
{
    TestGenericAlgorithms();

    return 0;
}
