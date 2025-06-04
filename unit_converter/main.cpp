#include "header.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    loadHistory();

    while (true)
    {
        system("cls");
        cout << "Головне меню\n";
        cout << "1. Конвертувати одиницю\n";
        cout << "2. Історія конвертувань\n";
        cout << "3. Вихід з програми\n";

        char choice;
        while (!_kbhit());
        choice = _getch();

        switch (choice)
        {
        case '1':
            convertUnits();
            break;
        case '2':
            showHistory();
            break;
        case '3':
            cout << '\n' << "Завершення програми" << '\n';
            return 0;
        }
    }
}

void esc2Menu()
{
    cout << '\n' << "Натисність любу клавішу щоб повернутись у головне меню";
    char keyPress = _getch();
}