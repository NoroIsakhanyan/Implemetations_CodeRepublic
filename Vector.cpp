#include <iostream>
using std::endl;
using std::cout;
using std::cin;

template <typename T> 

class vectorClass 
{
 
private:
  
    T* arr;
    int capacity;
    int size;
 
public:
    
    vectorClass()
    {
        arr = new T[1];
        capacity = 1;
        size = 0;
    }
 
    
    void push(T data)
    {
 
        
        if (size == capacity) {
            T* temp = new T[2 * capacity];
 
            
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
 
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
 
        
        arr[size] = data;
        size++;
    }
 
    void push(int data, int index)
    {
 
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }
 
    
    T get(int index)
    {
 
        if (index < size)
            return arr[index];
    }
 
    
    void pop() { size--; }
 
    
    int Sizeof() { return size; }
 
    
    int getcapacity() { return capacity; }
 
    
    void print()
    {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
 

int main()
{
    vectorClass<int> v;
    vectorClass<char> v1;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.push(50);
    v1.push('h');
    v1.push('e');
    v1.push('n');
    v1.push('o');
 
    cout << "Vector size : " << v.Sizeof() << endl;
    cout << "Vector capacity : " << v.getcapacity() << endl;
 
    cout << "Vector elements : ";
    v.print();
    
    cout << "Char Vector elements : ";
    v1.print();
 
    v.push(100, 1);

    v.pop();
    v1.pop();
 
    return 0;
}
