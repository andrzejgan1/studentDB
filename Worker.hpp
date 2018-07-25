#pragma once
#include <string>
#include "Person.hpp"

class Worker : public Person
{
    int payment_;
public:
    Worker(std::string name, std::string surname, int PESEL, char sex, std::string address, int payment);
    int getPayment() const override;
    void setPayment(int payment) override;
    ~Worker();
};
