#include "key.h"

int main()
{
    int *vecUserKey = new int[6];
    int *vecWinningKey = new int[6];

    // Initialize the keys
    for (int i = 0; i < 6; i++)
    {
        vecUserKey[i] = 0;
        vecWinningKey[i] = 0;
    }

    key key;

    int option;

    do
    {
        system("cls");
        cout << BRIGHT_GREEN << "Welcome to CASINO SOLVERDE" << RESET;
        cout << endl
             << endl;
        cout << "[1] TOTOLOTO" << endl;
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
            key.sortKey(vecWinningKey, vecUserKey);
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
            cout << BRIGHT_RED << "Cya! Hope you enjoyed losing your money!" << RESET << endl;
            break;
        default:
            system("cls");
            cout << BRIGHT_RED << "Invalid option!" << RESET << endl;
        }

        system("pause");

    } while (option != 2);
}