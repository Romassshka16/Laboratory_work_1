#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((cin >> x).fail() || cin.peek() != '\n' || x < min || x > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Type correct number (" << min << "-" << max << "):";
    }
    return x;
}


char GetCorrectChar()
{
    char x;
    while ((cin >> x).fail() || cin.peek() != '\n' || !(strchr("yn", x)))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Please enter \"y\" or \"n\": ";
    }
    return x;
}


struct Pipe
{
    string km_mark;
    float length;
    int diameter;
    bool in_repair;
    Pipe() {
        km_mark = "";
        length = 0;
        diameter = 0;
        in_repair = 0;
    }
};


struct CompressorStation
{
    string title;
    int all_workshop;
    int active_workshop;
    float efficiency;
    CompressorStation() {
        title = "";
        all_workshop = 0;
        active_workshop = 0;
        efficiency = 0;
    }
};


void CreatePipe(Pipe& p)
{
    cout << "Kilometer mark: ";
    cin >> ws;
    getline(cin, p.km_mark);

    cout << "Length (1 - 5000 km): ";
    p.length = GetCorrectNumber(1.0, 5000.0);

    cout << "Diameter (700 - 1400 mm): ";
    p.diameter = GetCorrectNumber(700, 1400);

    char in_repair;

    cout << "Is this pipe in repair? (y/n): ";
    p.in_repair = (GetCorrectChar() == 'y') ? true : false;
}


void CreateCS(CompressorStation& cs)
{
    cout << "Title of CS: ";
    cin >> ws;
    getline(cin, cs.title);

    cout << "Number of all workshop (1 - 15): ";
    cs.all_workshop = GetCorrectNumber(1, 15);

    cout << "Number of active workshop (0 - " << cs.all_workshop << "): ";
    cs.active_workshop = GetCorrectNumber(0, cs.all_workshop);

    cout << "Efficiency (0.00 - 1.00): ";
    cs.efficiency = GetCorrectNumber(0.0, 1.0);
}


bool CheckPipe(const Pipe& p)
{
    if (p.km_mark != "") 
        return true;
    cout << "Information about pipe is not available. Add pipe!\n";
    return false;
}


bool CheckCS(const CompressorStation& cs)
{
    if (cs.title != "")
        return true;
    cout << "Information about CS is not available. Add CS!\n";
    return false;
}


void PrintStatusPipe(const Pipe& p)
{
    cout << "This pipe is in " << (p.in_repair ? "repair" : "working condition") << "\n";
}

void PrinstStatusCS(const CompressorStation& cs)
{
    cout << "Number of all workshop: " << cs.all_workshop << "\n";
    cout << "Nubmer of active workshop: " << cs.active_workshop << "\n";
}


void ShowPipe(const Pipe& p)
{
    cout << "\tInformation about pipe: " << "\"" << p.km_mark << "\"\n\n";
    cout << "Kilometer mark: " << p.km_mark << "\n";
    cout << "Length: " << p.length << " km" << "\n";
    cout << "Diameter: " << p.diameter << " mm" << "\n";
    PrintStatusPipe(p);
}


void ShowCS(const CompressorStation& cs)
{
    cout << "\tInformation about CS " << "\"" << cs.title << "\"\n\n";
    cout << "Title: " << cs.title << "\n";
    PrinstStatusCS(cs);
    cout << "Efficiency: " << cs.efficiency * 100 << "%" << "\n";
}


void EditPipe(Pipe& p)
{
    if (GetCorrectChar() == 'y')
        p.in_repair = !p.in_repair;
}


void EditCS(CompressorStation& cs)
{
    cs.active_workshop = GetCorrectNumber(0, cs.all_workshop);
}


void SavePipeCS(const Pipe&p, const CompressorStation& cs) {
    ofstream fout;
    fout.open("Data.txt");
    if (fout)
    {
        if (CheckPipe(p)) {
            fout << 'p' << endl
                << p.km_mark << endl
                << p.length << endl
                << p.diameter << endl
                << p.in_repair << endl;
            cout << "Data of pipe is successfully saved\n";
        }
        if (CheckCS(cs)) {
            fout << "cs" << endl
                << cs.title << endl
                << cs.all_workshop << endl
                << cs.active_workshop << endl
                << cs.efficiency << endl;
            cout << "Data of CS is successfully saved\n";
        }
    }
    else
        cout << "Error in opening file\n";
    fout.close();
}


void LoadPipeCS(Pipe& p, CompressorStation& cs)
{
    ifstream fin;
    fin.open("Data.txt");

    if (fin)
    {
        string line;
        while (getline(fin, line)) {
            if (line == "p") {
                getline(fin, p.km_mark);
                fin >> p.length;
                fin >> p.diameter;
                fin >> p.in_repair;
            }
            if (line == "cs") {
                getline(fin, cs.title);
                fin >> cs.all_workshop;
                fin >> cs.active_workshop;
                fin >> cs.efficiency;
            }
        }
        cout << "Data is successfully load\n";
    }
    else
    {
        cout << "Error in opening file" << endl;
    }
    fin.close();
}


void PrintMenu()
{
    cout << "1. Add Pipe" << endl
        << "2. Add CS" << endl
        << "3. Show Pipes and Compressor Stations" << endl
        << "4. Edit Pipe" << endl
        << "5. Edit CS" << endl
        << "6. Save" << endl
        << "7. Load" << endl
        << "0. Exit" << endl;

}


int main()
{
    Pipe p;
    CompressorStation cs;

    while (1)
    {
        PrintMenu();
        switch (GetCorrectNumber(0, 7))
        {
        case 1:
        {
            CreatePipe(p);
            break;
        }
        case 2:
        {
            CreateCS(cs);
            break;
        }
        case 3:
        {
            cout << "\n-----------------------------------------------\n";
            cout << "\tINFORMATION ABOUT ALL PIPES\n";
            cout << "-----------------------------------------------\n\n";

            if (CheckPipe(p))
                ShowPipe(p);

            cout << "\n-----------------------------------------------\n";
            cout << "\tINFORMATION ABOUT ALL CS\n";
            cout << "-----------------------------------------------\n\n";

            if (CheckCS(cs))
                ShowCS(cs);
            
            cout << "\n";

            break;
        }
        case 4:
        {
            if (CheckPipe(p)) {
                PrintStatusPipe(p);
                cout << "Do you want to change status? (y/n): ";
                EditPipe(p);
            }

            break;
        }
        case 5:
        {
            if (CheckCS(cs)) {
                PrinstStatusCS(cs);
                cout << "Enter new number of active workshop (0"
                    << "-" << cs.all_workshop << "): ";
                EditCS(cs);
            }

            break;
        }
        case 6:
        {
            SavePipeCS(p, cs);
            break;
        }
        case 7:
        {
            LoadPipeCS(p, cs);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout << "Wrong action" << endl;
        }
        }
    }
}


