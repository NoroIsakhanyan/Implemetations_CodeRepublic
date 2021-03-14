#include <iostream>
#include <cstdlib>
using namespace std;
 
#define SIZE 10
 

class stack
{
    int *arr;
    int top;
    int capacity;
 
public:
    stack(int size = SIZE);         
    ~stack();                       
 
    void push(int);
    int pop();
    int peek();
 
    int size();
    bool isEmpty();
    bool isFull();
};
 

stack::stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}
 

stack::~stack() {
    delete[] arr;
}
 

void stack::push(int x)
{
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}
 

int stack::pop()
{
    
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Removing " << peek() << endl;
 
    
    return arr[top--];
}
 

int stack::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 

int stack::size() {
    return top + 1;
}
 

bool stack::isEmpty() {
    return top == -1;               // return size() == 0;
}
 

bool stack::isFull() {
    return top == capacity - 1;     // return size() == capacity;
}
 
int main()
{
    stack pt(3);
 
    pt.push(1);
    pt.push(2);
 
    pt.pop();
    pt.pop();
 
    pt.push(3);
 
    cout << "The top element is " << pt.peek() << endl;
    cout << "The stack size is " << pt.size() << endl;
 
    pt.pop();
 
    if (pt.isEmpty()) {
        cout << "The stack is empty\n";
    }
    else {
        cout << "The stack is not empty\n";
    }
 
    return 0;
}



