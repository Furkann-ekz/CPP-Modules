#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _value; // Sabit noktalı sayı değeri
    static const int _fractionalBits = 8; // Kesirli kısmı temsil eden bit sayısı

public:
    Fixed();                          // Varsayılan yapıcı
    Fixed(const int value);           // Tam sayıdan başlatıcı
    Fixed(const float value);         // Float'tan başlatıcı
    Fixed(const Fixed& other);        // Kopya yapıcı
    Fixed& operator=(const Fixed& other); // Kopya atama operatörü
    ~Fixed();                         // Yıkıcı

    int getRawBits(void) const;       // Ham değeri döndür
    void setRawBits(int const raw);   // Ham değeri ayarla
    float toFloat(void) const;        // Sabit noktalı değeri float'a dönüştür
    int toInt(void) const;            // Sabit noktalı değeri tam sayıya dönüştür

    // Karşılaştırma operatörleri
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Aritmetik operatörler
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Artırma/Azaltma operatörleri
    Fixed& operator++();    // Ön-ek artırma
    Fixed operator++(int);  // Son-ek artırma
    Fixed& operator--();    // Ön-ek azaltma
    Fixed operator--(int);  // Son-ek azaltma

    // Statik fonksiyonlar
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Çıkış operatörü
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
