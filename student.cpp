#include <iostream>
#include "student.h"
#include <string>
#include <cstring>

using namespace std;

// CONSTRUCTOR
//Student type in the scope of the student constructor
Student::Student()
{
    strcpy(firstName, "");
    strcpy(lastName, "");
    stuID = 0;
    GPA = 0.0;
}


// MODIFICATION MEMBER FUNCTIONS
void Student::setFirstName(const char fName[])
{
    if(strlen(fName) <= 15)
    {
        strcpy(firstName, fName);
    }
}


void Student::setLastName(const char lName[])
{
  if(strlen(lName) <= 20)
  {
    strcpy(lastName, lName);
  }
}


void Student::setID(const int ID)
{
  if(ID >= 0 && ID <= 20000)
  {
    stuID = ID;
  }
}


void Student::setGPA(const float gpaVal)
{
  if(gpaVal >= 0.0 && gpaVal <= 4.0)
  {
    GPA = gpaVal;
  }
}


// CONSTANT MEMBER FUNCTIONS
const char* Student::getFirstName() const
{
  return firstName;
}


const char* Student::getLastName() const
{
  return lastName;
}


int Student::getID(void) const
{
  return stuID;
}


float Student::getGPA(void) const
{
  return GPA;
}


void Student::display(void) const
{
  cout << "ID number:" << stuID << " | Name: " << firstName << "  " << lastName << " | GPA: " << GPA << endl;
}