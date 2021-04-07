#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

void PrintVector(vector<int> vt)
{
    if(vt.empty()) cout <<"\nKhong co phan tu";
    else{
    cout <<"\n";
    for(int i=0; i<vt.size(); i++)
        cout << vt[i] << "\t";
    }
}

void PrintStack(stack<int> s)
{
    if(s.empty()) cout <<"\nKhong co phan tu";
    else{
       cout <<"\n";
       while(!s.empty())
       {
        cout << "\t" << s.top();
        s.pop();
       }
    }
}

void PrintQueue(queue<int> q)
{
    if(q.empty()) cout <<"\nKhong co phan tu";
    else{
       while (!q.empty()) 
       { 
        cout << "\t" << q.front(); 
        q.pop(); 
       } 
    cout << "\n";
    }
}
int main()
{
    int n, value;
    vector<int>vt;
    stack<int> s;
    queue<int> q;

    //vector
    vt.push_back(1);
    vt.push_back(2);
    vt.push_back(3);
    PrintVector(vt);
    if(vt.empty())
       cout<<"\nKhong co phan tu";
    else
    {
        vt.pop_back();
        PrintVector(vt);
    }
    cout <<"\nNhap vi tri va gia tri can chen:"; cin >> n >> value;
    vt.insert(vt.begin()+n, value);
    PrintVector(vt);
    cout <<"\nSo luong phan tu trong vector: " << vt.size();
    cout << "\nPhan tu lay ra o vi tri 2: " << vt.at(1);
    cout << "\nPhan tu lay ra o vi tri dau la: " << vt.front();
    cout << "\nPhan tu lay ra o vi tri cuoi la: " << vt.back();
    vt.clear();
    PrintVector(vt);

    //stack
    s.push(1);
    s.push(2);
    s.push(3);
    PrintStack(s);
    s.pop();
    PrintStack(s);
    cout << "\nSo luong phan tu trong stack: " << s.size();

    //queue
    cout << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    PrintQueue(q);
    q.pop();
    PrintQueue(q);
    cout << "\nSo luong phan tu trong Queue la: " << q.size();
    cout << "\nPhan tu lay ra o vi tri dau la: " << q.front();
    cout << "\nPhan tu lay ra o vi tri cuoi la: " << q.back();
}