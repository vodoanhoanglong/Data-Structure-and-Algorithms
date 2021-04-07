#include <iostream>
#include <stack>

class Number
{
    private:
        std::stack<int> elements;
    public:
        void Push(int element);
        void Pop();
        void Top();
        void print();
};
void Number::Push(int element)
{
    elements.push(element);
}
void Number::Pop()
{

    if(elements.empty())
        std::cout<<"\nDon't pop because of: array was empty!";
    else elements.pop();
}
void Number::Top()
{
    if(elements.empty())
        std::cout<<"\nDon't front because of: array was empty!";
    else
        std::cout<< "Element: "<<elements.top();
}
void Number::print()
{
    std::stack<int> g = elements;
    std::cout << "Elements: ";
   while (!g.empty()) 
    { 
        std::cout << '\t' << g.top(); 
        g.pop(); 
    } 
    std::cout << '\n'; 
}
int main()
{
    Number number;
    number.Push(1);
    number.Push(2);
    number.Push(3);
    number.Push(4);
    number.Push(5);
    number.print();
    number.Pop();
    number.print();
    number.Top();
}