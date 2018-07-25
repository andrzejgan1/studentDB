#include "Worker.hpp"

Worker::Worker(std::string name, std::string surname, int PESEL, char sex, std::string address, int payment) :
    Person(name, surname, PESEL, sex, address),
    payment_(payment)
{}

int Worker::getPayment() const
{
    return payment_;
}
    
void Worker::setPayment(int payment) 
{
}

Worker::~Worker() {}
