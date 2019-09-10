// Copyright Lion Kortlepel 2019, licensed under MIT.
#ifndef LKTIME_H
#define LKTIME_H

#include <vector>
#include <chrono>
#include <utility>
#include "LKmath.h"

namespace LK
{

namespace time
{

/// @name time_me
/// @brief Measures a function's execution time 'n' times and returns mean and standard 
///     deviation in milliseconds. Measuring occurs in nanosecond resolution.
template<typename _Fnc, typename ..._Args>
std::pair<double, double> time_me(_Fnc fnc, std::size_t n, _Args ...args)
{
    using namespace std::chrono;
    std::vector<double> times(n);
    
    for (std::size_t i = 0; i < n; ++i)
    {
        auto start = high_resolution_clock::now();
        
        fnc(args...);
        
        times.at(i) = (high_resolution_clock::now() - start).count() / 1000000.0;
#ifdef LK_DEBUG_TIME_ME_FN
        printf("%.10g\n", times.at(i));
#endif
    }
    
    double mean = LK::math::mean(times);
    double std_dev = LK::math::standard_deviation(times, mean);
    
    //printf("Result:\n  Mean: %.10gms\n  Standard Deviation: %.10gms\n", mean, std_dev);
    return { mean, std_dev };
}

}

}


#endif // LKTIME_H
