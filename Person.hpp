#pragma once

#include <string>

class Person
{
    std::string name_;
    std::string surname_;
    std::string PESEL_;
    char sex_;
    std::string address_;
public:
    Person(const std::string & name, const std::string & surname, const std::string & PESEL, char sex, const std::string & address);
    virtual int getPayment() const = 0;
    std::string getName() const;
    std::string getPESEL() const;
    std::string getSurname() const;
    void setAddress(const std::string & address);
    virtual void setPayment(int payment) = 0;
    bool checkPESEL(const std::string & PESEL);
    bool PESELValidator(const std::string& PESEL, int sum);
    std::string getAddress() const;
    char getSex() const;
    virtual int getIndex() const;
    virtual ~Person();
};
