#include <iostream>
#include <chrono>
#include <format>
#include <stdio.h>
#include <fstream>
#include "GasSupplySystem.h"
#include "Addition.h"


using namespace std;
using namespace chrono;


int StartProgram(GasSupplySystem& GSS) {

    while (1)
    {
        Menu(1);
        switch (GetCorrectNumber(0, 7))
        {
        case 1:
        {

            GSS.Add(GSS.GetPipes());
            break;
        }
        case 2:
        {
            GSS.Add(GSS.GetCS());
            break;
        }
        case 3:
        {
            GSS.ShowObjects();

            break;
        }
        case 4:
        {
            GSS.EditPipe();

            break;
        }
        case 5:
        {
            GSS.EditCS();
            break;
        }
        case 6:
        {
            GSS.Save();
            break;
        }
        case 7:
        {
            GSS.Load();
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
        //return 0;
    }
}

int main(int argc, char* argv[])
{
    GasSupplySystem GSS;

    redirect_output_wrapper cerr_out(cerr);
    string time = std::format("{:%d.%m.%Y_%H_%M_%OS}", system_clock::now() + std::chrono::hours(3));
    ofstream out_logfile("Logging/log_" + time);
    if (out_logfile)
        cerr_out.redirect(out_logfile);

    /*redirect_output_wrapper logg_in(cin);
    ifstream in_logfile;
    in_logfile.open("Logging/log_08_11_2023_21_46_41");
    if (in_logfile)
        logg_in.redirect(in_logfile);*/
    StartProgram(GSS);
}
   
    

    




