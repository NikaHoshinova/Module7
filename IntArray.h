#pragma once
#include "bad_length.h"
#include "bad_range.h"
#include <algorithm>

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;
    IntArray(int length);
    ~IntArray();

    void erase();

    int& operator[](int index);
    int getLength() const;

    void reallocate(int newLength);
    void resize(int newLength);

    IntArray(const IntArray& a);
    IntArray& operator=(const IntArray& a);

    void insertBefore(int value, int index);
    void insertAfter(int value, int index);
    void insertInTheBeginning(int value);
    void insertInTheEnd(int value); //so numb

    void remove(int index);

    int searchValue(int value);
};



