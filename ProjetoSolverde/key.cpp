#include "KEY.H"

void key::sortKey(int *vecKey)
{
    sort(vecKey, vecKey + 5); // Sort the array in ascending order
}

void key::randomKeyGenerator(int *vecWinningKey)
{
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < 6; i++)
    {
        vecWinningKey[i] = rand() % 10; // Generate a random number between 1 and 9
    }
}

void key::readKey(int *vecUserKey)
{
    cout << "You have 6 numbers to guess, between 1 and 9!" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "Enter number in position " << i + 1 << ": ";
        cin >> vecUserKey[i];
        while (vecUserKey[i] < 0 || vecUserKey[i] > 9)
        {
            cout << "Invalid number. Please enter again: " << endl;
            cin >>
                vecUserKey[i];
        }
    }
    sort(vecUserKey, vecUserKey + 6); // Sort the array in ascending order
}

void key::printKey(int size, int *vecWinningKey, int *vecUserKey, int var)
{
    if (var == 1)
    {
        cout << "Winning Key: ";
    }
    else
    {
        cout << "User Key: ";
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
        for (int i = 0; i < 6; i++)
        {
            if (vecUserKey[i] == vecWinningKey[i])
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
        cout << "You didn't win anything! Better luck next time!" << endl;
        cout << "If you play again, your chances of winning increase! Technically..." << endl;
        break;
    case 1:
        cout << "Congratulations! You got the first 5 numbers right!" << endl;
        break;
    case 2:
        cout << "Congratulations! You got 5 numbers right!" << endl;
        break;
    case 3:
        cout << "Congratulations! You got 4 numbers right!" << endl;
        break;
    default:
        cout << "Invalid prize!" << endl;
        break;
    }
}

// Menu
void key::menu()
{
    int *vecUserKey = new int[6];
    int *vecWinningKey = new int[6];

    // Initialize the keys
    for (int i = 0; i < 6; i++)
    {
        vecUserKey[i] = 0;
        vecWinningKey[i] = 0;
    }

    // Menu
    system("cls");
    cout << "Welcome to CASINO SOLVERDE";
    cout << endl
         << endl;
    {
        key key;

        int option;

        do
        {
            system("cls");

            cout << "Welcome to CASINO SOLVERDE";
            cout << endl
                 << endl;
            cout << "[1] Start playing" << endl;
            cout << "[2] Exit" << endl
                 << endl;
            cout << "Option: ";
            cin >> option;

            switch (option)
            {
            case 1:
                system("cls");
                cout << "Welcome to TOTOLOTO! & GOOD LUCK HUMAN BEING!" << endl
                     << endl;
                key.randomKeyGenerator(vecWinningKey);
                key.readKey(vecUserKey);
                key.sortKey(vecUserKey);
                cout << "Running the key through top-secret algorithms..." << endl
                     << endl;
                Sleep(3000);
                key.printKey(5, vecWinningKey, vecUserKey, 1);
                key.printKey(6, vecWinningKey, vecUserKey, 2);
                cout << endl
                     << "Your fate is being decided by the algorithm overlords..." << endl
                     << endl;
                Sleep(3000);
                cout << "The algorithm overlords have decided your fate!" << endl
                     << endl;
                key.prize(vecWinningKey, vecUserKey);
                break;
            case 2:
                system("cls");
                cout << "Cya! Hope you enjoyed losing your money!" << endl;
                break;
            default:
                system("cls");
                cout << "Invalid option!" << endl;
            }

            system("pause");

        } while (option != 2);
    }
}