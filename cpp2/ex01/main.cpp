#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b(10);          // Tam sayıdan başlatma
    Fixed const c(42.42f);      // Float'tan başlatma
    Fixed const d(b);           // Kopya yapıcı

    a = Fixed(1234.4321f);      // Atama operatörü

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
