#include "header.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    loadHistory();

    while (true)
    {
        system("cls");
        cout << "������� ����\n";
        cout << "1. ������������ �������\n";
        cout << "2. ������ ������������\n";
        cout << "3. ����� � ��������\n";

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
            cout << '\n' << "���������� ��������" << '\n';
            return 0;
        }
    }
}

void esc2Menu()
{
    cout << '\n' << "��������� ���� ������ ��� ����������� � ������� ����";
    char keyPress = _getch();
}