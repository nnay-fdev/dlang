#pragma once

#include <list.libx>
#include <string.libx>
#include <dictionary.libx>
#include <iostream.libc>


namespace dlang::utils {
    class list {
    public:
        static int    summary(const dlang::list<int> &list);
        static float  summary(const dlang::list<float> &list);
        static double summary(const dlang::list<double> &list);
    };

    class string {
    public:
        static dtypes::string replace(const dtypes::string &main, const dtypes::string &newstr);
    };
} //namespace dlang::utils