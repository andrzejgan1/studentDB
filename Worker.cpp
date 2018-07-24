#include "Worker.hpp"

Worker::Worker(std::string name_, std::string surname_, int PESEL_, char sex_, std::string address_, int payment_) :
    Person(name_, surname_, PESEL_, sex_, address_),
    payment(payment_)
{}

int Worker::getPayment() const
{
}
    
void Worker::setPayment(int payment_) 
{
}

Worker::~Worker() {}
