#pragma once
#include "Person.hpp"
#include <vector>
#include <memory>

using ptr = std::shared_ptr<Person>;
using vec = std::vector<std::shared_ptr<Person>>;
using iterator = std::vector<std::shared_ptr<Person>>::iterator;
using c_str = const std::string &;

class Database
{
    vec persons_;
    int getRandom(int min, int max) const;
    void getData(std::string & name, std::string & surname, std::string & address, char & sex, std::string & PESEL) const;
public:
    void addPerson(ptr person);
    void sortByPESEL();
    void sortBySurname();
    void sortByPayment();
    void removePersonWithPESEL(c_str PESEL);
    iterator findPersonWithPESEL(c_str PESEL);
    vec findPersonWithSurname(c_str surname);
    void changeAddressPaymentPersonWithPESEL(c_str PESEL, c_str address, int payment);
    void showDB();
    void saveToFile();
    void readFromFile();
    void fillDB(int numberOfStudnets, int numberOfWorkers);
    void printNamesTable() const;
    void printDataPerson(ptr it) const;
    int getNumberOfPersons() const;
    iterator getFirstIterOfPerson();
    void sort(std::function<bool(ptr &, ptr &)> what);
    auto find(std::function<bool(ptr &)> what, iterator iter);
};
