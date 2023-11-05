#include <iostream>
#include <fstream>
#include "GasSupplySystem.h"
#include "Addition.h"

using namespace std;

int main()
{
    GasSupplySystem GSS;

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
    }
}




