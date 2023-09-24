#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


struct Pipeline
{
    string km_mark;
    int length;
    int diameter;
    bool in_repair;
};


struct CompressorStation
{
    string title;
    int all_workshop;
    int active_workshop;
    float efficiency;
};


Pipeline CreatePipeline()
{
    Pipeline pl;

    cout << "Kilometer mark: ";
    cin >> pl.km_mark;

    cout << "Length (km): ";
    cin >> pl.length;

    cout << "Diameter (mm): ";
    cin >> pl.diameter;

    char in_repair;

    cout << "Is this pipeline in repair? (y/n): ";
    cin >> in_repair;
    pl.in_repair = (in_repair == 'y') ? true : false;
    return pl;
}


CompressorStation CreateCS()
{
    CompressorStation cs;

    cout << "Title of CS: ";
    cin >> cs.title;

    cout << "Number of all workshop: ";
    cin >> cs.all_workshop;

    cout << "Number of active workshop: ";
    cin >> cs.active_workshop;

    cout << "Efficiency: ";
    cin >> cs.efficiency;
    
    return cs;
}


void ShowPipeline(const Pipeline& pl)
{
    cout << "\tInformation about pipeline " << "\"" << pl.km_mark << "\"" << endl;
    cout << "Kilometer mark: " << pl.km_mark << endl;
    cout << "Length: " << pl.length << " km" << endl;
    cout << "Diameter: " << pl.diameter << " mm" << endl;
    
    string in_repair;
    in_repair = (pl.in_repair) ? "This pipeline is in repair" : "This pipeline is in working condition";
    cout << in_repair << endl;
}


void ShowCS(const CompressorStation& cs)
{
    cout << "\tInformation about CS " << "\"" << cs.title << "\"" << endl;
    cout << "Title: " << cs.title << endl;
    cout << "Number of all workshop: " << cs.all_workshop << endl;
    cout << "Nubmer of active workshop: " << cs.active_workshop << endl;
    cout << "Efficiency: " << cs.efficiency << endl;
}


void EditPipeline(Pipeline& pl)
{
    char in_repair;

    if (pl.in_repair)
    {
        cout << "This pipeline is in repair" << endl;
        cout << "Open this pipeline for using? (y/n): ";
        cin >> in_repair;
        pl.in_repair = (in_repair == 'y') ? false : true;
    }
    else
    {
        cout << "This pipeline is in working condition" << endl;
        cout << "Close this pipeline for reparing? (y/n): ";
        cin >> in_repair;
        pl.in_repair = (in_repair == 'y') ? true : false;
    }
}


void EditCS(CompressorStation& cs)
{
    cout << "Currently number of active workshop is " <<
        cs.active_workshop << " out of " <<
        cs.all_workshop << endl;

    cout << "Enter new number of active workshop: ";
    cin >> cs.active_workshop;
}


void SavePipeline(const Pipeline& pl)
{
    ofstream fout;
    fout.open("Pipelines.txt", ios::out);
    if (fout)
    {
        fout << pl.km_mark << ";"
            << pl.length << ";"
            << pl.diameter << ";"
            << pl.in_repair << ";"
            << endl;
        cout << "Data is successfully saved" << endl;
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
        cout << "Data about is successfully saved" << endl;
    }
    else
    {
        cout << "Error in opening file" << endl;
    }
    fout.close();

}


Pipeline LoadPipeline()
{
    ifstream fin;
    fin.open("Pipelines.txt");
    Pipeline pl;

    if (fin)
    {
        string line;
        string parameter = "";
        vector <string> parameters_vector;
        
        while (fin >> line)
        {
            for (char const &i : line)
            {
                if (i != ';')
                {
                    parameter += i;
                }
                else
                {
                    parameters_vector.push_back(parameter);
                    parameter = "";
                }
            }

            pl.km_mark = parameters_vector[0];
            pl.length = stoi(parameters_vector[1]);
            pl.diameter = stoi(parameters_vector[2]);
            pl.in_repair = (parameters_vector[3] == "1") ? true : false;

        }
    }
    else
    {
        cout << "Error in opening file" << endl;
    }
    fin.close();
    return pl;
}


CompressorStation LoadCS()
{
    ifstream fin;
    fin.open("CS.txt");
    CompressorStation cs;

    if (fin)
    {
        string line;
        string parameter = "";
        vector <string> parameters_vector;

        while (fin >> line)
        {
            for (char const& i : line)
            {
                if (i != ';')
                {
                    parameter += i;
                }
                else
                {
                    parameters_vector.push_back(parameter);
                    parameter = "";
                }
            }

            cs.title = parameters_vector[0];
            cs.all_workshop = stoi(parameters_vector[1]);
            cs.active_workshop = stoi(parameters_vector[2]);
            cs.efficiency = stof(parameters_vector[3]);

        }
    }
    else
    {
        cout << "Error in opening file" << endl;
    }
    fin.close();
    return cs;
}


void PrintMenu()
{
    cout << "1. Add Pipeline" << endl
        << "2. Add CS" << endl
        << "3. Show Pipelines and Compressor Stations" << endl
        << "4. Edit Pipeline" << endl
        << "5. Edit CS" << endl
        << "6. Save" << endl
        << "7. Load" << endl
        << "0. Exit" << endl;

}



int main()
{

    Pipeline pl;
    CompressorStation cs;

    while (1)
    {
        PrintMenu();
        int i = 0;
        cin >> i;

        switch (i)
        {
        case 1:
        {
            pl = CreatePipeline();
            break;
        }
        case 2:
        {
            cs = CreateCS();
            break;
        }
        case 3:
        {
            //Проверка, что труба существует и КС тоже
            cout << "\nInformation about pipelines\n" << endl;
            ShowPipeline(pl);
            cout << "\nInformation about KS\n" << endl;
            ShowCS(cs);
            break;
        }
        case 4:
        {
            EditPipeline(pl);
            break;
        }
        case 5:
        {
            EditCS(cs);
            break;
        }
        case 6:
        {
            SaveCS(cs);
            SavePipeline(pl);
            break;
        }
        case 7:
        {
            pl = LoadPipeline();
            cs = LoadCS();
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

    //pl = CreatePipeline();
    //ShowPipeline(pl);
    //EditPipeline(pl);
    //ShowPipeline(pl);
    //pl = LoadPipeline();
    //ShowPipeline(pl);
    //SavePipeline(pl);
    /*station = CreateCS();
    ShowCS(station);
    EditCS(station);
    ShowCS(station);*/
    //cs = CreateCS();
    //ShowCS(cs);

}


