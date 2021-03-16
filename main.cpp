#include "snowman.hpp"
#include <stdexcept>

using namespace std;

int main()
{
    int num = 0;

    cout << "" << endl;
    cout << "Hello! Welcome to the Snowman anotator! " << endl
         << endl;
    cout << "NOTE: A valid Snowman's ID is a number 8 digits long, and each digit is in range 1-4. " << endl;
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