#pragma once

#include <string>

namespace dlang::streams {
    class ostream {
    public:
        //will settle as default in iostream.cpp
         ostream(); //ctor
        ~ostream(); //dtor


        //supported types for dlang::streams::ostream
        // int           / single(float) / double      / bool
        // const char * / char          / std::string

        //all operator<< methods will return *this
        ostream &operator<< (const int&         text); //int
        ostream &operator<< (const bool&        text); //boolean
        ostream &operator<< (const char&        text); //char
        ostream &operator<< (const float&       text); //float
        ostream &operator<< (const double&      text); //double

        ostream &operator<< (const char*        text); //const char *
        ostream &operator<< (const std::string& text); //std::string
    }; //ostream
} //namespace dlang::streams