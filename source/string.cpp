#include "string.hpp"

#include <algorithm>

#include "list.hpp"


//defining helpful macro
using STRING = dlang::dtypes::string;

template <typename T>
using LIST = dlang::dtypes::list<T>;

using OSTREAM = dlang::streams::ostream;
using ISTREAM = dlang::streams::istream;

#define settle default


//ctor(s)
STRING::string(const char        &text): data({text}) {}
STRING::string(const char        *text): data(text)   {}
STRING::string(const std::string &text): data(text)   {}
STRING::string(): data("") {}

STRING::~string() = settle; //dtor



LIST<STRING> STRING::split(const char &sep) const {
    LIST<STRING> result;
    std::string temp = data;

    while (temp.find(sep) != std::string::npos) {
        result.push(temp.substr(0, temp.find(sep)));
        temp.erase(temp.find(sep));
    }
    result.push(temp);

    return result;
}
     STRING  STRING::strip(const char &del) const {
    std::string result = data;

    for (int i = 0; i < 2; ++i) {
        for (const char &c : result) {
            if (c == del) result = result.substr(1);
            else          break;
        }
        std::ranges::reverse(result.begin(), result.end());
    }

    return result;
}


auto STRING::begin() const { return data.begin(); }
auto STRING::  end() const { return data.end(); }


const char *STRING::c_str() const { return data.c_str(); }


namespace dlang::dtypes {
    OSTREAM &operator<< (      OSTREAM &os, const string &text) { return os << text.c_str(); }
    void     operator>> (const ISTREAM &is,       string &text) {        is >> text.data;    }
} //namespace dlang::dtypes