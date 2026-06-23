#include <iostream>

#include "string.hpp"
#include "iostream.hpp"


int main() {
    dlang::streams::ostream write;
    const dlang::streams::istream read;

    dlang::dtypes::string text_;

    read >> text_;
    const char *text = text_.c_str();

    write << text << '\n' << text_;

    return 0;
}