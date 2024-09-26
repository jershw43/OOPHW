#include <iostream>
#include "student.h"
#include <string>
#include "student.cpp"



using namespace std;

const int maxStudents = 30;

// Function Prototypes
void createStudent(Student[], int&);
void deleteStudent(Student[], int&);
void displayAllStudents(const Student[], int);
void searchStudent(const Student[], int);
int findStudentByID(const Student[], int, int);

int main(void)
{
  // Array of students
  Student students[maxStudents];
  int currentStudentCount = 0;

  int choice;

  do
  {
    // Display Menu
    cout << "1. Create new student\n";
    cout << "2. Delete student\n";
    cout << "3. Display all students\n";
    cout << "4. Search for student\n";
    cout << "5. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Menu choices
    switch (choice)
    {
      case 1:
        createStudent(students, currentStudentCount);
        break;
      case 2:
        deleteStudent(students, currentStudentCount);
        break;
      case 3:
        displayAllStudents(students, currentStudentCount);
        break;
      case 4:
        searchStudent(students, currentStudentCount);
      case 5:
        cout << "Quiting";
        break;
      default:
        cout << "Invalid Input Please try again.\n";
    }

  } while (choice != 5);

  return 0;
}

// Create new student
void createStudent(Student students[], int &currentStudentCount)
{
  if(currentStudentCount >= maxStudents)
  {
    cout << "Student list is full\n Please delete a student to add a student.";
    return;
  }

  char firstName[16];
  char lastName[21];
  int stuID;
  float GPA;
  bool valid = false;
  int i = 0;
  // First name error check
  while (!valid)
  {
      cout << "Enter first name: " << endl;
      //clear input stream
      cin.ignore();

      cin >> firstName;
      
      if (strlen(firstName) > 15)
      {
          cout << "First name must be 15 characters or less. Please try again: \n";
          
      }
      else if(strchr(firstName, ' ') != nullptr)
      {
        cout << "First name cannot contain spaces \n";
          
      }
      else
      {
        valid = true;
      }
  }
  valid = false; // Reset for last name
  
  // Last name error check
  while (!valid)
  {
      cout << "Enter last name: " << endl;
      cin >> lastName;
    
      if (strlen(lastName) > 20)
      {
          cout << "Last name must be 20 characters or less. Please try again: \n";
          
      }
      else if (strchr(lastName, ' ') != nullptr)
      {
          cout << "Last name cannot contain spaces. Please try again: " << endl;
      }
      else
      {
    
          valid = true;
      }
  }
  
  valid = false; // Reset for ID
  
  // ID error check
  while (!valid)
  {
      cout << "Enter student ID number: ";
      while(!(cin >> stuID) || cin.peek() != '\n')
   {
     cout << "Please enter a number: ";
     cin.clear();
     cin.ignore(30000, '\n');            
   }
      
      if (stuID <= 0)
      {
        cout << "Student ID must be between 0 and 20000. Please try again: \n";
      }
      else if (stuID >= 20000)
      {
        cout << "Student ID must be between 0 and 20000. Please try again: \n"; 
      }
      else
      {
          valid = true;
      }
  }
  
  valid = false; // Reset for GPA
  
  // GPA error check
  while (!valid)
  {
      cout << "Enter student's GPA: ";
      while(!(cin >> GPA) || cin.peek() != '\n')
   {
     cout << "Please enter a number: ";
     cin.clear();
     cin.ignore(30000, '\n');            
   }
      
      if (GPA < 0.0 || GPA > 4.0)
      {
          cout << "GPA must be between 0.0 and 4.0. Please try again: \n";
      }
      else
      {
          valid = true;
      }
  }

  students[currentStudentCount].setFirstName(firstName);
  students[currentStudentCount].setLastName(lastName);
  students[currentStudentCount].setID(stuID);
  students[currentStudentCount].setGPA(GPA);

  currentStudentCount++;
  cout << "Student added successfully!\n";
}

// Delete student
void deleteStudent(Student students[], int &currentStudentCount)
{
    if(currentStudentCount <= 0)
    {
        cout << "There are no students in this list.\n";
        return;
    }
    
  int ID;
  cout << "Enter the ID of the student to delete: ";
  cin >> ID;

  int index = findStudentByID(students, currentStudentCount, ID);

  if (index != -1) 
  {
    for (int i = index; i < currentStudentCount - 1; i++)
    {
      students[i] = students[i + 1];
    }
    currentStudentCount--;
    cout << "Student deleted successfully.\n";
  } 
  else 
  {
    cout << "Student not found.";
  }

}

// Display all students
void displayAllStudents(const Student students[], int currentStudentCount)
{
  if (currentStudentCount == 0)
  {
    cout << "There are no students in this list.\n";
  }
  else
  {
    for (int i = 0; i < currentStudentCount; i++)
    {
      students[i].display();
    }
  }
}

// Search for student (by ID)
void searchStudent(const Student students[], int currentStudentCount)
{
    if(currentStudentCount <= 0)
    {
        cout << "There are no students in this list.\n";
        return;
    }
    
  int ID;
  cout << "Enter the ID of the student: ";
  cin >> ID;

  int index = findStudentByID(students, currentStudentCount, ID);

  if (index != 1)
  {
    students[index].display();
  }
  else
  {
    cout << "Student not found.\n";
  }
}

// Find a student by ID
int findStudentByID(const Student students[], int currentStudentCount, int ID)
{
  for (int i = 0; i < currentStudentCount; i++)
  {
    if (students[i].getID() == ID)
    {
      return i;
    }
  }
  return 0;
}