#include "MiniVector.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
// Task A Constructors and destructor (9 Tests)
MiniVector::MiniVector() : data_(new int[2]), size_(0), capacity_(2) {}

MiniVector::MiniVector(std::size_t count) {
    if (count == 0) {
        data_ = new int[2];
        size_ = 0;
        capacity_ = 2;
    } else {
        data_ = new int[count]();
        size_ = count;
        capacity_ = count;
    }
}

MiniVector::~MiniVector() {
    delete[] data_;
}

// Task B Growth and capacity (30 Tests)
void MiniVector::reserve(std::size_t newCapacity) {
    if (newCapacity >= capacity_) {
        int* newData = new int[newCapacity];
        for (std::size_t i = 0; i < size_; i++) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }
}
void MiniVector::push_back(int value) {
    if (size_ == capacity_) {
        reserve(2 * capacity_);
    }
    data_[size_] = value;
    size_++;
}

// Task C Element access and modification (20 Tests)
int& MiniVector::at(std::size_t count) {
    if (count >= size_) {
        throw std::out_of_range("");
    }
    return data_[count];
}   

const int& MiniVector::at(std::size_t count) const {
    if (count >= size_) {
        throw std::out_of_range("");
    }
    return data_[count];
}

void MiniVector::pop_back() {
    size_--;
}

void MiniVector::clear() {
    size_ = 0;
}

// Task D Rule of Three (29 Tests)
MiniVector::MiniVector(const MiniVector& other) : data_(new int[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
    for (std::size_t i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

MiniVector& MiniVector::operator=(const MiniVector& other) {
    if (this == &other) {
        return *this;
    }
    int* newData = new int[other.capacity_];
    for (std::size_t i = 0; i < other.size_; i++) {
        newData[i] = other.data_[i];
    }
    delete[] data_;
    data_ = newData;
    size_ = other.size_;
    capacity_ = other.capacity_;
    return *this;
}
// Basic 5 Functions
int& MiniVector::operator[](std::size_t count) {
    return data_[count];
}
const int& MiniVector::operator[](std::size_t count) const {
    return data_[count];
}

bool MiniVector::empty() const {
    return size_ == 0;
}

std::size_t MiniVector::size() const {
    return size_;
}

std::size_t MiniVector::capacity() const {
    return capacity_;
}