#define CATCH_CONFIG_MAIN 
#include "Database.hpp"
#include "Student.hpp"
#include <iostream>
#include "catch.hpp"


TEST_CASE("Testing find person")
{
    SECTION("Finding person by PESEL")
    {
        GIVEN("A empty database")
        {
            Database db;
            WHEN("Finding person with PESEL - 123 - in empty database")
            {
                REQUIRE_THROWS_WITH(db.findPersonWithPESEL("123"),"Database is empty!");
            }
            GIVEN("Fill the database random data 15 students and 18 workers")
            {
                db.fillDB(15, 18);
                THEN("Finding person with PESEL - 123 - no in the database")
                {
                    REQUIRE_THROWS_WITH(db.findPersonWithPESEL("123"),"There is no person with PESEL - 123 in the database");
                }
                WHEN("Added person to database")
                {
                    std::shared_ptr<Person> student = std::make_shared<Student>("Katarzyna", "Nowak", "12345678901", 'W', "Wroclaw, Staszica 12", 99789);
                    db.addPerson(student);
                    THEN("Finding person with PESEL - 12345678901 - existe in the database")
                    {
                        REQUIRE(db.findPersonWithPESEL("12345678901") == student);
                    }
                }
            }
        }
    }
    SECTION("Finding person by surname")
    {
        GIVEN("A empty database")
        {
            Database db;
            WHEN("Finding person with surname - Kot - in empty database")
            {
                REQUIRE_THROWS_WITH(db.findPersonWithSurname("Kot"),"Database is empty!");
            }
            GIVEN("Fill the database random data 15 students and 18 workers")
            {
                db.fillDB(15, 18);
                THEN("Finding person with surname - Kot - no in the database")
                {
                    REQUIRE_THROWS_WITH(db.findPersonWithSurname("Kot"),"There isn't person with surname Kot");
                }
                THEN("Finding persons with surname - Lis  - existe in the database")
                {
                    std::vector<std::shared_ptr<Person>> personsWithSurnames = db.findPersonWithSurname("Lis");
                    for (auto person : personsWithSurnames)
                    {
                        REQUIRE(person->getSurname() == "Lis");
                    }
                }
            }
        }
    }
}
/*
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
}*/
