// Copyright 2023 SomeName

#include "../include/lib.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdexcept>

FiveDigit::FiveDigit() : _size{0}, _data{nullptr} {}

FiveDigit::FiveDigit(const size_t &n, unsigned char t)
{
    isValid(t);
    _size = n;
    _data = new unsigned char[n];
    for (int i = 0; i < n; ++i)
    {
        _data[i] = t;
    }
}

FiveDigit::FiveDigit(const std::initializer_list<unsigned char> &t)
{
    _size = t.size();
    _data = new unsigned char[_size];

    size_t i = 0;
    for (unsigned char digit : t)
    {
        isValid(digit);
        _data[i++] = digit;
    }
}

FiveDigit::FiveDigit(const std::string &t)
{
    _size = t.size();
    _data = new unsigned char[_size];

    for (size_t i = 0; i < _size; i++)
    {
        isValid(t[i]);
        _data[i] = t[i];
    }
}

FiveDigit::FiveDigit(const FiveDigit &other)
{
    _size = other._size;
    _data = new unsigned char[_size];

    for (size_t i = 0; i < _size; ++i)
    {
        _data[i] = other._data[i];
    }
}

FiveDigit::FiveDigit(FiveDigit &&other) noexcept
{
    _size = other._size;
    _data = other._data;
    other._data = nullptr;
    other._size = 0;
}

FiveDigit &FiveDigit::operator=(const FiveDigit &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] _data;
    _size = other._size;
    _data = new unsigned char[_size];

    for (size_t i = 0; i < _size; ++i)
    {
        _data[i] = other._data[i];
    }

    return *this;
}

FiveDigit &FiveDigit::operator+=(const FiveDigit &other)
{
    int remember = 0;

    if (this->_size < other._size)
    {
        this->_data = static_cast<unsigned char *>(std::realloc(this->_data, other._size));
        std::memmove(this->_data + other._size - this->_size, this->_data, this->_size);
        std::memset(this->_data, '0', other._size - this->_size);
        this->_size = other._size;
    }
    for (int i = 0; i < this->_size; i++)
    {
        unsigned char dig1 = this->_data[this->_size - 1 - i];
        unsigned char dig2 = other._size - 1 < i ? '0' : other._data[other._size - 1 - i];

        int num1 = dig1 - '0';
        int num2 = dig2 - '0';
        int number = num1 + num2 + remember;
        remember = number > 4 ? 1 : 0;
        number = number % 5;
        unsigned char result = number + '0';
        this->_data[this->_size - 1 - i] = result;
    }

    if (remember == 1) {
        this->_data = static_cast<unsigned char *>(std::realloc(this->_data, ++this->_size));
        std::memmove(this->_data + 1, this->_data, this->_size);
        this->_data[0] = '1';
    }
    return *this;
}

FiveDigit &FiveDigit::operator-=(const FiveDigit &other)
{
    int remember = 0;

    if (this->_size < other._size) {
        throw std::invalid_argument("Subtraction result is negative");
    }

    for (int i = 0; i < this->_size; i++) {
        unsigned char dig1 = this->_data[this->_size - 1 - i];
        unsigned char dig2 = other._size - 1 < i ? '0' : other._data[other._size - 1 - i];

        int num1 = dig1 - '0';
        int num2 = dig2 - '0';

        int number = num1 - num2 - remember;

        if (number < 0) {
            number += 5;
            remember = 1;
        } else {
            remember = 0;
        }

        unsigned char result = number + '0';
        this->_data[this->_size - 1 - i] = result;
    }

    if (this->_data[0] == '0' && this->_size > 1) {
        std::memmove(this->_data, this->_data + 1, --this->_size);
        this->_data = static_cast<unsigned char *>(std::realloc(this->_data, this->_size));
    }

    if (remember == 1) {
        throw std::invalid_argument("Subtraction result is negative");
    }

    return *this;
}

bool FiveDigit::operator==(const FiveDigit &other) const
{
    if (_size != other._size)
    {
        return false;
    }

    for (size_t i = 0; i < _size; i++)
    {
        if (_data[i] != other._data[i])
        {
            return false;
        }
    }
    return true;
}

bool FiveDigit::operator<(const FiveDigit &other) const
{
    if (_size > other._size)
    {
        return false;
    }

    if (_size < other._size)
    {
        return true;
    }

    for (size_t i = 0; i < _size; i++)
    {
        if (_data[i] < other._data[i])
        {
            return true;
        }
        if (_data[i] > other._data[i])
        {
            return false;
        }
    }
    return false;
}

bool FiveDigit::operator>(const FiveDigit &other) const
{
    return other < *this;
}

size_t FiveDigit::getSize() const
{
    return _size;
}

unsigned char *FiveDigit::getData() const
{
    return _data;
}

FiveDigit::~FiveDigit() noexcept
{
    delete[] _data;
    _data = nullptr;
    _size = 0;
}

void FiveDigit::isValid(unsigned char digit)
{
    if (digit < '0' || digit > '4')
    {
        throw std::invalid_argument("Invalid digit");
    }
}

 