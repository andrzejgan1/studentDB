#pragma once
#include "Person.hpp"

class Student : public Person
{
    int index;
public:
    Student(std::string name_, std::string surname_, int PESEL_, char sex, std::string address, int index_);
    int getIndex() const;
    int getPayment() const override;
    void setPayment(int payment_) override;
    ~Student();
};
