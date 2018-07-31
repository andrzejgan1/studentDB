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

bool Person::PESELValidator(const std::string& PESEL, int sum)
{
    if(PESEL.size() != 11) return false;
    if(sum <= 0) return false;
    return true;

}
    
bool Person::checkPESEL(const std::string & PESEL) 
{
        int numbers[11];
    int sum = 0;

    for(int i=0; i<11; i++)
    {
        numbers[i] = PESEL[i] - 48;
    }

    sum += numbers[0] * 9;
    sum += numbers[1] * 7;
    sum += numbers[2] * 3;
    sum += numbers[3] * 1;
    sum += numbers[4] * 9;
    sum += numbers[5] * 7;
    sum += numbers[6] * 3;
    sum += numbers[7] * 1;
    sum += numbers[8] * 9;
    sum += numbers[9] * 7;
    sum = sum%10;

    if(sum == numbers[10] && PESELValidator(PESEL, sum)) return true;
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
    return 0;
}
Person::~Person() {}
