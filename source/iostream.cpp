#include "iostream.hpp"
#include <cstdio>
#include <cstring>
#include <iostream>


//writing some sort of macro 'cause of I don't want the code unreadable
#define OSTREAM dlang::streams::ostream
#define ISTREAM dlang::streams::istream
#define settle default



//ostream startup
OSTREAM::ostream()  = settle; //ostream ctor
OSTREAM::~ostream() = settle; //ostream dtor

//istream startup
ISTREAM::istream()  = settle; //istream ctor
ISTREAM::~istream() = settle; //istream dtor



//let's define ostream first
OSTREAM &OSTREAM::operator<< (const int &text)         { std::printf("%d",  text);                    return *this; } //int -> %d
OSTREAM &OSTREAM::operator<< (const bool &text)        { std::printf("%s",  text ? "true" : "false"); return *this; } //bool -> I use %s and ?:
OSTREAM &OSTREAM::operator<< (const char &text)        { std::printf("%c",  text);                    return *this; } //char -> %c
OSTREAM &OSTREAM::operator<< (const float &text)       { std::printf("%f",  text);                    return *this; } //single -> %f
OSTREAM &OSTREAM::operator<< (const double &text)      { std::printf("%lf", text);                    return *this; } //double -> %lf (like lo-fi)
OSTREAM &OSTREAM::operator<< (const char *text)        { std::printf("%s",  text);                    return *this; } //const char * -> %s
OSTREAM &OSTREAM::operator<< (const std::string &text) { std::printf("%s",  text.c_str());            return *this; } //std::string -> %s c_str()



//now define istream
void ISTREAM::operator>> (int &var)         const { std::scanf("%d",  &var);             } //int
void ISTREAM::operator>> (char &var)        const { std::scanf("%c",  &var);             } //char
void ISTREAM::operator>> (float &var)       const { std::scanf("%f",  &var);             } //single
void ISTREAM::operator>> (double &var)      const { std::scanf("%lf", &var);             } //double

void ISTREAM::operator>> (std::string &var) const { std::getline(std::cin, var);         } //std::string

