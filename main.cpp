#include "Database.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include <iostream>

int main()
{
    Database db;
    
    std::cout << "I try find person with PESEL - 123 - in empty database" << std::endl;
    try
    {
        db.findPersonWithPESEL("123");
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    std::cin.get();
    
    try
    {
        db.fillDB(15, 18);
        std::shared_ptr<Person> student = std::make_shared<Student>("Katarzyna", "Nowak", "12345678901", 'W', "Wroclaw, Staszica 12", 99789);
        db.addPerson(student);
        std::cout << "Show database" << std::endl;
        db.showDB();
        std::cin.get();
        std::cout << "Find data pesron with PESEL - 12345678901" << std::endl;
        std::shared_ptr<Person> foundPerson = *(db.findPersonWithPESEL("12345678901"));
        db.printNamesTable();
        db.printDataPerson(foundPerson);
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    std::cin.get();
    
    try
    {
        std::cout << "Find persons with surname - Lis" << std::endl;                
        std::vector<std::shared_ptr<Person>> personsWithSurnames = db.findPersonWithSurname("Lis");
        db.printNamesTable();
        for (auto person : personsWithSurnames)
        {
            db.printDataPerson(person);
        }
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    std::cin.get();

    try
    {
        std::cout << "Sort person by PESEL in database" << std::endl;
        db.sortByPESEL();
        db.showDB();
        std::cin.get();

        std::cout << "Sort person by surname in database" << std::endl;
        db.sortBySurname();
        db.showDB();
        std::cin.get();

        std::cout << "Sort person by payment in database" << std::endl;
        db.sortByPayment();
        db.showDB();
        std::cin.get();
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }

    try
    {
        std::cout << "Save and read database to file" << std::endl;
        db.saveToFile();
        db.readFromFile();
        db.showDB();
    }
    catch(const std::exception & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    return 0;
}
