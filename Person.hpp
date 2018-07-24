#pragma once

#include <string>

class Person
{
    std::string name;
    std::string surname;
    int PESEL;
    char sex;
    std::string address;
public:
    Person(std::string name_, std::string surname_, int PESEL_, char sex_, std::string address_);
    virtual int getPayment() const = 0;
    std::string getName() const;
    int getPESEL() const;
    std::string getSurname() const;
    void setAddress(std::string address_);
    virtual void setPayment(int payment_) = 0;
    bool checkPESEL(int PESEL_);
    virtual ~Person();
};
