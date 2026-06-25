#pragma once


#include "ostream.hpp"
#include <vector>
#include <unordered_map>

namespace dlang::dtypes {
    template <typename F, typename S>
    struct pair {
        F first;
        S second;

        pair(std::pair<F,S> p) : first(p.first), second(p.second) {}

        friend streams::ostream &operator<< (streams::ostream &os, const pair &p) {
            return os << '{' << p.first << ", " << p.second << '}';
        }
    };

    template <typename F, typename S>
    struct dictionary {
    private: std::vector<pair<F,S>> init;
    public:
        std::vector<F> keys;
        std::vector<S> values;

        dictionary(std::initializer_list<pair<F, S>> p) : init(p) {
            for (const pair<F, S> p_element : p) {
                keys.push_back(p_element.first);
                values.push_back(p_element.second);
            }
        }
        dictionary(): keys(), values() {}

        void add(F key, S value) {
            keys.push_back(key);
            values.push_back(value);
            init.push_back(std::pair(key, value));
        }

        friend streams::ostream &operator<< (streams::ostream &os, const dictionary &dict) {
            os << "{";
            for (const pair<F, S> p : dict.init) {
                os << p << ", ";
            }
            os << "\b\b}";
            return os;
        }
    };
} //namespace dlang::dtypes