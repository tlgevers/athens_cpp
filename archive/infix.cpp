
// Infix & Postfix Program
// Trevor Gevers / Data Structures 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;


ofstream outfile;
ifstream infile;


class ListFloat
{
    public:
    // TYPEDEF VALUES AND SIZE OF ARRAY VALUE
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 40; 
    
    // CONSTRUCTORS
    ListFloat(); 
    ListFloat(ListFloat &A);
    
    // METHODS
    bool empty();
    void first();
    void last();
    void prev();
    void next();
    value_type getPos();    
    void setPos(value_type);
    void insertBefore(float);
    void insertAfter(float);
    size_type size();
    void replace(int);
    void erase();
    void clear();
    void left_justify();
    float getElement();
    
// JUST FOR INITIAL TESTING
    void print(); 
// JUST FOR INITIAL TESTING
    
    
	friend std::ostream &operator<<(std::ostream &, ListFloat &);
    bool operator==(ListFloat &); 
    void operator+(ListFloat &);
    void operator=(ListFloat &);
	
    private:
    
    float data[CAPACITY];
    // char indata[CAPACITY];
    size_type my_size;
    value_type position;     
    void set_to_zero();
    
};


ListFloat::ListFloat()
{
    first();    
    my_size = 0;
    set_to_zero();
}


ListFloat::ListFloat(ListFloat &A)
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


void ListFloat::set_to_zero()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        data[i] = 0;
    }
}


bool ListFloat::empty() 
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


void ListFloat::first()
{
    position = 0;
}


void ListFloat::last()
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


void ListFloat::prev()
{
    if (position <= 0)
    {
        return;
    }
    position--;
}


void ListFloat::next()
{
    if (position >= (CAPACITY - 1))
    {
        return;
    }
    position++;
}


int ListFloat::getPos()
{
    return position;
}


void ListFloat::setPos(int p)
{
    if (p > (CAPACITY - 1)|| p < 0)
    {
        return;
    }
    position = p;    
}


void ListFloat::insertBefore(float value)
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


void ListFloat::insertAfter(float value)
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


float ListFloat::getElement()
{
    return data[position];
}


std::size_t ListFloat::size()
{
    return my_size;
}


void ListFloat::replace(int new_value)
{
    data[position] = new_value;
}


void ListFloat::erase()
{
    data[position] = 0; 
    left_justify();
}


void ListFloat::clear()
{
    this->set_to_zero();
}

// JUST FOR INITIAL TESTING
void ListFloat::print()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        outfile << data[i] << " ";
    }
    outfile << "\n";
}
// JUST FOR INITIAL TESTING

