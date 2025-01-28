#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif