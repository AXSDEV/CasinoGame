#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

class key
{
private:
public:
    static void randomKeyGenerator(int *vecWinningKey);
    static void readKey(int *vecUserKey);
    static void printKey(int size, int *vecWinningKey, int *vecUserKey, int var);
    static int checkPrize(int *vecWinningKey, int *vecUserKey);
    static void sortKey(int *vecKey);
    static void prize(int *vecWinningKey, int *vecUserKey);
    static void menu();
};

#endif