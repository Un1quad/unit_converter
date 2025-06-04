#include "header.h"

void convertUnits()
{
    system("cls");
    cout << "�������\n";
    cout << "1. �������\n";
    cout << "2. �����������\n";
    cout << "3. ����\n";
    cout << "4. ��������\n";

    char choice;
    while (!_kbhit());
    choice = _getch();
    if (choice == 27) return;

    int from, to;
    double value{};
    string fromStr, toStr, category;
    double result{};

    switch (choice)
    {
    case '1':
    {
        category = "�������";
        vector<string> units = { "̳������", "����������", "�����", "ʳ�������", "�����", "����", "����", "���" };
        cout << '\n' << "������� ������� :" << '\n';
        for (int i = 0; i < units.size(); i++)
            cout << i + 1 << ". " << units[i] << '\n';

        cout << "������� ��� ������� ������������: ";
        cin >> from;
        cout << "������ ��������: ";
        cin >> value;
        cout << "������� � ��� ������� ������������: ";
        cin >> to;

        result = convertLength(from, to, value);
        fromStr = units[from - 1];
        toStr = units[to - 1];
        break;
    }
    case '2':
    {
        category = "�����������";
        vector<string> units = { "������ ������", "������ ����������", "������ �������" };
        cout << '\n' << "������� �����������:" << '\n';
        for (int i = 0; i < units.size(); i++)
            cout << i + 1 << ". " << units[i] << '\n';

        cout << "������� � ��� ������� ������������: ";
        cin >> from;
        cout << "������ ��������: ";
        cin >> value;
        cout << "������� � ��� ������� ������������: ";
        cin >> to;

        result = convertTemp(from, to, value);
        fromStr = units[from - 1];
        toStr = units[to - 1];
        break;
    }
    case '3':
    {
        category = "����";
        vector<string> units = { "�����", "�����", "�����", "ʳ�������", "�����" };
        cout << '\n' << "������� ����:" << '\n';
        for (int i = 0; i < units.size(); i++)
            cout << i + 1 << ". " << units[i] << '\n';

        cout << "������� � ��� ������� ������������: ";
        cin >> from;
        cout << "������ ��������: ";
        cin >> value;
        cout << "������� � ��� ������� ������������: ";
        cin >> to;

        result = convertMass(from, to, value);
        fromStr = units[from - 1];
        toStr = units[to - 1];
        break;
    }
    case '4':
    {
        category = "��������";
        vector<string> units = { "����� �� ������", "ʳ������� �� ������", "���� �� ������", "��� �� ������", "�����" };
        cout << '\n' << "������� ��������:" << '\n';
        for (int i = 0; i < units.size(); i++)
            cout << i + 1 << ". " << units[i] << '\n';

        cout << "������� � ��� ������� ������������: ";
        cin >> from;
        cout << "������ ��������: ";
        cin >> value;
        cout << "������� � ��� ������� ������������: ";
        cin >> to;

        result = convertSpeed(from, to, value);
        fromStr = units[from - 1];
        toStr = units[to - 1];
        break;
    }
    default: return;
    }

    cout << fixed << setprecision(4);
    cout << '\n' << "���������: " << value << ' ' << fromStr << " = " << result << ' ' << toStr << '\n';

    Conversion c = { category, fromStr, toStr, value, result };
    addToHistory(c);

    esc2Menu();
}

double convertLength(int from, int to, double value)
{
    vector<double> toMeters = { 0.001, 0.01, 1, 1000, 0.0254, 0.3048, 0.9144, 1609.34 };
    return value * toMeters[from - 1] / toMeters[to - 1];
}

double convertMass(int from, int to, double value)
{
    vector<double> toKg = { 1000, 0.453592, 0.0283495, 1, 0.001 };
    return value * toKg[from - 1] / toKg[to - 1];
}

double convertSpeed(int from, int to, double value)
{
    vector<double> toMph = { 1, 1000, 0.3048, 1609.34, 1852 };
    return value * toMph[from - 1] / toMph[to - 1];
}

double convertTemp(int from, int to, double value)
{
    double tempK;

    switch (from)
    {
    case 1: tempK = value + 273.15; break;
    case 2: tempK = (value - 32) * 5 / 9 + 273.15; break;
    case 3: tempK = value; break;
    default: return 0;
    }

    switch (to)
    {
    case 1: return tempK - 273.15;
    case 2: return (tempK - 273.15) * 9 / 5 + 32;
    case 3: return tempK;
    default: return 0;
    }
}