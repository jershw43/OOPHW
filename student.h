/*Class provided: Student 

Constructor for Student class:
  Student();
  Description: Constructor initializes student objects
  Precondition: none
  Postcondition: none

  void setFirstName
  Description: Set the first name for a student
  Precondition: Must not contain spaces within the name, must be < 15 chars
  Postcondition: none

 void setLastName
  Description: Set the last name for a student
  Precondition: Must not contain spaces within the name, must be < 20 chars
  Postcondition: none

void setID
  Description: Set the student ID for a student
  Precondition: Numeric value between 0 and 20000
  Postcondition: none

  void setGPA
  Description: Set the GPA for a student
  Precondition: Numeric value between 0.0 and 4.0
  Postcondition: none

  Constant Member Functions:

  const char* getFirstName() const;
  Description: Obtain the first name of the student
  Precondition: none
  Postcondition: First name is returned

  const char* getLastName() const;
  Description: Obtain the last name of the student
  Precondition: none
  Postcondition: Last name is returned

  int getID() const;
  Description: Obtain the student ID of the student
  Precondition: none
  Postcondition: Student ID is returned


  float getGPA() const;
  Description: Obtain the GPA of the student
  Precondition: none
  Postcondition: GPA is returned

  void display() const;
  Description: Display all students
  Precondition: There are students in the array to display
  Postcondition: All students are displayed




*/





#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student
{
  public:
    // CONSTRUCTOR
    Student();

    // MODIFICATION MEMBER FUNCTIONS
    void setFirstName(const char[]);
    void setLastName(const char[]);
    void setID(const int);
    void setGPA(const float);
    
    // CONSTANT MEMBER FUNCTIONS
    const char* getFirstName() const;
    const char* getLastName() const;
    int getID() const;
    float getGPA() const;
    void display() const;

  private:
    char firstName[16];
    char lastName[21];
    int  stuID;
    float  GPA;
};

#endif