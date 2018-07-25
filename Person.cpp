#include "Person.hpp"

Person::Person(std::string name, std::string surname, int PESEL, char sex, std::string address) :
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

int Person::getPESEL() const
{
    return PESEL_;
}

void Person::setAddress(std::string address)
{
}
    
bool Person::checkPESEL(int PESEL) 
{
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
    return 0;
}
Person::~Person() {}
