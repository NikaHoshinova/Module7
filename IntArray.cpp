#include "IntArray.h"
#include <iostream>


IntArray::IntArray(int length) :
    m_length{ length }
{
    //assert(length >= 0);
    if (length < 0)
    {
        throw bad_length();
    }

    if (length > 0)
        m_data = new int[length] {};
}

IntArray::~IntArray()
{
    delete[] m_data;
    cout << "data deleted successfully" << endl;
}

void IntArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int IntArray::getLength() const 
{
    return m_length; 
}

int& IntArray::operator[](int index)
{
    //assert(index >= 0 && index < m_length);
    if (!(index >= 0 && index < m_length))
    {
        throw bad_range();
    }

    return m_data[index];
}

void IntArray::reallocate(int newLength)
{
    erase();

    if (newLength <= 0)
        return;

    m_data = new int[newLength];
    m_length = newLength;
}

void IntArray::resize(int newLength)
{
    if (newLength == m_length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    int* data{ new int[newLength] };

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
        std::copy_n(m_data, elementsToCopy, data);
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
}

IntArray::IntArray(const IntArray& a) : IntArray(a.getLength())
{
    std::copy_n(a.m_data, m_length, m_data);
}

IntArray& IntArray::operator=(const IntArray& a)
{
    if (&a == this)
        return *this;

    reallocate(a.getLength());
    std::copy_n(a.m_data, m_length, m_data);

    return *this;
}

void IntArray::insertBefore(int value, int index)
{
    //assert(index >= 0 && index <= m_length);
    if (!(index >= 0 && index <= m_length))
    {
        throw bad_range();
    }

    int* data{ new int[m_length + 1] };
    std::copy_n(m_data, index, data);
    data[index] = value;
    std::copy_n(m_data + index, m_length - index, data + index + 1);
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntArray::insertAfter(int value, int index)
{
    //assert(index >= 0 && index <= m_length);
    if (!(index >= 0 && index < m_length))
    {
        throw bad_range();
    }

    int* data{ new int[m_length + 1] };
    std::copy_n(m_data, index + 1, data);
    data[index] = value;
    std::copy_n(m_data + index + 1, m_length - index - 1, data + index + 1);
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntArray::remove(int index)
{
    //assert(index >= 0 && index < m_length);
    if (!(index >= 0 && index < m_length))
    {
        throw bad_range();
    }

    if (m_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[m_length - 1] };
    std::copy_n(m_data, index, data);
    std::copy_n(m_data + index + 1, m_length - index - 1, data + index);
    delete[] m_data;
    m_data = data;
    --m_length;
}

int IntArray::searchValue(int value)
{
    for (int i = 0; i < m_length; i++)
    {
        if (m_data[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void IntArray::insertInTheBeginning(int value)
{
    int* data{ new int[m_length + 1] };
    data[0] = value;
    std::copy_n(m_data + 1, m_length - 1, data + 1);
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntArray::insertInTheEnd(int value)
{
    int* data{ new int[m_length + 1] };
    std::copy_n(m_data, m_length, data);
    data[m_length] = value;
    delete[] m_data;
    m_data = data;
    ++m_length;
}