#include "snowman.hpp"
#include <iostream>
#include <string>
#include <array>
#include <math.h>

using namespace std;

//Arrays holding the snowman's parts by types in a fixed order
const array<string, TYPES> hats = {" _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
const array<string, TYPES> noses = {",", ".", "_", " "};
const array<string, TYPES> leftEyes = {"(.", "(o", "(O", "(-"};
const array<string, TYPES> rightEyes = {".)", "o)", "O)", "-)"};
const array<string, TYPES> leftArms = {"<", " ", "/", " "};
const array<string, TYPES> upperLeftArms = {" ", "\\", " ", " "};
const array<string, TYPES> rightArms = {">", " ", "\\", " "};
const array<string, TYPES> upperRightArms = {" ", "/", " ", " "};
const array<string, TYPES> torsos = {"( : )", "(] [)", "(> <)", "(   )"};
const array<string, TYPES> bases = {" ( : ) ", " (\" \") ", " (___) ", " (   ) "};

namespace ariel
{

    //Returns a valid snowman as a string
    string snowman(int num)
    {
        if (!validSnowman(num))
        {
            string e = "Invalid code '" + std::to_string(num) + "'";
            throw std::invalid_argument(e);
        }
        array<int, MAX_LENGTH> id = snowmanID(num);
        return snowmanAssemble(id);
    }

    //Checks if the snowman is valid, meaning:
    //if the number's length is exactly 8 digits
    //and each digit is in range of 1-4
    bool validSnowman(int num)
    {
        return inRange(num) && validLength(num);
    }

    //Checks if the number's length is valid
    bool validLength(int num)
    {
        return ((int)log10(num)) + 1 == MAX_LENGTH;
    }

    //Checks if each digit is in range between 1-4
    bool inRange(int num)
    {
        if (num < 1)
        {
            return false;
        }
        int tmp = num;

        while (tmp > 0)
        {
            if (tmp % BASE > MAX_DIGIT || tmp % BASE < MIN_DIGIT)
            {
                return false;
            }
            tmp /= BASE;
        }
        return true;
    }

    //Get the reversed number
    array<int, MAX_LENGTH> snowmanID(int num)
    {
        array<int, MAX_LENGTH> id = {0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = MAX_LENGTH - 1; i > -1; i--)
        {
            id.at(i) = num % BASE;
            num /= BASE;
        }
        return id;
    }

    //Get the snowman's parts from the arrays
    string getParts(int num, array<string, TYPES> arr)
    {
        for (int i = 1; i <= TYPES; i++)
        {
            if (num == i)
            {
                return "" + arr.at(i - 1);
            }
        }
        return "";
    }

    string torsoWithArms(int X, int T, int Y)
    {
        return "" + getParts(X, leftArms) + getParts(T, torsos) + getParts(Y, rightArms);
    }

    string faceWithArms(int X_Upper, int L, int N, int R, int Y_Upper)
    {
        return "" + getParts(X_Upper, upperLeftArms) + getParts(L, leftEyes) + getParts(N, noses) + getParts(R, rightEyes) + getParts(Y_Upper, upperRightArms);
    }

    //Concatenating the snowman's parts together
    string snowmanAssemble(array<int, MAX_LENGTH> id)
    {
        string hisHat = getParts(id[H - 1], hats);
        string hisFace = faceWithArms(id[X - 1], id[L - 1], id[N - 1], id[R - 1], id[Y - 1]);
        string hisTorso = torsoWithArms(id[X - 1], id[T - 1], id[Y - 1]);
        string hisBase = getParts(id[B - 1], bases);

        return "" + hisHat + "\n" + hisFace + "\n" + hisTorso + "\n" + hisBase + "\n";
    }
}