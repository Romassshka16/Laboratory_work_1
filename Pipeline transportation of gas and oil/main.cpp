#include <iostream>
#include <fstream>
#include "GasSupplySystem.h"
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
    GasSupplySystem EGS;

    while (1)
    {
        PrintMenu();
        switch (GetCorrectNumber(0, 7))
        {
        case 1:
        {
            
            EGS.Add(EGS.GetPipes());
            break;
        }
        case 2:
        {
            EGS.Add(EGS.GetCS());
            break;
        }
        case 3:
        {
            cout << "\n-----------------------------------------------\n";
            cout << "\tINFORMATION ABOUT ALL PIPES\n";
            cout << "-----------------------------------------------\n\n";

            EGS.Show(EGS.GetPipes());

            cout << "-----------------------------------------------\n";
            cout << "\tINFORMATION ABOUT ALL CS\n";
            cout << "-----------------------------------------------\n\n";

            EGS.Show(EGS.GetCS());

            

            break;
        }
        case 4:
        {


            break;
        }
        case 5:
        {

            break;
        }
        case 6:
        {
            EGS.Save();

            cout << "Data is saved" << "\n";

            break;
        }
        case 7:
        {
            EGS.Load();

            cout << "Data is load" << "\n";

            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout << "Wrong action" << "\n";
        }
        }
    }
}


