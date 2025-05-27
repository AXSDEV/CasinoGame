#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <cctype>
#define RESET "\033[0m"
#define BRIGHT_YELLOW "\033[1;33m"
#define BRIGHT_RED "\033[1;31m"
#define BRIGHT_GREEN "\033[1;32m"

using namespace std;

class key
{
private:
public:
    static void randomKeyGenerator(int *vecWinningKey);
    static void readKey(int *vecUserKey);
    static void printKey(int size, int *vecWinningKey, int *vecUserKey, int var);
    static int checkPrize(int *vecWinningKey, int *vecUserKey);
    static void sortKey(int *vecWinningKey, int *vecUserKey);
    static void prize(int *vecWinningKey, int *vecUserKey);
};

#endif