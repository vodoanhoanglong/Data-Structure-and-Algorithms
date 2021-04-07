#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Project
{
    private:
        int id, cost;
        string name;
    public:
        void EnterCommodityInformation(Project *a, int n);
        void Print(Project *a, int n);
        void PrintBill(int index, Project *a, int &n);
};

void Project::EnterCommodityInformation(Project *a, int n)
{
    for(int i=0; i<n; i++)
    {  
        cout << "\nEnter Commodity " << i+1 << ": ";
        cout << "\nEnter ID: ";
        cin >> a[i].id;
        cout << "\nEnter name: ";
        cin.ignore(0);
        getline(cin, a[i].name);
        cout << "\nEnter cost: ";
        cin >> a[i].cost;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i].id == a[j].id)
            {
                a[i].name = a[j].name;
                a[i].cost = a[j].cost;
                if(j+1 == n)
                {
                    cout << "\nEnter Commodity " << n+1 << ": ";
                    cout << "\nEnter ID: ";
                    cin >> a[j].id;
                    cout << "\nEnter name: ";
                    cin.ignore(0);
                    getline(cin, a[j].name);
                    cout << "\nEnter cost: ";
                    cin >> a[j].cost;
                }
                else if(j+1<n)
                {
                    a[j].id = a[j+1].id;
                    a[j].name = a[j+1].name;
                    a[j].cost = a[j+1].cost;
                    cout << "\nEnter Commodity " << n+1 << ": ";
                    cout << "\nEnter ID: ";
                    cin >> a[j+1].id;
                    cout << "\nEnter name: ";
                    cin.ignore(0);
                    getline(cin, a[j+1].name);
                    cout << "\nEnter cost: ";
                    cin >> a[j+1].cost;
                }
            }
        }
    }
}
void Project::Print(Project *a, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << "\nCommodity Information " << i+1 << ": ";
        cout << "\nID commodity: " << a[i].id;
        cout << "\nName commodity: " << a[i].name;
        cout << "\nCost commodity: " << a[i].cost;
    }
}
void Project::PrintBill(int index, Project *a, int &n)
{
    cout << "\n\t\tBILL: ";
    cout << "\nID commodity: " << a[index].id;
    cout << "\nName commodity: " << a[index].name;
    cout << "\nTotal money: " << a[index].cost;
    for(int i=index; i<n; i++)
    {
        if(index+1 == n)
        {
            n--;
            return;
        }
        else
        {
            a[index].id = a[index+1].id;
            a[index].name = a[index+1].name;
            a[index].cost = a[index+1].cost;
        }
    }
    n--;
}
int main()
{
    Project *a;
    Project project;
    int n;
    do
    {
        cout << "\nEnter number commodity: ";
        cin >> n;
    }while(n <= 0);
    a = new Project[n];
    project.EnterCommodityInformation(a, n);
    project.Print(a, n);
    project.PrintBill(3, a, n);
    project.Print(a, n);
    delete a;
}

