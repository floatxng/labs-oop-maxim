#pragma once

#include <initializer_list>
#include <string>
class FiveDigit
{
public:
    FiveDigit();
    FiveDigit(const size_t &n, unsigned char t);
    FiveDigit(const std::initializer_list<unsigned char> &t);
    FiveDigit(const std::string &t);
    FiveDigit(const FiveDigit &other);
    FiveDigit(FiveDigit &&other) noexcept;
    ~FiveDigit() noexcept;

    FiveDigit &operator=(const FiveDigit &other);
    FiveDigit &operator+=(const FiveDigit &other);
    FiveDigit &operator-=(const FiveDigit &other);

    bool operator==(const FiveDigit &other) const;
    bool operator<(const FiveDigit &other) const;
    bool operator>(const FiveDigit &other) const;

    size_t getSize() const;
    unsigned char *getData() const;

private:
    size_t _size;
    unsigned char *_data;

    void isValid(unsigned char digit);
};