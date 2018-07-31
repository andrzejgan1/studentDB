#include "Person.hpp"

Person::Person(const std::string & name, const std::string & surname, const std::string & PESEL, char sex, const std::string & address) :
    name_(name),
    surname_(surname),
    PESEL_(PESEL),
    sex_(sex),
    address_(address)
{}

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

std::string Person::getAddress() const
{
    return address_;
}
    
bool Person::checkPESEL(const std::string & PESEL) 
{
    //needs implementation
    return 1;
}

char Person::getSex() const
{
    return sex_;
}

int Person::getIndex() const
{
    return 0;
}
Person::~Person() {}
