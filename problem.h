// CLASS PROVIDED:
//
// CONSTRUCTOR for the Fraction class:
//   Fraction()
//     Description:        constructor will initialize Fraction objects
//     Preconditions:    none
//     Postcondition:    fraction has been set to +0 0/1

// Parameterized constructor for Fraction class:
//     Description:        constructor will initialize Fraction objects, giving a default fraction
//     Preconditions:    none
//     Postcondition:    fraction has been set to (0,0,1);
//
//
//
//
// MODIFICATION MEMBER FUNCTIONS for the Fraction class
//
//   void setFrac  ()
//     Description:        Sets up the left or right fraction of the problem
//     Precondition:    Denominator >0
//     Postcondition:    Whole number, numerator, and denominator are set
//
//
// CONSTANT MEMBER FUNCTIONS for the Fraction class
//  int getWhole() const
//    Description:        obtain whole part of the fraction
//     Preconditions:    none
//     Postcondition:    whole part of the fraction is returned
//
//  int getNumerator() const;
//     Description:        obtain numerator part of the fraction
//     Preconditions:    none
//     Postcondition:    numerator of the fraction is returned
//
//  int getDenominator() const;
//     Description:        obtain denominator part of the fraction
//     Preconditions:    none
//     Postcondition:    denominator of the fraction is returned
//
//  bool getIsNegative() const;
//     Description:        Determine if the current fraction is negative
//     Preconditions:    none
//     Postcondition:    Boolean determining sign is returned
//
//  void display(void) const;
//     Description:        Display all data from the fraction
//     Preconditions:    none
//     Postcondition:    Data is displayed on screen
//
// CLASS PROVIDED:  Problem
//
// CONSTRUCTOR for the Problem class:
//   Problem()
//     Description:        constructor will initialize Problem objects
//     Preconditions:    none
//     Postcondition:    Problem has a left, right, answer, and temp fraction variable
//
// MODIFICATION MEMBER FUNCTIONS for the Problem class
//
//   Fraction addition();
//     Description:        Add the left and right operand of a problem together
//     Preconditions:    none
//     Postcondition:    Numerator and denominator from result is returned
//
//  Fraction subtract();
//     Description:       subtract the left from the right operand
//     Preconditions:    none
//     Postcondition:    Numerator and denominator from result is returned
//
//  Fraction division();
//     Description:        Divide the left from the right operand
//     Preconditions:    none
//     Postcondition:    Numerator and denominator from result is returned
//
//  Fraction multiply();
//     Description:        Multiply the left and right operands
//     Preconditions:    none
//     Postcondition:    Numerator and denominator from result is returned
//
//  void setLeft(int whole, int numerator, int denominator);
//     Description:        Using the Fraction parameterized constructor, set's the left operand
//     Preconditions:    none
//     Postcondition:    none
//
//  void setRight(int whole, int numerator, int denominator);
//     Description:        Using the Fraction parameterized constructor, set's the right operand
//     Preconditions:    none
//     Postcondition:    none
//
// CONSTANT MEMBER FUNCTIONS for the Fraction class
//  Fraction getLeft(void) const;
//     Description:        Get the left operand for problem
//     Precondition:        none
//     Postcondition:    Left operand is returned
//
//  Fraction getRight(void) const;
//      Description:        Get the right operand for problem
//     Precondition:        none
//     Postcondition:    right operand is returned
//
//  Fraction getAnswer(void) const;
//     Description:        Get the answer for the problem
//     Precondition:        none
//     Postcondition:    none
//
//  void display(void) const;
//     Description:        Display result of the operation
//     Preconditions:    none
//     Postcondition:    result is displayed on screen
//

#include <string>


using namespace std;

#ifndef PROBLEM_H
#define PROBLEM_H


class Fraction
{
    private:
        int whole;
        int numerator;
        int denominator;
        bool isNegative;
        

    public:
        // Constructors
    Fraction();
    Fraction(int wholeNum = 0, int num = 0, int den = 1);
    //Modification Member Functions
        void setFrac();
    
    //Constant Member Functions
        int getWhole() const;
        int getNumerator() const;
        int getDenominator() const;
        bool getIsNegative() const;
        void display(void) const;
    void reduce();
    
    
    //Fraction Functions were found here: https://stackoverflow.com/questions/48256703/c-Fraction-calculator-using-classes-and-functions
    Fraction add(const Fraction& f1,const Fraction& f2) const                // addition fcn
    {
        int newnumerator = (f1.getNumerator()*f2.getDenominator()) + (f2.getNumerator()*f1.getDenominator());
        int newdenominator = f1.getDenominator()*f2.getDenominator();
        return Fraction(0, newnumerator, newdenominator);
    }
    Fraction sub(const Fraction& f1, const Fraction& f2)  const           // subtraction fcn
    {
        int newnumerator = (f1.getNumerator()*f2.getDenominator()) - (f2.getNumerator()*f1.getDenominator());
        int newdenominator = f1.getDenominator()*f2.getDenominator();
        return Fraction(0, newnumerator, newdenominator);
    }
    Fraction mult(const Fraction& f1, const Fraction& f2)     // multiplying fcn
    {
        int newnumerator = f1.getNumerator()*f2.getNumerator();
        int newdenominator = f1.getDenominator()*f2.getDenominator();
        return Fraction(0,newnumerator, newdenominator);
    }
    Fraction div(const Fraction& f1, const Fraction& f2)           // dividing fcn
    {
        int newnumerator = f1.getNumerator()*f2.getDenominator();
        int newdenominator = f1.getDenominator()*f2.getNumerator();
        return Fraction(0,newnumerator, newdenominator);
    }
};

class Problem 
{
    private:
        Fraction left;
        Fraction right;
        Fraction temp;
        Fraction answer;

    public:
        // Constructor
        Problem();
    
    
    //Constant Member Functions
        Fraction getLeft(void) const;
        Fraction getRight(void) const;
        Fraction getAnswer(void) const;
        void display(void) const;
    //Modification Member Functions
        Fraction addition();
        Fraction subtract();
        Fraction division();
        Fraction multiply();
        void setLeft(int whole, int numerator, int denominator);
        void setRight(int whole, int numerator, int denominator);
    

};

#endif
