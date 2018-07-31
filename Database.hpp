#pragma once
#include "Person.hpp"
#include <vector>
#include <memory>

class Database
{
    std::vector<std::shared_ptr<Person>> persons_;
    int getRandom(int min, int max) const;
    void getData(std::string & name, std::string & surname, std::string & address, char & sex, std::string & PESEL) const;
public:
    void addPerson(std::shared_ptr<Person> person);
    void sortByPESEL();
    void sortBySurname();
    void sortByPayment();
    void removePersonWithPESEL(const std::string & PESEL);
    std::shared_ptr<Person> findPersonWithPESEL(const std::string & PESEL);
    std::vector<std::shared_ptr<Person>> findPersonWithSurname(const std::string & surname);
    void changeAddressPaymentPersonWithPESEL(const std::string & PESEL, const std::string & address, int payment);
    void showDB();
    void saveToFile();
    void readFromFile();
    void fillDB(int numberOfStudnets, int numberOfWorkers);
    void printNamesTable() const;
    void printDataPerson(std::shared_ptr<Person> it) const;
    int getNumberOfPersons() const;
    std::vector<std::shared_ptr<Person>>::iterator getFirstIterOfPerson();
};
