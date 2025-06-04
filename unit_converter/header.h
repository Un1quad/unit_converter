#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const string HISTORY_FILE = "conversion_history.txt";
const int MAX_HISTORY = 5;

struct Conversion
{
    string category;
    string fromUnit;
    string toUnit;
    double inputValue{};
    double result{};
};

extern vector<Conversion> history;

void esc2Menu();

void saveHistory();
void loadHistory();
void addToHistory(const Conversion& conv);
void showHistory();

void convertUnits();
double convertLength(int from, int to, double value);
double convertMass(int from, int to, double value);
double convertSpeed(int from, int to, double value);
double convertTemp(int from, int to, double value);
