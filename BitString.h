#pragma once
#include <cstddef>
#include <initializer_list>
#include <string>
#include <stdexcept>

class BitString {
private:
    size_t size_;
    unsigned char* data_;

public:
    BitString();
    BitString(size_t size, unsigned char value = 0);
    BitString(const std::initializer_list<unsigned char>& bits);
    BitString(const BitString& other);
    BitString(BitString&& other) noexcept;

    ~BitString() noexcept;

    size_t size() const noexcept;

    BitString And(const BitString& other) const;
    BitString Or(const BitString& other) const;
    BitString Xor(const BitString& other) const;
    BitString Not() const;

    std::string ToString() const;
};
