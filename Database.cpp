#include "Database.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>

void Database::addPerson(Person* person_)
{
    persons.push_back(person_);
}

void Database::sortByPayment()
{
}

void Database::sortByPESEL()
{
} 

void Database::sortBySurname()
{
}

void Database::removePersonWithPESEL(int PESEL_)
{
}

Person* Database::findPersonWithPESEL(int PESEL_)
{
    auto iter = std::find_if(begin(persons), end(persons),
                    [PESEL_](const auto & person){
                    return person->getPESEL() == PESEL_;
                });
    return *iter;
}

Person* Database::findPersonWithSurname(std::string surname_)
{
    auto iter = std::find_if(begin(persons), end(persons),
                    [surname_](const auto & person){
                    return person->getSurname() == surname_;
                });
    return *iter;
}
    
void Database::changeAddressPaymentPersonWithPESEL(int PESEL_, std::string address_, int payment_)
{
}
    
void Database::showDB()
{
    system("clear");
    if (persons.empty())
    {
        std::cout << "Database is empty!" << std::endl;
        return;
    }
    std::cout << std::left << std::setw(20)
              << "PESEL" << std::setw(20)
              << "Name" << std::setw(20)
              << "Surname" << std::setw(20)
              << "Sex" << std::setw(40)
              << "Adress" << std::setw(20)
              << "Index number" << std::setw(20)
              << "Payment" << std::endl;
    std::cout.fill('=');
    std::cout << std::setw(150) << "=" << std::endl;
    std::cout.fill(' ');
    for ( auto it : persons )
    {
    std::cout << std::left << std::setw(20)
              << (it)->getPESEL() << std::setw(20)
              << (it)->getName() << std::setw(20)
              << (it)->getSurname() << std::setw(20)
              << (it)->getSex() << std::setw(40)
              << (it)->getAddress() << std::setw(20)
              << (it)->getIndex() << std::setw(20)
              << (it)->getPayment() << std::endl;
    }
}

void Database::saveToFile()
{
}

void Database::readFromFile()
{
}
    
void Database::fillDB()
{
}
