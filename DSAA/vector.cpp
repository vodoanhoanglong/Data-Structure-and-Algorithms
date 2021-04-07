#include <iostream>
#include <vector>
#define MAX 100

class Array
{
    private:
      std::vector<int> elements; // std:: thay thế cho using namespace std;
      std::vector<int> b;
      int  n;
    public:
      void printArray();
      void push(int element);
      void pop();
      void shift();
      void setArrayValues(int a);
      void displayArrayValues();
      void deleteElementByIndex(int index);
      void deleteElementByValue(int value);
      void updateElementByIndex(int index, int value);
      void updateElementByValue(int originalValue, int replacementValue);
      void concat();
};

void Array::printArray()
{
    std::cout<<std::endl<<"Elements: ";
    if(elements.empty())
    {
        std::cout<<"No elements!!!"<<std::endl;
    }
    else 
    {
        for(int element:elements){ //xét từng element trong elements
        std::cout<<element<<"  ";
        }
    }
}
void Array::push(int element)
{
    elements.push_back(element);
}
void Array::pop()
{
    if(elements.empty())
    {
        std::cout<<"Don't pop because of: array was empty!";
    }
    else
    {
        elements.pop_back();
    }
}
void Array::shift()
{
    int n = elements.size();
    if(elements.empty())
    {
        std::cout<<"Don't pop because of: array was empty!";
    }
    else
    {
        for(int i=0; i<n; i++)
            elements[i] = elements[i+1];
        elements.pop_back();
        n--;
    }
}
void Array::setArrayValues(int a)
{
    for(int i=0; i<MAX; i++)
    {
        std::cout << "\nEnter element(If you want stop, press -100 to skip) " << i+1 << ": " ;
        std::cin >> a;
        if(a == -100)
           break;
        b.push_back(a);
    }
}
void Array::displayArrayValues()
{
    std::cout<<std::endl<<"Elements: ";
    for(int a:b)
        std::cout<< a <<"  ";
}
void Array::deleteElementByIndex(int index)
{
    do
    {
        std::cout << "\nEnter a delete index: \n";
        std::cin >> index;
        if(index < 0 || index >= b.size())
            std::cout<<"Does not index need delete!\n";
    }while(index < 0 || index >= b.size());
    b.erase(b.begin() + index);
}
void Array::deleteElementByValue(int value)
{
    int dem = 0; // đếm
    int index=0;
    do{
        std::cout << "\nEnter a value u want to delete: ";
        std::cin >> value;
        for(int a:b){
            if(a == value)
            {
               b.erase(b.begin() + index);
               dem++;
            }
            index++;
        }
        if(dem==0)
           std::cout<<"Does not value need search!\n";
    }while(dem==0);
}
void Array::updateElementByIndex(int index, int value)
{
    do{
        std::cout<<"\nEnter the location u want to update: ";
        std::cin >> index;
        if(index >= b.size())
           std::cout<<"\nPosition does not exist please re-enter!!!";
    }while(index >= b.size());
    std::cout<<"\nEnter a value u want to update: ";
    std::cin >> value;
    b[index] = value;
}
void Array::updateElementByValue(int originalValue, int replacementValue)
{
    int index=0;
    int dem=0;
    std::cout << "\nEnter the new value: ";
    std::cin >> replacementValue;
    do{
        std::cout << "\nEnter the old value you want to change to the new value: ";
        std::cin >> originalValue;
        for(int a:b){
            if(a==originalValue){
                    b[index]=replacementValue;
                    dem++;
                }
            index++;
            }
    if(dem==0)
       std::cout<<"Does not value need change!\n";
    }while(dem==0);
}
void Array::concat()
{
    elements.insert(elements.end(), b.begin(), b.end());
}

int main()
{
    int a, index, b, value, originalValue, replacementValue;
    Array array1;
    array1.push(1);
    array1.printArray();
    array1.push(2);
    array1.printArray();
    array1.push(3);
    array1.printArray();
    array1.push(4);
    array1.printArray();
    array1.push(5);
    array1.printArray();
    array1.push(6);
    array1.printArray();
    array1.push(7);
    array1.printArray();
    array1.pop();
    array1.printArray();
    array1.shift();
    array1.printArray();
    array1.shift();
    array1.printArray();
    array1.setArrayValues(a);
    array1.displayArrayValues();
    array1.deleteElementByIndex(index);
    array1.displayArrayValues();
    array1.deleteElementByValue(value);
    array1.displayArrayValues();
    array1.updateElementByIndex(index, value);
    array1.displayArrayValues();
    array1.updateElementByValue(originalValue, replacementValue);
    array1.displayArrayValues();
    array1.concat();
    array1.printArray();
}
