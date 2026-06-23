#pragma once

#include <string>
#include "list.hpp"
#include "iostream.hpp"


namespace dlang::dtypes {
    class string {
    std::string data;

    public:
        //supported types for defining dlang::dtypes::string
        //char / const char * / std::string
        string(const char        &text);
        string(const char        *text);
        string(const std::string &text);
        string(); //will settle as default in string.cpp

        ~string();

        list<string> split(const char &sep) const;
             string  strip(const char &del) const;

        auto begin() const;
        auto   end() const;

        const char *c_str() const;

        bool operator==  (const string &other) const;
        bool operator!=  (const string &other) const;

        char operator[]  (const int &index)    const;

        string operator+ (const string &other) const;

        void operator+=  (const string &other);

        int size   ()                 const;
        int indexof(const char &find) const;

        friend streams::ostream &operator<< (      streams::ostream &os, const string &text);
        friend void              operator>> (const streams::istream &is,       string &text);
    };
} //namespace dlang::dtypes