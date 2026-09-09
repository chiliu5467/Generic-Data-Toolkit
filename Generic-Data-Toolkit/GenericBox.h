#pragma once

template <typename T>
class GenericBox
{
public:
	explicit GenericBox(const T& value) : value_(value) {}
    const T& Get() const { return value_;  }
    void Set(const T& value) { value_ = value; }

private:
    T value_;
};

GenericBox(const char*)->GenericBox<std::string>;
