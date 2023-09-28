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
    while ((cin >> x).fail() || cin.peek() != '\n' || !(strchr("YNyn", x)))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Please enter \"y\" or \"n\": ";
    }
    return x;
}


string GetCorrectString() {
    string s;
    int count = 0;
    cin.ignore(10000, '\n');
    getline(cin, s);

    for (char const& i : s) {
        if (i == 32) {
            count += 1;
        }
    }

    while (count == s.size()) {
        cout << "Line cannot be empty" << endl;
        getline(cin, s);

        count = 0;
        for (char const& i : s) {
            if (i == 32) {
                count++;
            }
        }

    }

    return s;
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
    //Pipeline pl;

    cout << "Kilometer mark: ";
    p.km_mark = GetCorrectString();

    cout << "Length (1 - 5000 km): ";
    p.length = GetCorrectNumber(1.0, 5000.0);

    cout << "Diameter (700 - 1400 mm): ";
    p.diameter = GetCorrectNumber(700, 1400);

    char in_repair;

    cout << "Is this pipe in repair? (y/n): ";
    in_repair = GetCorrectChar();
    p.in_repair = (in_repair == 'y' or in_repair == 'Y') ? true : false;
    //return pl;
}


void CreateCS(CompressorStation& cs)
{
    //CompressorStation cs;

    cout << "Title of CS: ";
    cs.title = GetCorrectString();

    cout << "Number of all workshop (1 - 15): ";
    cs.all_workshop = GetCorrectNumber(1, 15);

    cout << "Number of active workshop (1 - " << cs.all_workshop << "): ";
    cs.active_workshop = GetCorrectNumber(1, cs.all_workshop);

    cout << "Efficiency (0.00 - 1.00): ";
    cs.efficiency = GetCorrectNumber(0.0, 1.0);
    
    //return cs;
}


void ShowPipe(const Pipe& p)
{
    cout << "\n\tInformation about pipe: " << "\"" << p.km_mark << "\"\n" << endl;
    cout << " Kilometer mark: " << p.km_mark << endl;
    cout << " Length: " << p.length << " km" << endl;
    cout << " Diameter: " << p.diameter << " mm" << endl;

    string in_repair;
    in_repair = (p.in_repair) ? " This pipe is in repair\n" : " This pipe is in working condition\n";
    cout << in_repair << endl;
}


void ShowCS(const CompressorStation& cs)
{
    cout << "\n\tInformation about CS " << "\"" << cs.title << "\"\n" << endl;
    cout << " Title: " << cs.title << endl;
    cout << " Number of all workshop: " << cs.all_workshop << endl;
    cout << " Nubmer of active workshop: " << cs.active_workshop << endl;
    cout << " Efficiency: " << cs.efficiency * 100 << "%" << endl;
}


void EditPipe(Pipe& p)
{
    char in_repair;

    if (p.in_repair)
    {
        cout << "This pipe is in repair" << endl;
        cout << "Open this pipe for using? (y/n): ";
        in_repair = GetCorrectChar();
        p.in_repair = (in_repair == 'y' or in_repair == 'Y') ? false : true;
    }
    else
    {
        cout << "This pipe is in working condition" << endl;
        cout << "Close this pipe for reparing? (y/n): ";
        in_repair = GetCorrectChar();
        p.in_repair = (in_repair == 'y' or in_repair == 'Y') ? true : false;
    }
}


void EditCS(CompressorStation& cs)
{
    cout << "Currently number of active workshop is " <<
        cs.active_workshop << " out of " <<
        cs.all_workshop << endl;

    cout << "Enter new number of active workshop: ";
    cs.active_workshop = GetCorrectNumber(1, cs.all_workshop);
}


void SavePipe(const Pipe& p)
{
    ofstream fout;
    fout.open("Pipes.txt", ios::out);
    if (fout)
    {
        fout << p.km_mark << ";"
            << p.length << ";"
            << p.diameter << ";"
            << p.in_repair << ";"
            << endl;
        cout << "\n Data of pipe is successfully saved" << endl;
    }
    else
    {
        cout << "Error in opening file" << endl;
    }
    fout.close();

}


