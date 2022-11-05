#pragma once
#include <clara.hpp>
#include <string>
inline std::string
toString(const clara::Opt& opt)
{
    std::ostringstream oss;
    oss << (clara::Parser() | opt);
    return oss.str();
}
inline std::string
toString(const clara::Parser& p)
{
    std::ostringstream oss;
    oss << p;
    return oss.str();
}
