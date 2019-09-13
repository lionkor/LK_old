#include "LKstring.h"
#include <exception>

struct NotImplemented final {};

std::vector<std::string> LK::string::split(const std::string &str, char delim) 
{
    if (str.find(delim) == std::string::npos) return std::vector<std::string>();
    std::vector<std::string> splits {};
    std::size_t pos { 0 };
    const char* cstr = str.c_str();
    for (const char* c = cstr; true; ++c)
    {
        if (*c == delim || *c == '\0') 
        {
            splits.push_back(str.substr(pos, (c - cstr) - pos));
            if (*c == '\0') break;
            pos = ++c - cstr;
        }
    }
    return splits;
}

std::vector<std::string> LK::string::trim_empty_elements(const std::vector<std::string>& str) 
{
    std::vector<std::string> vec { str.size() };
    for (std::size_t i = 0; i < str.size(); ++i)
    {
        if (!str[i].empty()) vec[i] = str[i];
    }
    return vec;
}

std::vector<std::string> LK::string::trim_empty_pairs(const std::vector<std::string>& str) 
{
    std::size_t size = str.size();
    if (size % 2 != 0) size -= 1;
    
    std::vector<std::string> vec { size };
    for (std::size_t i = 0; i < size; i+=2)
    {
        if (!str[i].empty() && !str[i+1].empty()) 
        {
            vec[i] = str[i];
            vec[i+1] = str[i+1];
        }
    }
    return vec;
}

std::string LK::string::left_trim(const std::string& str, char trim) 
{
    const char* p;
    for (p = str.c_str(); *p == trim; ++p);
    return std::string(p);
}

std::string LK::string::right_trim(const std::string& str, char trim) 
{
    const char* c;
    const char* end = &str.c_str()[str.size()-1];
    for (c = end; *c == trim; --c);
    return std::string (str.begin(), str.end() - (end - c));
}

std::string LK::string::trim(const std::string& str, char trim)
{
    return LK::string::right_trim(LK::string::left_trim(str, trim), trim);
    // FIXME: Rewrite to do it manually.
}

std::string LK::string::replace(const std::string& str, const std::string& to_replace, const std::string& replace_with)
{
    throw NotImplemented();
}

std::string LK::string::replace(const std::string& str, char to_replace, char replace_with)
{
    std::string s {};
    for (const char* c = str.c_str(); *c != '\0'; ++c)
    {
        s += *c == to_replace ? replace_with : *c;
    }
    return s;
}

bool LK::string::starts_with(const std::string& str, char c)
{
    if (str.empty()) return false;
    return str[0] == c;
}

bool LK::string::ends_with(const std::string& str, char c)
{
    if (str.empty()) return false;
    return str[str.size()-1] == c;
}
