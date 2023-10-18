#include <iostream>
#include "Pipe.h"
#include "Station.h"
#include "Addition.h"


using namespace std;


//void EditPipe(Pipe& p)
//{
//    if (GetCorrectChar() == 'y')
//        p.in_repair = !p.in_repair;
//}
//
//
//void EditCS(CompressorStation& cs)
//{
//    cs.active_workshop = GetCorrectNumber(0, cs.all_workshop);
//}
//
//
//void SavePipe(const Pipe&p) {
//    ofstream fout;
//    fout.open("Data.txt");
//    if (fout)
//    {
//        fout << 'p' << endl
//            << p.km_mark << endl
//            << p.length << endl
//            << p.diameter << endl
//            << p.in_repair << endl;
//    }
//    else
//        cout << "Error in opening file\n";
//    fout.close();
//}
//
//
//void SaveCS(const CompressorStation& cs) {
//    ofstream fout;
//    fout.open("Data.txt", ios::app);
//    if (fout)
//    {
//        fout << "cs" << endl
//            << cs.title << endl
//            << cs.all_workshop << endl
//            << cs.active_workshop << endl
//            << cs.efficiency << endl;
//    }
//    else
//        cout << "Error in opening file\n";
//    fout.close();
//}
//
//
//void LoadPipe(Pipe& p)
//{
//    ifstream fin;
//    fin.open("Data.txt");
//
//    if (fin)
//    {
//        string line;
//        while (getline(fin, line)) {
//            if (line == "p") {
//                getline(fin, p.km_mark);
//                fin >> p.length;
//                fin >> p.diameter;
//                fin >> p.in_repair;
//            }
//        }
//    }
//    else
//    {
//        cout << "Error in opening file" << endl;
//    }
//    fin.close();
//}
//
//
//void LoadCS(CompressorStation& cs)
//{
//    ifstream fin;
//    fin.open("Data.txt");
//
//    if (fin)
//    {
//        string line;
//        while (getline(fin, line)) {
//            if (line == "cs") {
//                getline(fin, cs.title);
//                fin >> cs.all_workshop;
//                fin >> cs.active_workshop;
//                fin >> cs.efficiency;
//            }
//        }
//    }
//    else
//    {
//        cout << "Error in opening file" << endl;
//    }
//    fin.close();
//}
//
//
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
    Station cs;

    //CompressorStation cs;

    while (1)
    {
        PrintMenu();
        switch (GetCorrectNumber(0, 7))
        {
        case 1:
        {
            cin >> p;
            break;
        }
        case 2:
        {
            cin >> cs;
            break;
        }
        case 3:
        {
            cout << "\n-----------------------------------------------\n";
            cout << "\tINFORMATION ABOUT ALL PIPES\n";
            cout << "-----------------------------------------------\n\n";

            cout << p;

            cout << "\n\n-----------------------------------------------\n";
            cout << "\tINFORMATION ABOUT ALL CS\n";
            cout << "-----------------------------------------------\n\n";

            cout << cs;
            
            cout << "\n";

            break;
        }
        case 4:
        {
            /*if (CheckPipe(p)) {
                PrintStatusPipe(p);
                cout << "Do you want to change status? (y/n): ";
                EditPipe(p);
            }*/

            break;
        }
        case 5:
        {
            /*if (CheckCS(cs)) {
                PrinstStatusCS(cs);
                cout << "Enter new number of active workshop (0"
                    << "-" << cs.all_workshop << "): ";
                EditCS(cs);
            }*/

            break;
        }
        case 6:
        {
           /* if (CheckPipe(p)) {
                SavePipe(p);
                cout << "Data of pipe is successfully saved\n";
            }*/


            /*if (CheckCS(cs)) {
                SaveCS(cs);
                cout << "Data of CS is successfully saved\n";
            }*/

            break;
        }
        case 7:
        {
            /*LoadPipe(p);
            LoadCS(cs);
            cout << "Data is successfully load\n";
            break;*/
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


