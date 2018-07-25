#pragma once
#include "Person.hpp"

class Student : public Person
{
    int index_;
public:
    Student(std::string name, std::string surname, int PESEL, char sex, std::string address, int index);
    int getIndex() const override;
    int getPayment() const override;
    void setPayment(int payment) override;
    ~Student();
};
