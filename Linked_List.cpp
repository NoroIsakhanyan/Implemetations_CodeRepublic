#include <iostream>

template<typename T>
class List
{
public:
    List();
    ~List();
public:
    int getSize() const;
    void push_back(const T&);
    void push_front(const T&);
    void pop_front();
    void clear();
    void removeAt(int position);
    void pop_back();
    void insert(const T&, int position);
    void print();
private:
    struct list_node
    {
        T data;
        list_node* next;
    };
    std::size_t list_size;
    list_node* m_head = nullptr;
};

template<typename T>
List<T>::List() : list_size{0}, m_head{nullptr}
{
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
int List<T>::getSize() const
{
    return list_size;
}

template<typename T>
void List<T>::push_front(const T& data)
{
    list_node* node = new list_node;
    node->data = data;
    node->next = m_head;
    m_head = node;
    ++list_size;
}

template<typename T>
void List<T>::pop_front()
{
    list_node* tmp = m_head;
    m_head = m_head->next;
    delete tmp;
    --list_size;
}

template<typename T>
void List<T>::push_back(const T& data)
{
    list_node* node = new list_node;
	node->next = nullptr;
	node->data = data;
	if(!m_head)
	{	
		m_head = node;
	}
	list_node* current = m_head;
	while(current->next != nullptr)
	{	
		current = current->next;
	}
    ++list_size;
}

template<typename T>
void List<T>::insert(const T& data, int position)
{
    list_node* node = new list_node;

    list_node* current = m_head;
    node->data = data;
    
    if(position < 1)
    {
        std::cout << "Wrong position" << std::endl;
        return;
    }
    
    if(position == 1)
    {
        push_front(data);
        return;
    }
    
    if(position - 1 > list_size)
    {
        std::cout << "Wrong position" << std::endl;
        return;
    }
    
    else
    {
        for(int i = 2; i <= position; ++i)
        {
            if(current->next != nullptr)
            {
                current = current->next;
            }
        }
        node->next = current->next;
        current->next = node;
        ++list_size;
    }
}
    
template<typename T>
void List<T>::print()
{
    list_node* current = m_head;
    while(current)
    {
        std::cout << current->data;
        std::cout << "->";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

template<typename T>
void List<T>::clear()
{
    while(list_size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::removeAt(int position)
{
    list_node* current = m_head;
    
    if(position < 1)
    {
        std::cout << "Wrong position" << std::endl;
        return;
    }
    if(position == 1)
    {
        pop_front();
        return;
    }
    
    if(position - 1 > list_size)
    {
        std::cout << "Wrong position" << std::endl;
    }
    else
    {
        for(int i = 2; i < position; ++i)
        {
            if(current->next != nullptr)
            {
                current = current->next;
            }
        }
        list_node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
        --list_size;
    }
}

template<typename T>
void List<T>::pop_back()
{
    removeAt(list_size);
}

int main()
{
    List<int> obj;
    obj.push_back(12);
    obj.push_front(24);
    obj.insert(33,1);
    obj.insert(35,2);
    obj.insert(77,2);
    obj.pop_back();
    obj.removeAt(3);
    std::cout << obj.getSize() << std::endl;
    obj.print();

  return 0;
}