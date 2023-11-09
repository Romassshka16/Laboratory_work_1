#include "Addition.h"

using namespace std;

bool CheckByEmptySet(const unordered_set<int>& id_set)
{
	if (id_set.size() == 0) {
		cout << "Not objects!\n";
		return false;
	}
	return true;
}

string EnterLine()
{
	string line;
	cin >> ws;
	getline(cin, line);
	cerr << line << '\n';
	return line;
}

void  Menu(int param)
{
	switch (param)
	{
	case 1:
	{
		cout << "1.Add Pipe\n" << "2.Add CS\n"
			<< "3.Show Pipes and Compressor Stations\n"
			<< "4.Edit Pipe\n" << "5.Edit CS\n"
			<< "6.Save\n" << "7.Load\n" << "0.Exit\n";
		break;
	}
	case 2:
	{
		cout << "1.Show pipes\n" << "2.Show stations\n"
			<< "3.Show all\n" << "0.Exit\n";
		break;
	}
	case 3:
	{
		cout << "1.Edit one pipe\n" << "2.Edit pipe package\n"
			<< "3.Delete\n" << "0.Back to menu\n";
		break;
	}
	case 4:
	{
		cout << "1.Search by kilometer mark\n" << "2.Search by status\n"
			<< "3.Select pipes\n" << "4.Edit all pipes\n"
			<< "0.Back to menu\n";
		break;
	}
	case 5:
	{
		cout << "1.Change the status to the opposite\n"
			<< "2.Change the status to the \"In repair\"\n"
			<< "3.Change the status to the \"In working condition\"\n"
			<< "0.Back to menu\n";
		break;
	}
	case 6:
	{
		cout << "1.Edit one station\n" << "2.Edit station package\n"
			<< "3.Delete\n" << "0.Back to menu\n";
		break;
	}
	case 7:
	{
		cout << "1.Search by title\n"
			<< "2.Search by percent unused workshops\n"
			<< "3.Select stations\n" << "4.Edit all stations\n"
			<< "0.Back to menu\n";
		break;
	}
	case 8:
	{
		cout << "1.Increase by 1 active workshop\n"
			<< "2.Decrease by 1 active worksop\n"
			<< "0.Back to menu\n";
		break;
	}
	default:
		break;
	}
}




