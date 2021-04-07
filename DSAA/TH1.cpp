#include <iostream>
#include <string>
#include <list>
using namespace std;
class student
{
private:
	string full_name;
	list<student> DSSV;
	double GPA;

public:
	student() {}
	~student() {}
	void Input();
	void addRecord_Head();
	void addRecord_Tail();
	void insert_List();
	void deleteRecord();
	void viewRecord();
};
void student::Input()
{
    cout << endl;
	cout << "Add record:" << endl;
	cout << endl;
	cout << "What is the student's full name: ";
	cin.ignore(1);
	getline(cin, full_name);
	cout << "What is student's GPA: ";
	cin >> GPA;
}
void mainMenu()
{
	cout << endl;
	cout << "++++++++++++++++++++++++++++++++++" << endl;
	cout << "            MAIN MENU             " << endl;
	cout << "    Choose from the following:    " << endl;
	cout << "1.Add a record in head            " << endl;
	cout << "2.Add a record in tail            " << endl;
	cout << "3.Add a record any                " << endl;
	cout << "4.Delete a record                 " << endl;
	cout << "5.View all records                " << endl;
	cout << "6.Quit program                    " << endl;
	cout << "++++++++++++++++++++++++++++++++++" << endl;
	cout << endl;
}
void student::addRecord_Head()
{
	student x;
	x.Input();
	DSSV.push_front(x);
}
void student::addRecord_Tail()
{
    student x;
	x.Input();
	DSSV.push_back(x);
}
void student::insert_List()
{
	list<student>::iterator it = DSSV.begin();
	student x;
	int position, n;
	cout<<"Nhap vi tri can chen: "<<endl;
	cin>>n;
	advance(it, n);
	x.Input();
	DSSV.insert(it, x);
}
void student::deleteRecord()
{
	DSSV.pop_back();
	cout<<"Deleted successfully!!!"<<endl;
}
void student::viewRecord()
{
    for(list<student>::iterator it = DSSV.begin(); it != DSSV.end(); ++it)
	{
        cout<<"Full Name:" << it->full_name<<endl;
		cout << "GPA: "<< it->GPA<<endl;
	}
}


int main()
{
	student *st;
	st = new student;
	int choice;
	while (1)
	{
		system("cls");
		mainMenu();
		cout << "Enter choice: ";
		if (cin >> choice)
			switch (choice)
			{
			case 1:
				st->addRecord_Head();
				system("pause");
				break;
			case 2:
				st->addRecord_Tail();
				system("pause");
				break;
			case 3:
				st->insert_List();
				system("pause");
				break;
			case 4:
				st->deleteRecord();
				system("pause");
				break;
			case 5:
				st->viewRecord();
				system("pause");
				break;
			case 6:
				cout << "Good bye!!!" << endl;
				system("pause");
				exit(1);
			default:
				cout << "Error!!!" << endl;
				system("pause");
			}
	}
	system("PAUSE");
	return 0;
}
