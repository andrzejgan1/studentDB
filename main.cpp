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
                REQUIRE_THROWS_WITH(*(db.findPersonWithPESEL("123")),"Database is empty!");
            }
            GIVEN("Fill the database random data 15 students and 18 workers")
            {
                db.fillDB(15, 18);
                THEN("Finding person with PESEL - 123 - no in the database")
                {
                    REQUIRE_THROWS_WITH(*(db.findPersonWithPESEL("123")),"There is no person with PESEL - 123 in the database");
                }
                WHEN("Added person to database")
                {
                    std::shared_ptr<Person> student = std::make_shared<Student>("Katarzyna", "Nowak", "12345678901", 'W', "Wroclaw, Staszica 12", 99789);
                    db.addPerson(student);
                    THEN("Finding person with PESEL - 12345678901 - existe in the database")
                    {
                        REQUIRE(*(db.findPersonWithPESEL("12345678901")) == student);
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

TEST_CASE("Testing sort")
{
    SECTION("Sorting persons by PESEL")
    {
        GIVEN("A empty database")
        {
            Database db;
            WHEN("Sorting persons by PESEL in empty database")
            {
                REQUIRE_THROWS_WITH(db.sortByPESEL(), "Database is empty!");
            }
            GIVEN("Fill the database random data 15 students and 18 workers")
            {
                db.fillDB(15, 18);
                THEN("Sort person by PESEL in database")
                {
                    db.sortByPESEL();
                    std::vector<std::shared_ptr<Person>>::iterator iter = db.getFirstIterOfPerson();
                    for (int i = 0; i < db.getNumberOfPersons()-1; i++)
                    {
                        REQUIRE((*iter)->getPESEL() < (*(iter+1))->getPESEL());
                        iter++;
                    }
                }
            }
        }
    }
    SECTION("Sorting persons by surname")
    {
        GIVEN("A empty database")
        {
            Database db;
            WHEN("Sorting persons by surname in empty database")
            {
                REQUIRE_THROWS_WITH(db.sortBySurname(), "Database is empty!");
            }
            GIVEN("Fill the database random data 15 students and 18 workers")
            {
                db.fillDB(15, 18);
                THEN("Sort person by surname in database")
                {
                    db.sortBySurname();
                    std::vector<std::shared_ptr<Person>>::iterator iter = db.getFirstIterOfPerson();
                    for (int i = 0; i < db.getNumberOfPersons()-1; i++)
                    {
                        REQUIRE((*iter)->getSurname() <= (*(iter+1))->getSurname());
                        iter++;
                    }
                }
            }
        }
    }
    SECTION("Sorting persons by payment")
    {
        GIVEN("A empty database")
        {
            Database db;
            WHEN("Sorting persons by payment in empty database")
            {
                REQUIRE_THROWS_WITH(db.sortByPayment(), "Database is empty!");
            }
            GIVEN("Fill the database random data 15 students and 18 workers")
            {
                db.fillDB(15, 18);
                THEN("Sort person by payment in database")
                {
                    db.sortByPayment();
                    std::vector<std::shared_ptr<Person>>::iterator iter = db.getFirstIterOfPerson();
                    for (int i = 0; i < db.getNumberOfPersons()-1; i++)
                    {
                        REQUIRE((*iter)->getPayment() <= (*(iter+1))->getPayment());
                        iter++;
                    }
                }
            }
        }
    }
}
