#include <iostream>
#include <string>
#include "problem.h"

using namespace std;

// Constructors

//Default Constructor
Fraction::Fraction()
{
    whole = 0;
    numerator = 0;
    denominator = 1;
}
//Parameterized Constructor
Fraction::Fraction(int wholeNum, int num, int den)
    : whole(wholeNum), numerator(num), denominator(den) {
}

// Modification member functions (Fraction)
void Fraction::setFrac()
{

    string input;
    //getline makes sure that the entire input is being captured, including spaces
    getline(cin, input);
    whole = 0;
    numerator = 0;
    denominator = 1;
    isNegative = false;
    
    //Find negative sign if it is there
    int start = 0;
    if (input[0] == '-')
    {
        isNegative = true;
        start = 1;
    }
    //To determine a whole number, we need to find where the space is
    size_t spacePos = input.find(' ');
    if (spacePos != string::npos)
    {
        //we are going to substring everything to the left of the space, making it our whole number
        whole = stoi(input.substr(start, spacePos - start));
        
        //We know that stuff to the left of spacePos is the whole number, so we'll find rest of the fraction after the space
        string frac = input.substr(spacePos+1);
        size_t slashPos = frac.find('/');
        if (slashPos != string::npos)
        {
            numerator = stoi(frac.substr(spacePos+1, slashPos));
            denominator = stoi(frac.substr(slashPos+1));
        }
        numerator = whole * denominator + numerator;
        
    }
    //No space entered, process regular fration
    else
    {
        size_t slashPos = input.find('/');
        if (slashPos!= string::npos)
        {
            numerator = stoi(input.substr(start, slashPos - start));
            denominator = stoi(input.substr(slashPos+1));
        }
        else{
            
            //If there's no space found, it's a whole number
                numerator = stoi(input);
                denominator = 1;
        }
        
    }
    if (isNegative)
    {
        numerator = -numerator;
    }
}

// Constant member functions (Fraction)
bool Fraction:: getIsNegative() const
{
    return isNegative;
}

int Fraction::getNumerator(void) const
{
    return numerator;
}

int Fraction::getDenominator(void) const
{
    return denominator;
}
int Fraction:: getWhole(void) const
{
    return whole;
}
// Get GCD
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Reduce function
void Fraction::reduce()
{
    if(numerator != 0 && denominator != 0)
    {
        int gcdValue = gcd(numerator, denominator);

        numerator /= gcdValue;
        denominator /= gcdValue;
    }
}

// Display (Fraction)
void Fraction::display(void) const
{
    if (denominator == 1)
    {
        cout << numerator<< "/" << denominator;
    }
    else
        cout << numerator<< "/" << denominator;
}

Problem::Problem() : left(0, 0, 1), right(0, 0, 1), answer(0, 0, 1) ,temp(0,0,1){}

// Constant member functions (Problem)

Fraction Problem::getLeft(void) const
{
    return left;
}


Fraction Problem::getRight(void) const
{
    return right;
}
Fraction Problem::getAnswer(void) const
{
    return answer;
}

//Modification member functions (Problem)
void Problem::setLeft(int whole, int numerator, int denominator)
{
    left = Fraction(whole,numerator,denominator);
}
void Problem::setRight(int whole, int numerator, int denominator)
{
    right = Fraction(whole,numerator,denominator);
}

Fraction Problem ::addition() 
{
    answer = answer.add(left,right);
    answer.reduce();
    return answer;
   
}

Fraction Problem ::subtract()
{
    answer = answer.sub(left,right);
    answer.reduce();
    return answer;
}

Fraction Problem ::division()
{
    answer = answer.div(left,right);
    answer.reduce();
    return answer;
}
Fraction Problem ::multiply()
{
    answer = answer.mult(left,right);
    answer.reduce();
    return answer;
   
}

void Problem::display(void) const
{
    answer.display();
}




