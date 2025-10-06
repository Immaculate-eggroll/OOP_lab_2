#include "BitString.h"
#include <sstream>
#include <stdexcept>

BitString::BitString() : size_(0), data_(nullptr) {}

BitString::BitString(size_t size, unsigned char value)
    : size_(size), data_(new unsigned char[size]) {

    if (value != 0 && value != 1)
        throw std::invalid_argument("Битовая строка может содержать только 0 или 1");

    for (size_t i = 0; i < size_; ++i)
        data_[i] = value;
}

BitString::BitString(const std::initializer_list<unsigned char>& bits)
    : size_(bits.size()), data_(new unsigned char[bits.size()]) {

    size_t i = 0;
    for (auto b : bits) {
        if (b != 0 && b != 1)
            throw std::invalid_argument("Бит может быть только 0 или 1");
        data_[i++] = b;
    }
}

BitString::BitString(const BitString& other)
    : size_(other.size_), data_(new unsigned char[other.size_]) {

    for (size_t i = 0; i < size_; ++i)
        data_[i] = other.data_[i];
}

BitString::BitString(BitString&& other) noexcept
    : size_(other.size_), data_(other.data_) {

    other.size_ = 0;
    other.data_ = nullptr;
}

BitString::~BitString() noexcept {
    delete[] data_;
}

size_t BitString::size() const noexcept {
    return size_;
}

BitString BitString::And(const BitString& other) const {
    if (size_ != other.size_)
        throw std::length_error("Размеры строк не совпадают");

    BitString result(size_);
    for (size_t i = 0; i < size_; ++i)
        result.data_[i] = data_[i] & other.data_[i];

    return result;
}

BitString BitString::Or(const BitString& other) const {
    if (size_ != other.size_)
        throw std::length_error("Размеры строк не совпадают");

    BitString result(size_);
    for (size_t i = 0; i < size_; ++i)
        result.data_[i] = data_[i] | other.data_[i];

    return result;
}

BitString BitString::Xor(const BitString& other) const {
    if (size_ != other.size_)
        throw std::length_error("Размеры строк не совпадают");

    BitString result(size_);
    for (size_t i = 0; i < size_; ++i)
        result.data_[i] = data_[i] ^ other.data_[i];

    return result;
}

BitString BitString::Not() const {
    BitString result(size_);
    for (size_t i = 0; i < size_; ++i)
        result.data_[i] = !data_[i];

    return result;
}

std::string BitString::ToString() const {
    std::ostringstream out;
    for (size_t i = 0; i < size_; ++i)
        out << static_cast<int>(data_[i]);
    return out.str();
}

