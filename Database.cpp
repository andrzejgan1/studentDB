#include "Database.hpp"
#include <algorithm>

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
