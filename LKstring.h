// Copyright Lion Kortlepel 2019, licensed under MIT.
#ifndef LKSTRING_H
#define LKSTRING_H

#include <vector>
#include <string>

namespace LK
{ namespace string {

std::vector<std::string> split(const std::string& str, char delim);

std::string left_trim(const std::string& str, char trim = ' ');
std::string right_trim(const std::string& str, char trim = ' ');
std::string trim(const std::string& str, char trim = ' ');

std::string replace(const std::string& str, const std::string& to_replace, const std::string& replace_with);
std::string replace(const std::string& str, char to_replace, char replace_with);

bool starts_with(const std::string& str, char c);
bool ends_with(const std::string& str, char c);

std::vector<std::string> trim_empty_elements(const std::vector<std::string>& str);
std::vector<std::string> trim_empty_pairs(const std::vector<std::string>& str);

}}

#endif // LKSTRING_H
