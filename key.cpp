#include "KEY.H"

void key::sortKey(int *vecWinningKey, int *vecUserKey)
{
    sort(vecUserKey, vecUserKey + 5);       // Sort the array in ascending order
    sort(vecWinningKey, vecWinningKey + 5); // Sort the array in ascending order
}

void key::randomKeyGenerator(int *vecWinningKey)
{
    srand(time(0)); // Seed the random number generator
    int count = 0;
    while (count < 5)
    {
        int num = rand() % 9 + 1;
        bool repeated = false;
        for (int i = 0; i < count; i++)
        {
            if (vecWinningKey[i] == num)
            {
                repeated = true;
                break;
            }
        }
        if (!repeated)
        {
            vecWinningKey[count] = num;
            count++;
        }
    }
}

void key::readKey(int *vecUserKey)
{
    int count = 5;
    cout << "You have 6 numbers to guess, between 1 and 9!" << endl;
    for (int i = 0; i < count + 1; i++)
    {
        bool repeated;
        do
        {
            if (i < count)
            {
                cout << "Enter number in position " << i + 1 << ": ";
            }
            else
            {
                cout << "Enter the supplementary number: ";
            }
            string input;
            getline(cin, input);
            if (!input.empty() && all_of(input.begin(), input.end(), [](char c)
                                         { return isdigit(static_cast<unsigned char>(c)); }))
            {
                cout << "Invalid number. Please use only digits." << endl;
                continue;
            }
            input = stoi(vecUserKey[i]);

            if (vecUserKey[i] < 0 || vecUserKey[i] > 9)
            {
                cout << BRIGHT_RED << "Invalid number." << endl
                     << RESET;
                repeated = true;
                continue;
            }

            repeated = false;
            for (int j = 0; j < i; j++)
            {
                if (vecUserKey[i] == vecUserKey[j])
                {
                    cout << BRIGHT_RED << "You already entered this number!" << RESET << endl;
                    repeated = true;
                    break;
                }
            }
        } while (repeated);
    }
}

void key::printKey(int size, int *vecWinningKey, int *vecUserKey, int var)
{
    if (var == 1)
    {
        cout << BRIGHT_YELLOW << "Winning Key: " << RESET;
    }
    else
    {
        cout << BRIGHT_YELLOW << "User Key: " << RESET;
    }
    for (int i = 0; i < size; i++)
    {
        if (var == 1)
        {
            cout << vecWinningKey[i] << " ";
        }
        else
        {
            cout << vecUserKey[i] << " ";
        }
    }
    cout << endl;
}

int key::checkPrize(int *vecWinningKey, int *vecUserKey)
{
    int mainHits = 0;
    int totalHits = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (vecUserKey[i] == vecWinningKey[j])
            {
                mainHits++;
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (vecUserKey[i] == vecWinningKey[j])
            {
                totalHits++;
            }
        }
    }

    if (mainHits == 5)
    {
        return 1;
    }
    else if (totalHits == 5)
    {
        return 2;
    }
    else if (totalHits == 4)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void key::prize(int *vecWinningKey, int *vecUserKey)

{
    int prize = key::checkPrize(vecWinningKey, vecUserKey);

    switch (prize)
    {
    case 0:
        cout << BRIGHT_RED << "You didn't win anything! Better luck next time!" << RESET << endl;
        cout << BRIGHT_YELLOW << "If you play again, your chances of winning increase! Technically..." << RESET << endl;
        break;
    case 1:
        cout << BRIGHT_GREEN << "Congratulations! You got the first 5 numbers right!" << endl;
        break;
    case 2:
        cout << "Congratulations! You got 5 numbers right!" << endl;
        break;
    case 3:
        cout << "Congratulations! You got 4 numbers right!" << endl;
        break;
    default:
        cout << BRIGHT_RED << "Invalid prize!" << RESET << endl;
        break;
    }
}