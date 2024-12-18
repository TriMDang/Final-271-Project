#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

#include <iostream>
#include <exception>
#pragma once

using namespace std;

class index_exception: public exception{
    public:
        const char* what() const noexcept override{
            return "Operation failed: Index out of bounds.";
        }
};

#endif
