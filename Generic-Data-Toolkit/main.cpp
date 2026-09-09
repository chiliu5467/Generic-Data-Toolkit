#include <iostream>
#include <typeinfo>

#include "GenericAlgorithms.h"
#include "GenericBox.h"

struct Task
{
    int id;
    std::string name;
};

void TestGenericAlgorithms()
{
    std::cout << "=== Testing Generic Algorithms ===" << std::endl;

    // 1. Testing Contains (int)
    {
        std::vector<int> numbers{ 1, 2, 3, 4 };
        bool result = Contains(numbers, 3);
        std::cout << "[Contains<int>] Searching 3 in {1,2,3,4} -> Result: "
            << std::boolalpha << result
            << " (Expected: true)" << std::endl;
    }

    // 2. Testing Max
    {
        double maxVal = Max<double>(3, 4.5);
        std::cout << "[Max<double>] Max(3, 4.5) -> Result: "
            << maxVal
            << " (Expected: 4.5)" << std::endl;
    }

    // 3. Testing Min
    {
        double minVal = Min<double>(3, 4.5);
        std::cout << "[Min<double>] Min(3, 4.5) -> Result: "
            << minVal
            << " (Expected: 3)" << std::endl;
    }

    // 4. Testing Contains (string)
    {
        std::vector<std::string> names{ "Alice", "Bob", "Charlie" };
        bool result = Contains<std::string>(names, "Alice");
        std::cout << "[Contains<string>] Searching 'Alice' in names -> Result: "
            << std::boolalpha << result
            << " (Expected: true)" << std::endl;
    }

    std::cout << "==================================" << std::endl;
}

void TestGenericBox()
{
    std::cout << "=== Testing Generic Box ===" << std::endl;
    // 1. Testing GenericBox with int
    {
        GenericBox<int> intBox(42);
        std::cout << "[GenericBox<int>] Get Value: " << intBox.Get()
            << " (Expected: 42)" << std::endl;

        intBox.Set(50);
        std::cout << "[GenericBox<int>] Set Value: " << intBox.Get()
            << " (Expected: 50)" << std::endl;
    }
    // 2. Testing GenericBox with string
    {
        GenericBox<std::string> strBox("Hello, World!");
        std::cout << "[GenericBox<string>] Value: " << strBox.Get()
            << " (Expected: Hello, World!)" << std::endl;

        strBox.Set("Goodbye");
        std::cout << "[GenericBox<string>] Value: " << strBox.Get()
            << " (Expected: Goodbye)" << std::endl;
    }

    //3. Testing GenericBox with custom struct Task
    {
        Task task{ 1, "Complete Assignment" };
        GenericBox<Task> taskBox(task);
        Task retrievedTask = taskBox.Get();
        std::cout << "[GenericBox<Task>] Task ID: " << retrievedTask.id
            << ", Name: " << retrievedTask.name
            << " (Expected: ID=1, Name=Complete Assignment)" << std::endl;
        
        Task newTask{ 2, "Review Code" };
        taskBox.Set(newTask);
        retrievedTask = taskBox.Get();
        std::cout << "[GenericBox<Task>] Task ID: " << retrievedTask.id
            << ", Name: " << retrievedTask.name
            << " (Expected: ID=2, Name=Review Code)" << std::endl;
	}

    //4. Testing CTAD
    {
        GenericBox<int> box1(42); // explicit
        GenericBox box2(42);      // deduction
        std::cout << "box1: " << typeid(box1).name() << '\n';
        std::cout << "box2: " << typeid(box2).name() << '\n';

        GenericBox stringBox1("Hello");
        GenericBox stringBox2(std::string{ "Hello" });
        std::cout << "stringBox1: " << typeid(stringBox1).name() << '\n';
        std::cout << "stringBox2: " << typeid(stringBox2).name() << '\n';
    }
	std::cout << "==============================" << std::endl;
}

int main()
{
    TestGenericAlgorithms();
    TestGenericBox();

    return 0;
}
