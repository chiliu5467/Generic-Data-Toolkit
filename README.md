# Generic Data Toolkit

A small C++17 project for practicing generic programming with function templates, class templates, template argument deduction, and mixed-type operations.

The project explores how reusable C++ interfaces can work across different types while also demonstrating the type requirements and compile-time behavior of templates.

## Concepts Practiced

- Function templates
- Class templates
- Template argument deduction
- Class Template Argument Deduction (CTAD)
- Multiple template type parameters
- `auto` return type deduction
- `std::common_type_t`
- Const references
- Generic programming and type requirements
- Header-only template implementation

## Features

### Generic Algorithms

`GenericAlgorithms.h` provides reusable function templates for common operations.

~~~cpp
Max(10, 20);
Min(10, 20);

std::vector<int> numbers{ 1, 2, 3, 4 };
Contains(numbers, 3);
~~~

`Max` and `Min` use a single template type parameter, meaning both arguments must allow the compiler to deduce the same `T`.

For operations involving different input types, the project also explores multiple template parameters:

~~~cpp
MaxValue(10, 20.5);
~~~

Here, the compiler can independently deduce:

~~~text
T = int
U = double
~~~

The project also experiments with `std::common_type_t` to explicitly determine a common result type for mixed-type operations.

### GenericBox

`GenericBox<T>` is a simple class template that can store values of different types using the same class design.

~~~cpp
GenericBox<int> intBox(42);

std::cout << intBox.Get();

intBox.Set(100);
~~~

The same class template can also store strings:

~~~cpp
GenericBox<std::string> stringBox("Hello");

stringBox.Set("World");
~~~

It can also store user-defined types:

~~~cpp
struct Task
{
    int id;
    std::string name;
};

Task task{ 1, "Learn Templates" };
GenericBox<Task> taskBox(task);
~~~

This demonstrates that a class template can work with both built-in and user-defined types as long as the operations required by the template are valid for that type.

## Template Argument Deduction

The project compares explicit template arguments with compiler deduction.

~~~cpp
Max<double>(10, 20.5);
~~~

This explicitly specifies the template type, while:

~~~cpp
Max(10, 20);
~~~

allows the compiler to deduce `T` from the arguments.

A single-type template can fail when different arguments produce conflicting deductions:

~~~cpp
Max(10, 20.5);
~~~

The compiler attempts to deduce both `int` and `double` for the same `T`.

Using multiple template parameters allows the types to be deduced independently:

~~~cpp
MaxValue(10, 20.5);
~~~

In this case:

~~~text
T = int
U = double
~~~

## Class Template Argument Deduction

The project also explores C++17 Class Template Argument Deduction (CTAD).

Instead of explicitly writing:

~~~cpp
GenericBox<int> box(42);
~~~

C++17 can often infer the template argument from the constructor:

~~~cpp
GenericBox box(42);
~~~

which produces a `GenericBox<int>`.

The project also examines edge cases such as string literals, where template deduction may produce an array type rather than `std::string`.

Using:

~~~cpp
GenericBox box(std::string{"Hello"});
~~~

makes the intended type explicit to the deduction process.

## Multiple Template Types

Using multiple template parameters allows a function to accept different argument types:

~~~cpp
template <typename T, typename U>
auto MaxValue(const T& a, const U& b)
{
    return a > b ? a : b;
}
~~~

For example:

~~~cpp
auto result = MaxValue(10, 20.5);
~~~

The compiler deduces:

~~~text
T = int
U = double
~~~

The return expression determines the resulting type. In this case, the conditional expression produces a `double`.

The project also explores `std::common_type_t`:

~~~cpp
template <typename T, typename U>
std::common_type_t<T, U> MaxCommon(const T& a, const U& b)
{
    using Common = std::common_type_t<T, U>;

    return static_cast<Common>(a > b ? a : b);
}
~~~

This provides an explicit common result type for two different input types.

## Project Structure

~~~text
Generic-Data-Toolkit/
├── GenericAlgorithms.h
├── GenericBox.h
└── main.cpp
~~~

### `GenericAlgorithms.h`

Contains generic function templates including:

- `Max<T>()`
- `Min<T>()`
- `Contains<T>()`
- `MaxValue<T, U>()`
- `MaxCommon<T, U>()`

### `GenericBox.h`

Contains the `GenericBox<T>` class template with:

- Constructor
- `Get()`
- `Set()`

### `main.cpp`

Contains test cases demonstrating:

- Generic algorithms with different types
- Template argument deduction
- `GenericBox<T>`
- Class Template Argument Deduction
- User-defined types
- Mixed-type template operations

## What I Learned

This project helped me understand that C++ templates are more than a way to avoid duplicated code.

A template defines generic logic, but the types used to instantiate it must still support the operations required by its implementation.

For example:

~~~cpp
template <typename T, typename U>
~~~

does not mean every possible combination of `T` and `U` will compile.

If the implementation contains:

~~~cpp
a > b
~~~

then the selected types must support a valid comparison.

I also learned to distinguish between:

- Function template argument deduction
- Class Template Argument Deduction (CTAD)
- Template instantiation
- Implicit type conversions inside expressions
- Return type deduction

For example:

~~~cpp
MaxValue(10, 20.5);
~~~

can be understood as several separate steps:

~~~text
Template argument deduction
        ↓
T = int, U = double
        ↓
Template instantiation
        ↓
Expression type conversion
        ↓
Return type deduction
        ↓
double
~~~

Understanding these as separate stages made compiler errors involving templates much easier to reason about.

## Requirements

- C++17 or later
- Visual Studio 2022 or another C++17-compatible compiler

## Build

1. Clone the repository.
2. Open `Generic-Data-Toolkit.sln` in Visual Studio 2022.
3. Build the solution.
4. Run the project to see the template tests.

The project uses header-defined templates so their complete definitions are visible when the compiler instantiates them.
