#include <iostream>
#include <string>
#include <list>
using namespace std;
class student
{
private:
	string full_name;
	student *next;
	double GPA;

public:
	student() {}
	~student() {}
	void addRecord_Head();
	void addRecord_Tail();
	void insert_List();
	void deleteRecord();
	void viewRecord();
};
student *head = NULL;
student *tail = NULL;
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
	cout << endl;
	cout << "Add record:" << endl;
	cout << endl;
	student *temp;
	temp = new student;
	cout << "What is the student's full name: ";
	cin.ignore(1);
	getline(cin, temp->full_name);
	cout << "What is student's GPA: ";
	cin >> temp->GPA;
	temp->next = NULL;
	if (head == NULL)
		head = temp;
	else
	{
		temp->next = head;
		head = temp;
	}
}
void student::addRecord_Tail()
{
	cout << endl;
	cout << "Add record:" << endl;
	cout << endl;
	student *temp;
	temp = new student;
	cout << "What is the student's full name: ";
	cin.ignore(1);
	getline(cin, temp->full_name);
	cout << "What is student's GPA: ";
	cin >> temp->GPA;
	temp->next = NULL;
	if (head == NULL)
		head = temp;
	else
	{
		tail = head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = temp;
	}
}
void student::insert_List()
{
	string position;
	cout << endl;
	cout << "Add record:" << endl;
	cout << endl;
	student *temp;
	temp = new student;
	cout << "Enter name need to add in after this name: " << endl;
	cin.ignore(1);
	getline(cin, position);
	cout << "What is the student's full name: ";
	getline(cin, temp->full_name);
	cout << "What is student's GPA: ";
	cin >> temp->GPA;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		tail = head;
		while (position != tail->full_name)
		{
			tail = tail->next;
		}
		tail->next = temp;
	}
		
}
void student::deleteRecord()
{
	cout << endl;
	cout << "Delete record:" << endl;
	cout << endl;
	student *del;
	del = head;
	del = del->next;
	if (del->next == NULL)
		cout << "End of the list." << endl;
	else
		del = del->next;
	if (del == head)
		cout << "Beginning of list." << endl;
	else
	{
		student *prev;
		prev = head;
		while (prev->next != del)
		{
			prev = prev->next;
		}
		del = prev;
	}
	cout << endl;
	cout << "Name to delete: ";
	cin.ignore(1);
	getline(cin, del->full_name);

	if (del->next == NULL)
		cout << "Nothing follows." << endl;
	else
	{
		student *temp;
		temp = del->next;
		del->next = temp->next;
		delete temp;
	}
}
void student::viewRecord()
{
	cout << endl;
	cout << "All records:";
	cout << endl;
	student *temp;
	temp = head;
	do
	{
		if (temp == NULL)
			cout << "Nothing follows." << endl;
		else
		{
			cout << "Name: " << temp->full_name << ", ";

			cout << "GPA: " << temp->GPA << endl;
			cout << endl;
			temp = temp->next;
		}
	} while (temp != NULL);
}

int main()
{
	student st;
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
				st.addRecord_Head();
				system("pause");
				break;
			case 2:
				st.addRecord_Tail();
				system("pause");
				break;
			case 3:
				st.insert_List();
				system("pause");
				break;
			case 4:
				st.deleteRecord();
				system("pause");
				break;
			case 5:
				st.viewRecord();
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
