#include "snowman.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * AUTHORS: Rotem Halbreich
 * 
 * 
 * {H,N,L,R,X,Y,T,B} -> Snowman's ID
 * 
 * 1. H is for Hat
 * 2. N is for Nose/Mouth
 * 3. L is for Left Eye
 * 4. R is for Right Eye
 * 5. X is for Left Arm
 * 6. Y is for Right Arm
 * 7. T is for Torso
 * 8. B is for Base
 * 
 * Output:
 * 
 *  HHHHH
 *  HHHHH
 * X(LNR)Y
 * X(TTT)Y
 *  (BBB)
 */

int main()
{
    int num = 0;

    cout << "" << endl;
    cout << "Hello! Welcome to the Snowman painter! " << endl
         << endl;
    cout << "NOTE: A valid Snowman's ID is 8 digits long, and each digit is in range of 1-4. " << endl;
    cout << "      In case you'd like to end the program, please insert \"0\". " << endl
         << endl;
    do
    {
        cout << "Pick a valid Snowman's ID: " << endl;
        cin >> num;
        cout << "" << endl;

        if (num < 0)
        {
            cout << "You've inserted an invalid ID, please try again! " << endl;
            cin >> num;
            cout << "" << endl;
            cout << "Your Snowman: " << endl;
            cout << ariel::snowman(num) << endl;
        }
        else if (num == 0)
        {
            cout << "Goodbye, see you soon! " << endl;
        }
        else
        {
            try
            {
                cout << "Your Snowman: " << endl;
                cout << ariel::snowman(num) << endl;
            }
            catch (exception &e)
            {
                cout << "Doesn't exist. " << e.what() << endl;
                cout << "Please try again... " << endl
                     << endl;
            }
        }
    } while (num != 0);
    return 0;
}

/**
 * clang++-9 -std=c++2a -Werror main.cpp snowman.cpp -o main
 * ./main
 * 
 */