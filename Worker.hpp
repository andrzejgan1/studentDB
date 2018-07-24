#pragma once
#include <string>
#include "Person.hpp"

class Worker : public Person
{
    int payment;
public:
    Worker(std::string name_, std::string surname_, int PESEL_, char sex_, std::string address_, int payment_);
    int getPayment() const override;
    void setPayment(int payment_) override;
    ~Worker();
};
