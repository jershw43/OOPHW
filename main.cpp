#include <iostream>
#include <cstdlib>
#include "problem.h"
#include <string>

using namespace std;

void display_menu()
{
    
    cout << "\n1. Enter Left Fraction" << endl;
    cout << "2. Enter Right Fraction" << endl;
    cout << "3. Add" << endl;
    cout << "4. Subtract" << endl;
    cout << "5. Multiply" << endl;
    cout << "6. Divide" << endl;
    cout << "7. Display" << endl;
    cout << "8. Quit" << endl;
}

int main()
{
    //Initialize variables
    Fraction lf(0,0,1),rf(0,0,1);
    Problem p1;
    
    int choice;
    
    
    do{
        // Display Menu
        display_menu();
        
        // Take in user input
        cout << "Enter one of the options: ";
        cin >> choice;
        //Flushes i/o stream otherwise the menu doesn't work
        cin.ignore(1000, '\n');
        
        
        
        switch(choice)
        {
            case 1:
                cout <<"Enter your left fraction:";
                lf.setFrac();
                //After setting up the fraction, pass it through to Problem
                cout <<"Fraction entered: " << endl;
                lf.display();
                p1.setLeft(lf.getWhole(),lf.getNumerator(),lf.getDenominator());
                cout << endl;
                break;
            case 2:
                cout <<"Enter your right fraction:";
                rf.setFrac();
                cout <<"Fraction entered: " << endl;
                rf.display();
                p1.setRight(rf.getWhole(),rf.getNumerator(),rf.getDenominator());
                cout << endl;
                break;
            case 3:
                p1.addition();
                cout << "The result of addition is: ";
                p1.display();
                cout << endl;
                break;
            case 4:
                p1.subtract();
                cout << "The result of subtraction is: ";
                p1.display();
                cout << endl;
                break;
            case 5:
                p1.multiply();
                cout << "The result of multiplication is: ";
                p1.display();
                cout << endl;
                break;
            case 6:
                p1.division();
                cout << "The result of division is: ";
                p1.display();
                cout << endl;
                break;
            case 7:
                cout << "Your left fraction is: ";
                lf.display();
                cout << "\nYour right fraction is: ";
                rf.display();
                cout << endl;
                break;
            case 8:
                break;
            default:
                if (choice <=0 || choice >8)
                {
                    cout << "Invalid Input. Please Try Again:" << endl;
                }
                
        }
        
    }
    while (choice != 8);
    


    return 0;
}
