#include "Fixed.hpp"
#include <cmath> // roundf için gerekli

// Daha önceki fonksiyonlar (Fixed::Fixed, getRawBits, vs.) aynı kalacak, o yüzden tekrar etmiyorum.

// Karşılaştırma operatörleri
bool Fixed::operator>(const Fixed& other) const {
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_value != other._value;
}

// Aritmetik operatörler
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value + other._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value - other._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits((this->_value * other._value) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._value == 0) {
        std::cerr << "Division by zero!" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((this->_value << _fractionalBits) / other._value);
    return result;
}

// Artırma ve Azaltma Operatörleri
Fixed& Fixed::operator++() {
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++_value;
    return temp;
}

Fixed& Fixed::operator--() {
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --_value;
    return temp;
}

// Statik Fonksiyonlar
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Çıkış Operatörü
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
