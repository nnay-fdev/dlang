#include <iostream>
#include "istream.hpp"

#define ISTREAM dlang::streams::istream
#define settle default


//istream startup
ISTREAM::istream()  = settle; //istream ctor
ISTREAM::~istream() = settle; //istream dtor


//now define istream
void ISTREAM::operator>> (int &var)         const { std::scanf("%d",  &var);             } //int
void ISTREAM::operator>> (char &var)        const { std::scanf(" %c",  &var);            } //char
void ISTREAM::operator>> (float &var)       const { std::scanf("%f",  &var);             } //single
void ISTREAM::operator>> (double &var)      const { std::scanf("%lf", &var);             } //double

void ISTREAM::operator>> (std::string &var) const { std::getline(std::cin, var);         } //std::string