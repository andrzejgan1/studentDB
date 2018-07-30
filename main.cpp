#include "Database.hpp"
#include "Student.hpp"
#include <iostream>

int main()
{
    Database db;
std::cout << "I'm tring find PESEL - 123 - in empty database" << std::endl;
    try
    {
        db.findPersonWithPESEL("123");
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    std::cin.get();
std::cout << "I'm tring find PESEL - 123 -  no exists in database" << std::endl;
    db.fillDB(15, 18);
    try
    {
        db.findPersonWithPESEL("123");
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    std::cin.get();
std::cout << "I'm tring find person with PESEL: 12345678901 - which is in database" << std::endl;
std::shared_ptr<Person> student = std::make_shared<Student>("Katarzyna", "Nowak", "12345678901", 'W', "Wroclw, Staszica 12", 99789);
        db.addPerson(student);
    try
    {
        std::shared_ptr<Person> person = db.findPersonWithPESEL("12345678901");
        db.printNamesTable();
        db.printDataPerson(person);
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    std::cin.get();
std::cout << "I'm tring find persons with surname: Kot - no in the database" << std::endl;
    try
    {
        std::vector<std::shared_ptr<Person>> persons = db.findPersonWithSurname("Kot");
        db.printNamesTable();
        for (auto iter : persons)
        {
            db.printDataPerson(iter);
        }
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    std::cin.get();
std::cout << "I'm tring find persons with surname: Lis" << std::endl;
    try
    {        std::vector<std::shared_ptr<Person>> persons = db.findPersonWithSurname("Lis");
        db.printNamesTable();
        for (auto iter : persons)
        {
            db.printDataPerson(iter);
        }
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    std::cin.get();
std::cout << "I'm showing the database" << std::endl;
    db.showDB();
    std::cin.get();
std::cout << "I'm sorting database by PESEL" << std::endl;
    db.sortByPESEL();
    db.showDB();
    std::cin.get();
std::cout << "I'm sorting database by surname" << std::endl;
    db.sortBySurname();
    db.showDB();
    std::cin.get();
std::cout << "I'm sorting database by payment" << std::endl;
    db.sortByPayment();
    db.showDB();
    std::cin.get();
    return 0;
}
