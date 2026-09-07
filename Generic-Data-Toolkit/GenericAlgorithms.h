#pragma once
#include <vector>
#include <iostream>

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
