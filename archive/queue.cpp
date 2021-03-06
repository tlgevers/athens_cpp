
// queue.cpp : Defines the entry point for the console application.
// Trevor Gevers / Data Structures 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cstdlib>
using namespace std;

ofstream outfile;

class List
{
    public:
    // TYPEDEF VALUES AND SIZE OF ARRAY VALUE
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 20; 
    
    // CONSTRUCTORS
    List(); 
    List(List &A);
    
    // METHODS
    bool empty();
    void first();
    void last();
    void prev();
    void next();
    value_type getPos();    
    void setPos(value_type);
    void insertBefore(value_type);
    void insertAfter(value_type);
    size_type size();
    void replace(int);
    void erase();
    void clear();
    void left_justify();
    value_type getElement();
    
// JUST FOR INITIAL TESTING
    void print(); 
// JUST FOR INITIAL TESTING
    
    
	friend std::ostream &operator<<(std::ostream &, List &);
    bool operator==(List &); 
    void operator+(List &);
    void operator=(List &);
	
    private:
    
    value_type data[CAPACITY];
    size_type my_size;
    value_type position;     
    void set_to_zero();
    
};


List::List()
{
    first();    
    my_size = 0;
    set_to_zero();
}


List::List(List &A)
{
    first();    
    my_size = 0;
    set_to_zero();
    
    for (int i = 0; i < CAPACITY; i++)
    {
        data[i] = A.data[i];
    }
    left_justify();
}


void List::set_to_zero()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        data[i] = 0;
    }
}


bool List::empty() 
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (data[i] != 0)
        {
            return false;
        }
    }
    return true;
}


void List::first()
{
    position = 0;
}


void List::last()
{
    if (my_size == 0)
    {
        position = 0;
    }
    if (my_size == 1)
    {
        position = 0;
    }
    if (my_size > 1)
    {
        position = my_size - 1;
    }
    
}


void List::prev()
{
    if (position <= 0)
    {
        return;
    }
    position--;
}


void List::next()
{
    if (position >= (CAPACITY - 1))
    {
        return;
    }
    position++;
}


int List::getPos()
{
    return position;
}


void List::setPos(int p)
{
    if (p > (CAPACITY - 1)|| p < 0)
    {
        return;
    }
    position = p;    
}


void List::insertBefore(int value)
{
    if (my_size == CAPACITY)
    {
        return;
    }
    
    if (data[position] == 0)
    {
        data[position] = value;
            
        left_justify();
        return;
    }
    
    if (position == 0) {
        for (int i = my_size + 1; i > (position); i--)
        {
            data[i] = data[i - 1];
        }
        data[position] = value;
        left_justify();
        return;
    }
    
    for (int i = my_size + 1; i > (position - 1); i--)
    {
       data[i] = data[i - 1];
    }
    
    data[position - 1] = value;
    left_justify();
}


void List::insertAfter(int value)
{
    
    if (my_size == CAPACITY)
    {
       return;
    }
    
    if (data[position] == 0)
    {
        data[position] = value;
        
        left_justify();
        return;
    }
    
    if (position == 0) {
        for (int i = my_size + 1; i > (position); i--)
        {
            data[i] = data[i - 1];
        }
        data[position + 1] = value;
        left_justify();
        return;
    }
    
    for (int i = my_size + 1; i > position + 1; i--)
    {
       data[i] = data[i - 1];
    }
    
    data[position + 1] = value;
    left_justify();
}


int List::getElement()
{
    return data[position];
}


std::size_t List::size()
{
    return my_size;
}


void List::replace(int new_value)
{
    data[position] = new_value;
}


void List::erase()
{
    data[position] = 0; 
    left_justify();
}


void List::clear()
{
    this->set_to_zero();
}

// JUST FOR INITIAL TESTING
void List::print()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        outfile << data[i] << " ";
    }
    outfile << "\n";
}
// JUST FOR INITIAL TESTING

std::ostream & operator<<(std::ostream &out, List &A)
{
    int *ptr;
    ptr = A.data;
    int count = 0;
    while(*ptr && count != 20)
    {
        if (*ptr != 0)
        {
            out << *ptr << " ";
        }
        ptr++;
        count++;
    }
    return out;
}


bool List::operator==(List &L)
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (L.data[i] != data[i])
        {
            return false;
        }
    }
    return true;
}


void List::operator+(List &L)
{
   for (int i = 0; i < CAPACITY; i++)
   {
       data[i] = data[i] + L.data[i];
   }
   left_justify();
}