std::ostream & operator<<(std::ostream &out, ListFloat &A)
{
    float *ptr;
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


bool ListFloat::operator==(ListFloat &L)
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


void ListFloat::operator+(ListFloat &L)
{
   for (int i = 0; i < CAPACITY; i++)
   {
       data[i] = data[i] + L.data[i];
   }
   left_justify();
}


void ListFloat::operator=(ListFloat &L)
{
    for (int i = 0; i < CAPACITY; i++)
    {
        data[i] = L.data[i];
    }
    left_justify();
}

void ListFloat::left_justify()
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

class StackFloat : virtual public ListFloat
{
    public:
    int max;
    void pop(); //remove last value placed in StackFloat, last value in
    int size(); 
    void push(float);
    int top();
    bool empty();
    bool full();
    void print();
    void max_value();
    int get_max();
    StackFloat();
    
    private:
};

StackFloat::StackFloat():ListFloat()
{
    max = 0;      
    outfile << "StackFloat Constructed\n";
}


void StackFloat::pop()
{
    if (ListFloat::empty())
    {
       return; 
    }
    ListFloat::last();
    ListFloat::erase();
    max_value();
}


int StackFloat::size()
{
    return ListFloat::size();
    
}


void StackFloat::push(float value)
{
    ListFloat::last();
    ListFloat::insertAfter(value);
    max_value();
}


int StackFloat::top()
{
    ListFloat::last();
    return ListFloat::getElement();
}


bool StackFloat::empty()
{
    return ListFloat::empty();
}


bool StackFloat::full()
{
    if (ListFloat::size() == 20)
    {
        return true;
    }
    return false;
}


void StackFloat::print()
{
    ListFloat::print();
}


void StackFloat::max_value()
{
    int temp = 0;
    for (int i = 0; i < size(); i++)
    {
        ListFloat::setPos(i);
        temp = ListFloat::getElement();
        if (temp > max)
        {
            max = temp;
        }
    }
}


int StackFloat::get_max()
{
    return max;
}


class List
{
    public:
    // TYPEDEF VALUES AND SIZE OF ARRAY VALUE
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 40; 
    
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
    
    char data[CAPACITY];
    // char indata[CAPACITY];
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
        data[i] = 0.0;
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
    char *ptr;
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

//Prototypes
void pushStack(Stack &, char);
char topStack(Stack &);
void popStack(Stack &);

void pushStackFloat(StackFloat &, float);
float topStackFloat(StackFloat &);
void popStackFloat(StackFloat &);

void pushQueue(Queue &, char);
char topQueue(Queue &);
void popQueue(Queue &);

void setupInfix(string);
void setupPostfix();
int rankInfix(char);
int rankPostfix(char);
float evaluate(float,float,char);
void clearData();

//Variables
Stack math;
StackFloat num;

Queue infix;
Queue postfix;

//Functions for Stack Management
void pushStack(Stack &st, char v)
{
    st.push(v);
}


char topStack(Stack &st)
{
    return st.top();
}


void popStack(Stack &st)
{
   st.pop();
}


void pushStackFloat(StackFloat &st, float v)
{
    st.push(v);
}


float topStackFloat(StackFloat &st)
{
    return st.top();
}


void popStackFloat(StackFloat &st)
{
   st.pop();
}


//Functions for Queue Management
void pushQueue(Queue &q, char v)
{
    q.push(v);
}


char topQueue(Queue &q)
{
    q.top();
}


void popQueue(Queue &q)
{
    q.pop();
}


//Infix Postfix Logic
void setupInfix(string c)
{
    const char *ptr = c.c_str();
    
    while (*ptr)
    {
        if(!isspace(*ptr))
        {
            pushQueue(infix, *ptr);
        }
        ptr++;
    }
    pushQueue(infix, '$');
}


void setupPostfix()
{
    char top_math;
    char top_infix;
    char decision;
    int r_top_infix;
    int r_top_math;
    
    
    while(topQueue(infix) != '$')
    {
        top_infix = topQueue(infix);
        
        if (isdigit(top_infix))
        {
            pushQueue(postfix, top_infix);
            popQueue(infix);
        }
        else {
            
            top_math = topStack(math);
            r_top_infix = rankInfix(top_infix);
            r_top_math = rankPostfix(top_math);
            
            if (r_top_infix == 0)
            {
                if (r_top_math != 0)
                {
                    while(r_top_math != 0)
                    {
                        pushQueue(postfix, top_math);
                        popStack(math);
                        top_math = topStack(math);
                        r_top_math = rankPostfix(top_math);
                    }
                    popQueue(infix);
                    popStack(math);
                }
                else
                {
                    popQueue(infix);
                }
            }
            else
            {
                if (r_top_infix <= r_top_math && top_math != '$')
                {
                    pushQueue(postfix, top_math);
                    popStack(math);
                    
                    pushStack(math, top_infix);
                    popQueue(infix);
                }
                else
                {
                    pushStack(math, top_infix);
                    popQueue(infix);
                }
            }
        }
        top_infix = topQueue(infix);
        if (top_infix == '$')
        {
            top_math = topStack(math);
            if (top_math != '$')
            {
                while(top_math != '$')
                {
                    r_top_math = rankPostfix(top_math);
                    if (r_top_math != 0)
                    {
                        pushQueue(postfix, top_math);
                        popStack(math);
                    }
                    else
                    {
                        popStack(math);
                    }
                    top_math = topStack(math);
                }
            }
        }
    }
    pushQueue(postfix, '$');
}

int rankInfix(char c)
{
    switch (c)
    {
        case '*': return 2;
            break;
        case '/': return 2;
            break;
        case '+': return 1;
            break;
        case '-': return 1;
            break;
        case '(': return 3;
            break;
        case ')': return 0;
            break;
        case '^': return 4;
            break;
        default: return 0;
        
    }
}


int rankPostfix(char c)
{
    switch (c)
    {
        case '*': return 2;
            break;
        case '/': return 2;
            break;
        case '+': return 1;
            break;
        case '-': return 1;
            break;
        case '(': return 0;
            break;
        case '^': return 4;
            break;
        default: return 0;
        
    }
    return 0;
}


float evaluate(float v1, float v2, char op)
{
    float sum;
    switch (op)
    {
        case '+': sum = ((float)v1) + v2; return sum;
            break;
        case '-': sum = ((float)v1) - v2; return sum;
            break;
        case '*': sum = ((float)v1) * v2; return sum;
            break;
        case '/': sum = ((float)v1) / v2; return sum; 
            break;
        case '^': sum = (pow(((float)v1), v2)); return sum;
            break;
        default: outfile << "not an operator.\n";
            break;
        return 0;
    }
}


void clearData()
{
    char top_postfix = topQueue(postfix);
    while (top_postfix != 0)
    {
        popQueue(postfix);
        top_postfix = topQueue(postfix);
    }
    
    char top_math = topStack(math);
    while (top_math != 0)
    {
        popStack(math);
        top_math = topStack(math);
    }
    
    float top_num = topStackFloat(num);
    while (top_num != 0)
    {
        popStackFloat(num);
        top_num = topStackFloat(num);
    }
    
    char top_infix = topQueue(infix);
    while (top_infix != 0)
    {
        popQueue(infix);
        top_infix = topQueue(infix);
    }
}


int main()
{
    
	outfile.open("outfile-InfixOutfix.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!";
		return 1;
	}
	
	infile.open("infix_input.txt");
	if (!infile)
	{
	    outfile << "The infile did not open!";
	    return 1;
	}
	
    
    string line;	
    int check = 0;
    
	while(infile.good())
	{
        pushStack(math, '$'); 
	    getline(infile, line); 
	    setupInfix(line);
	    outfile << "The line read is: " << line << endl;
        setupPostfix();
        outfile << "The postfix is:\n";
        postfix.print();
        
        float sum = 0;
        double o1;
        double o2;
        char op;
        char top_postfix;
        char top_num;
        
        while(topQueue(postfix) != '$')
        {
            
            top_postfix = topQueue(postfix);
            
            if (isdigit(top_postfix))
            {
                pushStackFloat(num, (top_postfix - '0') * 100);
                popQueue(postfix);
                top_postfix = topQueue(postfix);
            }
            else
            {
                op = top_postfix;
                
                o1 = topStackFloat(num) / 100;
                popStackFloat(num);
                
                o2 = topStackFloat(num) / 100;
                popStackFloat(num);
                
                
                if (o1 < 0 || o2 < 0 && op == '-')
                {
                    sum = (evaluate(o1, o2, op));
                }
                else
                {
                    sum = (evaluate(o2, o1, op));
                }
                pushStackFloat(num, sum * 100);
                
                popQueue(postfix);
                top_postfix = topQueue(postfix);
            }
            
            top_postfix = topQueue(postfix);
        }
        outfile << "The evaluation is: " << sum << endl;
	    clearData();
	    
	    outfile << endl;
	    
	}
	
    
    outfile << endl;
    outfile.close();
    
    return 0;
}