#include "Database.hpp"

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
}

Person* Database::findPersonWithSurname(std::string surname_)
{
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
