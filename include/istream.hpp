#pragma once


#include <string>

namespace dlang::streams {
    class istream {
    public:
        //will settle as default in iostream.cpp
        istream(); //ctor
        ~istream(); //dtor

        //supported types for dlang::streams::istream
        //int             / single(float) / double
        //std::string    / char

        //all operator>> methods will return void
        void operator>> (int&               var) const; //int
        void operator>> (char&              var) const; //char
        void operator>> (float&             var) const; //float
        void operator>> (double&            var) const; //double

        void operator>> (std::string&       var) const; //std::string
    }; //istream
}