void List::operator=(List &L)
{
    for (int i = 0; i < CAPACITY; i++)
    {
        data[i] = L.data[i];
    }
    left_justify();
}

void List::left_justify()
{
    int index = 0;
    int zero_pos = 0;
    int outlier = 0;
    bool found = false;
    
    while(index <= CAPACITY)
    {
        if (data[index] == 0)
        {
            zero_pos = index;
            
            for (int i = index; i < CAPACITY; i++)
            {
                if (data[i] != 0)
                {
                    outlier = i;
                    found = true;
                }
            }
            
            if (found == true)
            {
                data[zero_pos] = data[outlier];
                data[outlier] = 0;
                index = outlier;
                found = false;
            }
            
        }
        index++;
    }
    my_size = 0;
    for (int i = 0; i < CAPACITY; i++)
    {
        
        if (data[i] != 0)
        {
            my_size++;
        }
        if (data[i] == 0)
        {
            break;
        }
    }
}

class Stack : virtual public List
{
    public:
    int max;
    void pop(); //remove last value placed in stack, last value in
    int size(); 
    void push(int);
    int top();
    bool empty();
    bool full();
    void print();
    void max_value();
    int get_max();
    Stack();
    
    private:
};

Stack::Stack():List()
{
    max = 0;      
    outfile << "Stack Constructed\n";
}


void Stack::pop()
{
    if (List::empty())
    {
       return; 
    }
    List::last();
    List::erase();
    max_value();
}


int Stack::size()
{
    return List::size();
    
}


void Stack::push(int value)
{
    List::last();
    List::insertAfter(value);
    max_value();
}


int Stack::top()
{
    List::last();
    return List::getElement();
}


bool Stack::empty()
{
    return List::empty();
}


bool Stack::full()
{
    if (List::size() == 20)
    {
        return true;
    }
    return false;
}


void Stack::print()
{
    List::print();
}


void Stack::max_value()
{
    int temp = 0;
    for (int i = 0; i < size(); i++)
    {
        List::setPos(i);
        temp = List::getElement();
        if (temp > max)
        {
            max = temp;
        }
    }
}


int Stack::get_max()
{
    return max;
}

class Queue : virtual public List
{
    public:
    void pop(); //remove first value placed in the stack
    int size(); 
    void push(int);
    int top();
    bool empty();
    bool full();
    void print();
    void push_stack(int);
    void pop_stack();
    int top_stack();
    
    Queue();
    
    private:
    Stack auxiliary;
};

Queue::Queue():List()
{
    outfile << "Queue constructed\n";
}


void Queue::pop()
{
    if (List::empty())
    {
       return; 
    }
    List::last();
    List::erase();
}

int Queue::size()
{
    return List::size();
    
}

void Queue::push(int value)
{
    List::first();
    List::insertBefore(value);
}

int Queue::top()
{
    List::last();
    return List::getElement();
}

bool Queue::empty()
{
    return List::empty();
}

bool Queue::full()
{
    if (List::size() == 20)
    {
        return true;
    }
    return false;
}

void Queue::print()
{
    List::print();
}


void Queue::push_stack(int store)
{
    auxiliary.push(store);
}


void Queue::pop_stack()
{
    if (!auxiliary.empty())
    {
        auxiliary.pop();
    }
}


int Queue::top_stack()
{
    return auxiliary.top();
}


int main()
{
    
	outfile.open("outfile-queue.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!";
		return 1;
	}
	
	outfile << "input:\n";
    Queue q;
    for (int i = 11; i <= 20; i++)
    {
        q.push(i);
        outfile << i << " "; 
    }
    
    
    outfile << endl;
    
    for (int i = 0; i < 10; i++)
    {
        q.push_stack(q.top());
        q.pop();
    }
    
    
    for (int i = 0; i < 10; i++)
    {
        q.push(q.top_stack());
        q.pop_stack();
    }
    
    
    for (int i = 0; i < 10; i++)
    {
        q.push_stack(q.top());
        q.pop();
    }
    
    for (int i = 0; i < 5; i++)
    {
        q.push(q.top_stack());
        q.pop_stack();
    }
    
    
    for (int i = 0; i < 10; i++)
    {
        q.push_stack(q.top());
        q.pop();
        q.push(q.top_stack());
        q.pop_stack();
        q.push(q.top_stack());
        q.pop_stack();
    }
    
    outfile << "output:\n";
    for (int i = 0; i < 10; i++)
    {
        outfile << q.top() << " ";
        q.pop();
    }
    
    outfile << endl;
    
    return 0;
}