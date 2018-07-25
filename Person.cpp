#include "Person.hpp"

Person::Person(std::string name_, std::string surname_, int PESEL_, char sex_, std::string address_) :
    name(name_),
    surname(surname_),
    PESEL(PESEL_),
    sex(sex_),
    address(address_)
{}

std::string Person::getSurname() const
{
    return surname;
}

std::string Person::getName() const
{
    return name;
}

int Person::getPESEL() const
{
    return PESEL;
}

void Person::setAddress(std::string address_)
{
}
    
bool Person::checkPESEL(int PESEL_) 
{
}

Person::~Person() {}
