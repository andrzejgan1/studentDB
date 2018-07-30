#pragma once
#include "Person.hpp"
#include <vector>

class Database
{
    std::vector<Person*> persons_;
    int getRandom(int min, int max) const;
    void getData(std::string & name, std::string & surname, std::string & address, char & sex, std::string & PESEL) const;
public:
    void addPerson(Person* person);
    void sortByPESEL();
    void sortBySurname();
    void sortByPayment();
    void removePersonWithPESEL(const std::string & PESEL);
    Person* findPersonWithPESEL(const std::string & PESEL);
    std::vector<Person *> findPersonWithSurname(const std::string & surname);
    void changeAddressPaymentPersonWithPESEL(const std::string & PESEL, const std::string & address, int payment);
    void showDB();
    void saveToFile();
    void readFromFile();
    void fillDB(int numberOfStudnets, int numberOfWorkers);
    void printNamesTable() const;
    void printDataPerson(Person * it) const;
    ~Database();
};