void SaveCS(const CompressorStation& cs)
{
    ofstream fout;
    fout.open("CS.txt", ios::out);
    if (fout)
    {
        fout << cs.title << ";"
            << cs.all_workshop << ";"
            << cs.active_workshop << ";"
            << cs.efficiency << ";"
            << endl;
        cout << "\n Data of CS is successfully saved\n" << endl;
    }
    else
    {
        cout << "Error in opening file" << endl;
    }
    fout.close();

}


void ReadFile(ifstream& fin, vector <string>& v)
{
    string line;
    string parameter;
    while (getline(fin, line))
    {
        for (char const& i : line)
        {
            if (i != ';')
            {
                parameter += i;
            }
            else 
            {
                if (parameter != "") {
                    v.push_back(parameter);
                }
                parameter = "";
            }
        }
    }
}


void LoadPipe(Pipe& p)
{
    ifstream fin;
    fin.open("Pipes.txt");
    //Pipe p;

    if (fin)
    {
        vector <string> pipe_vector;
        
        ReadFile(fin, pipe_vector);

        if (pipe_vector.size() == 4) {
            p.km_mark = pipe_vector[0];
            p.length = stoi(pipe_vector[1]);
            p.diameter = stoi(pipe_vector[2]);
            p.in_repair = (pipe_vector[3] == "1") ? true : false;
            cout << "\n Data of pipe is successfully load" << endl;
        }
        else {
            cout << "\n File with pipes is empty or conatin not all parameters" << endl;
        }
    }
    else
    {
        cout << "Error in opening file" << endl;
    }
    fin.close();
    //return p;
}


void LoadCS(CompressorStation& cs)
{
    ifstream fin;
    fin.open("CS.txt");
    //CompressorStation cs;

    if (fin)
    {
        vector <string> CS_vector;
        ReadFile(fin, CS_vector);

        if (CS_vector.size() == 4) {
            cs.title = CS_vector[0];
            cs.all_workshop = stoi(CS_vector[1]);
            cs.active_workshop = stoi(CS_vector[2]);
            cs.efficiency = stof(CS_vector[3]);
            cout << "\n Data of CS is successfully load\n" << endl;
        } 
        else {
            cout << "\n File with CS is empty or file contain not all parameters!\n" << endl;
        }

    }
    else
    {
        cout << "Error in opening file" << endl;
    }
    fin.close();
    //return cs;
}


bool CheckPipe(const Pipe&p)
{
    if (p.km_mark != "") {
        return true;
    } 
    else {
        cout << "\n Information about pipe is available. Add pipe!\n" << endl;
        return false;
    }
}


bool CheckCS(const CompressorStation& cs)
{
    if (cs.title != "") {
        return true;
    } 
    else {
        cout << "\n Information about CS is available. Add CS!\n" << endl;
        return false;
    }
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
            system("cls");
            CreatePipe(p);
            break;
        }
        case 2:
        {
            system("cls");
            CreateCS(cs);
            break;
        }
        case 3:
        {
            system("cls");
            cout << "\n-----------------------------------------------" << endl;
            cout << "\tINFORMATION ABOUT ALL PIPES" << endl;
            cout << "-----------------------------------------------" << endl;

            if (CheckPipe(p))
            {
                ShowPipe(p);
            }

            cout << "-----------------------------------------------" << endl;
            cout << "\tINFORMATION ABOUT ALL CS" << endl;
            cout << "-----------------------------------------------" << endl;

            if (CheckCS(cs))
            {
                ShowCS(cs);
            }

            cout << endl;
            break;
        }
        case 4:
        {
            system("cls");
            if (CheckPipe(p)) {
                EditPipe(p);
            }
            
            break;
        }
        case 5:
        {
            system("cls");
            if (CheckCS(cs)) {
                EditCS(cs);
            }

            break;
        }
        case 6:
        {
            system("cls");
            if (CheckPipe(p)) {
                SavePipe(p);
            }

            if (CheckCS(cs)) {
                SaveCS(cs);
            }
           
            break;
        }
        case 7:
        {
            system("cls");
            LoadPipe(p);
            LoadCS(cs);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            system("cls");
            cout << "Wrong action" << endl;
        }
        }
    }
}


