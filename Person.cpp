#include "Person.hpp"
#include <stdexcept>
#include <limits>
#include <iomanip>
#include <iostream>

Person::Person(const std::string & name, const std::string & surname, const std::string & PESEL, char sex, const std::string & address) :
    name_(name),
    surname_(surname),
    sex_(sex),
    address_(address)
{
    if (!Person::checkPESEL(PESEL)) throw std::invalid_argument("Bad PESEL");
    PESEL_ = PESEL;
}

Person::Person(const std::string & packedData) :
    name_(packedData.substr(20,20)),
    surname_(packedData.substr(40,20)),
    sex_(packedData[60]),
    address_(packedData.substr(80,40))
{
    if (!Person::checkPESEL(packedData.substr(0,11))) throw std::invalid_argument("Bad PESEL");
    PESEL_ = packedData.substr(0,11);
}

std::string Person::getSurname() const
{
    return surname_;
}

std::string Person::getName() const
{
    return name_;
}

std::string Person::getPESEL() const
{
    return PESEL_;
}

void Person::setAddress(const std::string & address)
{
    address_ = address;
}

bool Person::checkPESEL(const std::string & PESEL) 
{
    if (PESEL.size() != 11) return false;
    int sum = 0;
    sum = (PESEL[0] - 48) * 9 +
          (PESEL[1] - 48) * 7 +
          (PESEL[2] - 48) * 3 +
          (PESEL[3] - 48) * 1 +
          (PESEL[4] - 48) * 9 +
          (PESEL[5] - 48) * 7 +
          (PESEL[6] - 48) * 3 +
          (PESEL[7] - 48) * 1 +
          (PESEL[8] - 48) * 9 +
          (PESEL[9] - 48) * 7;
    if (sum == 0) return false;
    if ((sum%10) == (PESEL[10] - 48)) return true;
    return false;
}

std::string Person::getAddress() const
{
    return address_;
}

char Person::getSex() const
{
    return sex_;
}

int Person::getIndex() const
{
    return std::numeric_limits<int>::max();
}

Person::~Person() {}

std::string Person::toString() const
{
    std::stringstream ss;
    ss << std::left << std::setw(20)
       << PESEL_ << std::setw(20)
       << name_ << std::setw(20)
       << surname_ << std::setw(20)
       << sex_ << std::setw(40)
       << address_ << std::setw(20)
       << getIndex() << std::setw(20)
       << getPayment() << std::endl;
    return ss.str();
}
