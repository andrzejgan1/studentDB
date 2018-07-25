#pragma once

#include <string>

class Person
{
    std::string name_;
    std::string surname_;
    int PESEL_;
    char sex_;
    std::string address_;
public:
    Person(std::string name, std::string surname, int PESEL, char sex, std::string address);
    virtual int getPayment() const = 0;
    std::string getName() const;
    int getPESEL() const;
    std::string getSurname() const;
    void setAddress(std::string address);
    virtual void setPayment(int payment) = 0;
    bool checkPESEL(int PESEL);
    std::string getAddress() const;
    char getSex() const;
    virtual int getIndex() const;
    virtual ~Person();
};
