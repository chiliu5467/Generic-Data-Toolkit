#pragma once
#include <vector>
#include <iostream>
#include <type_traits>

template <typename T>
const T& Max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

template <typename T>
const T& Min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template <typename T>
bool Contains(
    const std::vector<T>& values,
    const T& target)
{
    for (const T& value : values)
    {
        if (value == target)
        {
            return true;
		}
    }
    return false;
}

template <typename T, typename U>
auto MaxValue(const T& a, const U& b)
{
    return a > b ? a : b;
}

template <typename T, typename U>
std::common_type_t<T, U> MaxCommon(const T& a, const U& b)
{
    using Common = std::common_type_t<T, U>;

    return static_cast<Common>(a > b ? a : b);
}
