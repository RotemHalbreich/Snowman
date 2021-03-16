#pragma once
#include <string>
#include <array>
#include <math.h>
#include <iostream>

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
 */
const int MAX_INPUT = 44444444, MIN_INPUT = 11111111, MAX_LENGTH = 8, MAX_DIGIT = 4, MIN_DIGIT = 1, TYPES = 4, BASE = 10;
const int H = 1, N = 2, L = 3, R = 4, X = 5, Y = 6, T = 7, B = 8;

namespace ariel
{
    std::string snowman(int num);
    bool validSnowman(int num);
    bool validLength(int num);
    bool inRange(int num);
    std::array<int, MAX_LENGTH> snowmanID(int num);
    std::string hat(int num);
    std::string nose(int num);
    std::string leftEye(int num);
    std::string rightEye(int num);
    std::string leftArm(int num);
    std::string leftUpperArm(int num);
    std::string rightArm(int num);
    std::string rightUpperArm(int num);
    std::string torso(int num);
    std::string base(int num);
    std::string torsoWithArms(int X, int T, int Y);
    std::string faceWithArms(int X_Upper, int L, int N, int R, int Y_Upper);
    std::string snowmanAssemble(std::array<int, MAX_LENGTH> id);
    //std::string getParts(int num, std::array<std::string,TYPES> arr);
};