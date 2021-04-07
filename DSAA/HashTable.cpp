#include <iostream>
#include <list>
using namespace std;

class Hash
{
  int BUCKET;

  list<int> *table;

public:
  Hash(int V);

  void insertItem(int x);

  void Search(int key);

  int hashFunction(int x)
  {
    return (x % BUCKET);
  }

  void displayHash();
};

Hash::Hash(int b)
{
  this->BUCKET = b;
  table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
  int index = hashFunction(key);
  table[index].push_back(key);
}

void Hash::Search(int key)
{
  int index = hashFunction(key);
  int found = 0;
  // tìm khóa trong list
  list<int>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++)
  {
    if (*i == key)
    {
      cout << "Found at " << index << ": " << *i << endl;
      found++;
    }
  }
  if (found == 0)
    cout << "Element not found" << endl;
}
void Hash::displayHash()
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

  int n, bucket, search;
  cout << "-Enter number elements in array: " << endl;
  cin >> n;
  int a[1];
  a[n];
  cout << "-Enter number bucket in array: " << endl;
  cin >> bucket;
  Hash h(bucket);
  for (int i = 0; i < n; i++)
  {
    cout << "Enter element " << i + 1 << ": " << endl;
    cin >> a[i];
    h.insertItem(a[i]);
  }
  cout << "-Enter value need to search: " << endl;
  cin >> search;
  h.Search(search);
  cout << "-Array display:" << endl;
  h.displayHash();
  system("pause");
  return 0;
}