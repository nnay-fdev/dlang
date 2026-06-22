#pragma once

//I will not create a file named 'list.cpp'
//'cause will use template for list so cannot create a file named 'list.hpp'

#include <vector>

#include "iostream.hpp"


namespace dlang::dtypes {
    template <typename K>
    class list {
    std::vector<K> data;
        //supported types for defining dlang::dtypes::list<T>
        //std::initializer_list<T>
        //std::vector          <T>
        //T *
    public:
         list(const std::initializer_list<K>& ls): data(ls) {} //ctor
         list(const std::vector          <K>& ls): data(ls) {} //ctor
         list(const                        K* ls): data(ls) {} //ctor
         list()                                  : data({}) {} //ctor
        ~list() = default;

        void push(const K& element) { data.push_back(element); } //push(const K&)
        void  pop(const int &index) { data.erase(index);       } //pop(const int&
        void clera()                { data.clear();            } //clera(void)

        int begin() const { return data.begin(); } //begin(void)
        int   end() const { return data.end();   } //end(void)

        friend streams::ostream &operator<< (streams::ostream &os, const list &ls) {
            os << "{";
            for (const K &element : ls.data)
                os << element << ", ";
            os << "\b\b}";

            return os;
        } //operator<<
    };
} //namespace dlang::dtypes