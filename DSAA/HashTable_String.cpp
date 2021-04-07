#include <iostream>
#include <list>
#include <string>
#define Max_Len 30
using namespace std;

class SinhVien
{
  int BUCKET;
  list<string> *table;

public:
  SinhVien(int V);

  void insertItem(string x);

  int hashFunction(string x)
  {
    return (x.length() % BUCKET);
  }
  void Search(string x);
  void displayHash();
};
SinhVien::SinhVien(int b)
{
  this->BUCKET = b;
  table = new list<string>[BUCKET];
}
void SinhVien::insertItem(string HoTen)
{
  int index = hashFunction(HoTen);
  table[index].push_back(HoTen);
}
void SinhVien::Search(string HoTen)
{
  int index = hashFunction(HoTen);
  int found = 0;
  // tìm khóa trong list
  list<string>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++)
  {
    if (*i == HoTen)
    {
      cout << "Found at " << index << ": " << *i << endl;
      found++;
    }
  }
  if (found == 0)
    cout << "Name not found" << endl;
}
void SinhVien::displayHash()
{
  for (int i = 0; i < BUCKET; i++)
  {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}
int main()
{
  int n, bucket;
  string search;
  cout << "-Enter number elements in array: " << endl;
  cin >> n;
  string a[Max_Len];
  cout << "-Enter number bucket in array: " << endl;
  cin >> bucket;
  cin.ignore(1);
  SinhVien sv(bucket);
  for (int i = 0; i < n; i++)
  {
    cout << "Enter student " << i + 1 << ": " << endl;
    getline(cin, a[i]);
    sv.insertItem(a[i]);
  }
  cout << "-Enter student full name need to search: " << endl;
  getline(cin, search);
  sv.Search(search);
  cout << "-List display:" << endl;
  sv.displayHash();
  system("pause");
  return 0;
}