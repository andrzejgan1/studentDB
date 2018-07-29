#include "Student.hpp"
 
Student::Student(const std::string & name, const std::string & surname, const std::string & PESEL, char sex, const std::string & address, int index) :
    Person(name, surname, PESEL, sex, address),
    index_(index)
{}

int Student::getIndex() const
{
    return index_;
}

int Student::getPayment() const 
{
    return 0;
}
    
void Student::setPayment(int payment) 
{
}

Student::~Student() {}
