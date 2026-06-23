#include <cstring>
#include <iostream>

#include "string.hpp"
#include "iostream.hpp"
#include "dictionary.hpp"

int main() {
    dlang::streams::ostream write;
    using string = dlang::dtypes::string;

    dlang::dtypes::dictionary<int, string> dict;
    int i = 0;
    while (true) {
        const dlang::streams::istream read;

        string input;

        write << "enter smth :";
        read >> input;

        if (strcmp(input.c_str(), "end") == 0) break;

        dict.add(i, input);

        i++;
    }
    write << dict;
    return 0;
}