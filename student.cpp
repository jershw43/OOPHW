#include <iostream>
#include "student.h"

using namespace std;

// CONSTRUCTOR
//Student type in the scope of the student constructor
Student::Student()
{
    fname = cin >> fname;
}


// MODIFICATION MEMBER FUNCTIONS
void Fraction::setsign(const char value)
{
  if(value == '+' || value == '-')
    sign = value;
}


void Fraction::setwhole(const int value)
{
  if(value >= 0)
    whole = value;
}


void Fraction::setnum(const int value)
{
  if(value >= 0)
    num = value;
}


void Fraction::setden(const int value)
{
  if(value > 0)
    den = value;
}


// CONSTANT MEMBER FUNCTIONS
    char Student::getfname (void);
    {
        return fname;
    }

{
  return sign;
}


int Fraction::getwhole(void) const
{
  return whole;
}


int Fraction::getnum(void) const
{
  return num;
}


int Fraction::getden(void) const
{
  return den;
}

