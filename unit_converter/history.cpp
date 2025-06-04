#include "header.h" 

vector<Conversion> history;

void saveHistory()
{
    ofstream out(HISTORY_FILE);
    int count = min((int)history.size(), MAX_HISTORY);
    for (int i = 0; i < count; i++)
    {
        out << history[i].category << " " << history[i].inputValue << " " << history[i].fromUnit
            << " -> " << history[i].result << " " << history[i].toUnit << '\n';
    }
    out.close();
}

void loadHistory()
{
    history.clear();
    ifstream in(HISTORY_FILE);
    string line;
    while (getline(in, line))
    {
        if (history.size() >= MAX_HISTORY) break;
        Conversion conv;
        conv.category = "З файлу";
        conv.fromUnit = conv.toUnit = "";
        conv.inputValue = conv.result = 0;
        conv.category = line;
        history.push_back(conv);
    }
    in.close();
}

void addToHistory(const Conversion& conv)
{
    if (history.size() >= MAX_HISTORY)
        history.erase(history.begin());
    history.push_back(conv);
    saveHistory();
}

void showHistory()
{
    system("cls");
    cout << "Історія конвертувань\n";
    loadHistory();
    if (history.empty())
        cout << "Історія пуста.\n";
    else
        for (const auto& h : history)
            cout << h.category << '\n';
    esc2Menu();
}