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