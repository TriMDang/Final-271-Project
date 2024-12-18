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

class empty_heap: public exception{
    public:
        const char* what() const noexcept override{
            return "Operation failed: Size = 0! Empty.";
        }
};

class invalid_arguments: public exception{
    public:
        const char* what() const noexcept override{
            return "Operation failed: Invalid argument. Perhaps value is bigger than target value?";
        }
};

class invalid_value: public exception{
    public:
        const char* what() const noexcept override{
            return "Operation failed: Value not found in queue";
        }
};


#endif
