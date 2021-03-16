/**
 *
 * AUTHORS: Rotem Halbreich
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
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

string nospaces(string input)
{
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    input.erase(remove(input.begin(), input.end(), '\t'), input.end());
    input.erase(remove(input.begin(), input.end(), '\n'), input.end());
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());
    return input;
}

TEST_CASE("Invalid number length in range of 1-7 digits squence")
{
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(12));
    CHECK_THROWS(snowman(121));
    CHECK_THROWS(snowman(124));
    CHECK_THROWS(snowman(1231));
    CHECK_THROWS(snowman(12323));
    CHECK_THROWS(snowman(123333));
}

TEST_CASE("Invalid number length for more than 8 digits squence")
{
    CHECK_THROWS(snowman(123123212));
    CHECK_THROWS(snowman(1111111111));
}

TEST_CASE("Invalid digit, not in range 1-4")
{
    CHECK_THROWS(snowman(71111111));
    CHECK_THROWS(snowman(15111111));
    CHECK_THROWS(snowman(11611111));
    CHECK_THROWS(snowman(11171111));
    CHECK_THROWS(snowman(11119111));
    CHECK_THROWS(snowman(11111811));
    CHECK_THROWS(snowman(11111151));
    CHECK_THROWS(snowman(11111119));
}

TEST_CASE("Negative number") {
    CHECK_THROWS(snowman(-12312312));
    CHECK_THROWS(snowman(-1234322));
    CHECK_THROWS(snowman(-123421));
    CHECK_THROWS(snowman(-32111));
    CHECK_THROWS(snowman(-1232));
    CHECK_THROWS(snowman(-123));
    CHECK_THROWS(snowman(-12));
    CHECK_THROWS(snowman(-1));
}

TEST_CASE("Input Zero") {
    CHECK_THROWS(snowman(123422130));
    CHECK_THROWS(snowman(012342213));
    CHECK_THROWS(snowman(00000000));
    CHECK_THROWS(snowman(0000000));
    CHECK_THROWS(snowman(000000));
    CHECK_THROWS(snowman(00000));
    CHECK_THROWS(snowman(0000));
    CHECK_THROWS(snowman(000));
    CHECK_THROWS(snowman(00));
    CHECK_THROWS(snowman(0));
}

TEST_CASE("Basic snowman") {

    CHECK(nospaces(snowman(11111111)) == nospaces("       \n _===_ \n (.,.) \n<( : )>\n ( : ) \n"));
}
 
TEST_CASE("Checking snowman's Hat") {

    CHECK(nospaces(snowman(21111111)) == nospaces("  ___  \n ..... \n (.,.) \n<( : )>\n ( : ) \n"));
    CHECK(nospaces(snowman(31111111)) == nospaces("   _   \n  /_\\  \n (.,.) \n<( : )>\n ( : ) \n"));
    CHECK(nospaces(snowman(41111111)) == nospaces("  ___  \n (_*_) \n (.,.) \n<( : )>\n ( : ) \n"));
}

                  
TEST_CASE("Checking snowman's Nose/Mouth") {

    CHECK(nospaces(snowman(12111111)) == nospaces("       \n _===_ \n (...) \n<( : )>\n ( : ) \n"));
    CHECK(nospaces(snowman(13111111)) == nospaces("       \n _===_ \n (._.) \n<( : )>\n ( : ) \n"));
    CHECK(nospaces(snowman(14111111)) == nospaces("       \n _===_ \n (. .) \n<( : )>\n ( : ) \n"));
}
                   
TEST_CASE("Checking snowman's Left Eye") {

    CHECK(nospaces(snowman(11211111)) == nospaces("       \n _===_ \n (o,.) \n<( : )>\n ( : ) \n"));
    CHECK(nospaces(snowman(11311111)) == nospaces("       \n _===_ \n (O,.) \n<( : )>\n ( : ) \n"));
    CHECK(nospaces(snowman(11411111)) == nospaces("       \n _===_ \n (-,.) \n<( : )>\n ( : ) \n"));
}

TEST_CASE("Checking snowman's Right Eye") {

    CHECK(nospaces(snowman(11121111)) == nospaces("       \n _===_ \n (.,o) \n<( : )>\n ( : ) \n"));
    CHECK(nospaces(snowman(11131111)) == nospaces("       \n _===_ \n (.,O) \n<( : )>\n ( : ) \n"));
    CHECK(nospaces(snowman(11141111)) == nospaces("       \n _===_ \n (.,-) \n<( : )>\n ( : ) \n"));
}

                        
TEST_CASE("Checking snowman's Left Arm") {
 
    CHECK(nospaces(snowman(11112111)) == nospaces("       \n _===_ \n\\(.,.) \n ( : )>\n ( : ) \n"));
    CHECK(nospaces(snowman(11113111)) == nospaces("       \n _===_ \n (.,.) \n/( : )>\n ( : ) \n"));
    CHECK(nospaces(snowman(11114111)) == nospaces("       \n _===_ \n (.,.) \n ( : )>\n ( : ) \n"));
}

TEST_CASE("Checking snowman's Right Arm") {
                  
    CHECK(nospaces(snowman(11111211)) == nospaces("       \n _===_ \n (.,.)/\n<( : ) \n ( : ) \n"));
    CHECK(nospaces(snowman(11111311)) == nospaces("       \n _===_ \n (.,.) \n<( : )\\\n ( : ) \n"));
    CHECK(nospaces(snowman(11111411)) == nospaces("       \n _===_ \n (.,.) \n<( : ) \n ( : ) \n"));
}
                              
TEST_CASE("Checking snowman's Torso") {

    CHECK(nospaces(snowman(11111121)) == nospaces("       \n _===_ \n (.,.) \n<(] [)>\n ( : ) \n"));
    CHECK(nospaces(snowman(11111131)) == nospaces("       \n _===_ \n (.,.) \n<(> <)>\n ( : ) \n"));
    CHECK(nospaces(snowman(11111141)) == nospaces("       \n _===_ \n (.,.) \n<(   )>\n ( : ) \n"));
}

TEST_CASE("Checking snowman's Base") {

    CHECK(nospaces(snowman(11111112)) == nospaces("     \n_===_\n (.,.) \n<( : )>\n (" ") \n"));
    CHECK(nospaces(snowman(11111113)) == nospaces("     \n_===_\n (.,.) \n<( : )>\n (___) \n"));
    CHECK(nospaces(snowman(11111114)) == nospaces("     \n_===_\n (.,.) \n<( : )>\n (   ) \n"));
}