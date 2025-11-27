#pragma once
#include <exception>
#include <string>

class MyException : public std::exception {
    std::string msg;
public:
    explicit MyException(const std::string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};
