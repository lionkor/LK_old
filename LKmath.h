// Copyright Lion Kortlepel 2019, licensed under MIT.
#ifndef LKMATH_H
#define LKMATH_H

#include <vector>
#include <cmath>

namespace LK
{

namespace math
{

template<typename _T>
_T standard_deviation(const std::vector<_T>& vec, _T mean)
{
    std::vector<_T> others(vec.size());
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        others[i] = (vec[i] - mean) * (vec[i] - mean);
    }
    _T others_sum = 0;
    for (const auto& o : others)
        others_sum += o;
    return static_cast<_T>(sqrt(others_sum / others.size()));
}

template<typename _T>
_T mean(const std::vector<_T>& vec)
{
    _T sum = 0;
    for (const auto& t : vec)
    {
        sum += t; 
    }
    return sum / vec.size();
}

}

}

#endif // LKMATH_H
