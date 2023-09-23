#include <iostream>
#include <string>

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


int main()
{

    Pipeline pipe;
    CompressorStation station;
    pipe = CreatePipeline();
    ShowPipeline(pipe);
    EditPipeline(pipe);
    ShowPipeline(pipe);
    EditPipeline(pipe);
    ShowPipeline(pipe);
    EditPipeline(pipe);
    ShowPipeline(pipe);
    EditPipeline(pipe);
    ShowPipeline(pipe);
    EditPipeline(pipe);
    ShowPipeline(pipe);
    EditPipeline(pipe);
    ShowPipeline(pipe);
    station = CreateCS();
    ShowCS(station);
    EditCS(station);
    ShowCS(station);
    EditCS(station);
    ShowCS(station);



}


