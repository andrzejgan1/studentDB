#include "Student.hpp"
 
Student::Student(std::string name_, std::string surname_, int PESEL_, char sex_, std::string address_, int index_) :
    Person(name_, surname_, PESEL_, sex_, address_),
    index(index_)
{}

int Student::getIndex() const
{
    return index;
}

int Student::getPayment() const 
{
    return 0;
}
    
void Student::setPayment(int payment_) 
{
}

Student::~Student() {}
