#include "Database.hpp"
#include "Student.hpp"
#include "Worker.hpp"

int main()
{
    Database db;
    Student s1("Sandra", "Nowak", 12345, 'W', "Kniaziewicza 8, 50-523 Wroclaw", 12345);
    Worker w1("Bogdan", "Cichy", 55555, 'M', "Dlugopolska 54, 55-557 Wroclaw", 6000);
    db.addPerson(&s1); 
    db.addPerson(&w1); 
    return 0;
}
