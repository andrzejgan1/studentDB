#include "Database.hpp"
#include "Student.hpp"
#include <iostream>

int main()
{
    Database db;
std::cout << "I'm tring find PESEL in empty database" << std::endl;
    try
    {
        db.findPersonWithPESEL("123");
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    std::cin.get();
std::cout << "I'm tring find PESEL no exists in database" << std::endl;
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
    Person *student = new Student("Katarzyna", "Nowak", "12345678901", 'W', "Wroclw, Staszica 12", 99789);
        db.addPerson(student);
    try
    {
        Person *person = db.findPersonWithPESEL("12345678901");
        db.printNamesTable();
        db.printDataPerson(person);
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    std::cin.get();
std::cout << "I'm showing the database" << std::endl;
    db.showDB();
    return 0;
}
