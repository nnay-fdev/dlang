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
} //namespace dlang::streams