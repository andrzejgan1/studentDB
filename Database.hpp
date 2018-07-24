#pragma once
#include "Person.hpp"
#include <vector>

class Database
{
    std::vector<Person*> persons;
public:
    void addPerson(Person* person_);
    void sortByPESEL();
    void sortBySurname();
    void sortByPayment();
    void removePersonWithPESEL(int PESEL_);
    Person* findPersonWithPESEL(int PESEL_);
    Person* findPersonWithSurname(std::string surname_);
    void changeAddressPaymentPersonWithPESEL(int PESEL_, std::string address_, int payment_);
    void showDB();
    void saveToFile();
    void readFromFile();
    void fillDB();
};
