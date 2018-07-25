#pragma once
#include "Person.hpp"
#include <vector>

class Database
{
    std::vector<Person*> persons_;
public:
    void addPerson(Person* person);
    void sortByPESEL();
    void sortBySurname();
    void sortByPayment();
    void removePersonWithPESEL(int PESEL);
    Person* findPersonWithPESEL(int PESEL);
    Person* findPersonWithSurname(std::string surname);
    void changeAddressPaymentPersonWithPESEL(int PESEL, std::string address, int payment);
    void showDB();
    void saveToFile();
    void readFromFile();
    void fillDB();
};
