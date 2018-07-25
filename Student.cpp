#include "Student.hpp"
 
Student::Student(std::string name, std::string surname, int PESEL, char sex, std::string address, int index) :
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
