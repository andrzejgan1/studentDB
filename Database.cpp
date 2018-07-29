#include "Database.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random> 
#include "Student.hpp"
#include "Worker.hpp"

void Database::addPerson(Person* person)
{
    persons_.push_back(person);
}

void Database::sortByPayment()
{
    std::sort(persons_.begin(), persons_.end(),
                    [](const Person *person1_, const Person *person2_){
                    return person1_->getPayment() < person2_->getPayment();
                });
}

void Database::sortByPESEL()
{
    std::sort(persons_.begin(), persons_.end(),
                    [](const Person *person1_, const Person *person2_){
                    return person1_->getPESEL() < person2_->getPESEL();
                });
} 

void Database::sortBySurname()
{
    std::sort(persons_.begin(), persons_.end(),
                    [](const Person *person1_, const Person *person2_){
                    return person1_->getSurname() < person2_->getSurname();
                });
}

void Database::removePersonWithPESEL(const std::string & PESEL)
{
}

Person* Database::findPersonWithPESEL(const std::string & PESEL)
{
    auto iter = std::find_if(begin(persons_), end(persons_),
                    [PESEL](const auto & person_){
                    return person_->getPESEL() == PESEL;
                });
    return *iter;
}

Person* Database::findPersonWithSurname(const std::string & surname)
{
    auto iter = std::find_if(begin(persons_), end(persons_),
                    [surname](const auto & person_){
                    return person_->getSurname() == surname;
                });
    return *iter;
}
    
void Database::changeAddressPaymentPersonWithPESEL(const std::string & PESEL, const std::string & address, int payment)
{
}
    
void Database::showDB()
{
    system("clear");
    if (persons_.empty())
    {
        std::cout << "Database is empty!" << std::endl;
        return;
    }
    std::cout << std::left << std::setw(20)
              << "PESEL" << std::setw(20)
              << "Name" << std::setw(20)
              << "Surname" << std::setw(20)
              << "Sex" << std::setw(40)
              << "Address" << std::setw(20)
              << "Index number" << std::setw(20)
              << "Payment" << std::endl;
    std::cout.fill('=');
    std::cout << std::setw(150) << "=" << std::endl;
    std::cout.fill(' ');
    for ( auto it : persons_ )
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
    
void Database::fillDB(int numberOfStudnets, int numberOfWorkers)
{
    int index = 0, payment = 0;
    std::string name, surname, address, PESEL;
    char sex;
    while (numberOfStudnets--)
    {
        getData(name, surname, address, sex, PESEL); 
        int index = getRandom(10000, 100000);
        Person *student = new Student(name, surname, PESEL, sex, address, index);
        addPerson(student);
    }
    while (numberOfWorkers--)
    {
        getData(name, surname, address, sex, PESEL); 
        int payment = getRandom(3000, 15000);
        Person *worker = new Worker(name, surname, PESEL, sex, address, payment);
        addPerson(worker);
    }
}

int Database::getRandom(int min, int max) const
{
    std::random_device rd;
    std::mt19937_64  mersenne(rd());                   
    std::uniform_int_distribution<> die(min, max);
    return die(mersenne);
}

void Database::getData(std::string & name, 
                       std::string & surname, 
                       std::string & address, 
                       char & sex, 
                       std::string & PESEL) const 
{
    std::vector<std::string> names = {"Anna", "Kasia", "Marek", 
                                      "Zuzanna", "Tomek", "Malgorzata", 
                                      "Kamil", "Jan", "Marta", 
                                      "Piotr", "Bogdan"};
    std::vector<std::string> surnames = {"Nowak", "Dudzik", 
                                         "Jakimiszyn", "Adamczyk", 
                                         "Jackiewicz", "Lis", 
                                         "Owczarek", "Borowek"};
    std::vector<std::string> cities = {"Krakow", "Wroclaw", 
                                       "Poznan", "Szczecin", 
                                       "Warszawa", "Opole", 
                                       "Lodz"};
    std::vector<std::string> streets = {"Ciepla", "Krakowska", 
                                        "Piekna", "Opolska", 
                                        "Dluga", "Zielinskiego", 
                                        "Borowska"};
    PESEL = std::to_string(getRandom(100000, 999999));
    PESEL += std::to_string(getRandom(10000, 99999));
    name = names[getRandom(0, names.size() - 1)];
    surname = surnames[getRandom(0, surnames.size() - 1)];
    address = cities[getRandom(0, cities.size() - 1)] + ", " 
            + streets[getRandom(0, streets.size() - 1)] + " " 
            + std::to_string(getRandom(1,100));
    sex = name.back() == 'a'? 'W' : 'M';
}

Database::~Database()
{
    for (auto it : persons_)
    {
        delete it;
    }
}
