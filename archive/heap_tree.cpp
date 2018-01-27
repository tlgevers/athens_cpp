// Heap Program | CS 372 | Trevor Gevers
//
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;

ifstream infile;
ofstream outfile;

class List
{
    public:
    // TYPEDEF VALUES AND SIZE OF ARRAY VALUE
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 301; 
    
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
    void insertBefore(string);
    void insertAfter(string);
    size_type size();
    void decrement_size();
    void replace(string);
    void erase();
    void clear();
    string getElement();
    
// JUST FOR INITIAL TESTING
    void print(); 
// JUST FOR INITIAL TESTING
    
    
	friend std::ostream &operator<<(std::ostream &, List &);
    bool operator==(List &); 
    void operator+(List &);
    void operator=(List &);
	
    private:
    
    string data[CAPACITY];
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
    my_size = 1;
    set_to_zero();
    
    for (int i = 0; i < CAPACITY; i++)
    {
        data[i] = A.data[i];
    }
}


void List::set_to_zero()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        data[i] = "";
    }
}


bool List::empty() 
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (data[i] != "")
        {
            return false;
        }
    }
    return true;
}


void List::first()
{
    position = 1;
}


void List::last()
{
    position = my_size;
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


void List::insertBefore(string value)
{
    if (my_size == CAPACITY)
    {
        return;
    }
    
    if (data[position] == "")
    {
        data[position] = value;
        return;
    }
    
    if (position == 0) {
        for (int i = my_size + 1; i > (position); i--)
        {
            data[i] = data[i - 1];
        }
        data[position] = value;
        return;
    }
    
    for (int i = my_size + 1; i > (position - 1); i--)
    {
       data[i] = data[i - 1];
    }
    
    data[position - 1] = value;
}


void List::insertAfter(string value)
{
    my_size++;
    if (my_size == CAPACITY)
    {
       return;
    }

    if (data[position] == "")
    {
        data[position] = value;
        return;
    }

    if (position == 0) {
        for (int i = my_size + 1; i > (position); i--)
        {
            data[i] = data[i - 1];
        }
        data[position + 1] = value;
        return;
    }
    
    for (int i = my_size + 1; i > position + 1; i--)
    {
       data[i] = data[i - 1];
    }
    
    data[position + 1] = value;
}


string List::getElement()
{
    return data[position];
}


std::size_t List::size()
{
    return my_size;
}

void List::decrement_size()
{
    my_size = my_size - 1;
}

void List::replace(string new_value)
{
    data[position] = new_value;
}


void List::erase()
{
    data[position] = ""; 
}


void List::clear()
{
    this->set_to_zero();
}

// JUST FOR INITIAL TESTING
void List::print()
{
    for (int i = 0; i < 20; i++)
    {
        if (i % 20 == 0)
        {
            outfile << endl;
        }
        outfile << data[i] << " ";
    }
    outfile << "\n";
}
// JUST FOR INITIAL TESTING

std::ostream & operator<<(std::ostream &out, List &A)
{
    for (int i = 0; i < 600; i++)
    {
        if (A.data[i] != "")
        {
            out << A.data[i] << " ";
        }
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
}


void List::operator=(List &L)
{
    for (int i = 0; i < CAPACITY; i++)
    {
        data[i] = L.data[i];
    }
}


class HEAP
{
private:
    List list;
    
public:
    HEAP() { list.setPos(1); }
    void insert(string v)
    {
        list.setPos(list.size() + 1);
        list.insertAfter(v);
        walk_up();
    }
    void walk_up()
    {
        if (list.size() == 1)
            return;
        else
        {
            int pos = list.getPos();
            list.setPos(pos);
            
            string child = list.getElement();
            int child_position = pos;
            
            pos = pos / 2;
            list.setPos(pos);

            string parent = list.getElement();
            int parent_position = pos;
            
            if (pos == 1)
            {
                if (parent < child)
                {
                    list.setPos(child_position);
                    list.replace(parent);
                    
                    list.setPos(parent_position);
                    list.replace(child);
                }
            }
            else
            {
                bool check = false;
                while (check == false)
                {
                    if (parent < child)
                    {
                        list.setPos(child_position);
                        list.replace(parent);
                        
                        list.setPos(parent_position);
                        list.replace(child);
                        child_position = parent_position;
                    }
                    pos = pos / 2;
                    if (pos == 1)
                    {
                        pos = 1; 
                    }
                    parent_position = pos;
                    list.setPos(pos);
                    parent = list.getElement();
                    if (pos == 0)
                    {
                        check = true;
                    }
                }
            }
        }
    }
    void print_heap()
    {
        list.print();
    }
    void delete_heap()
    {
        int last_pos = list.size();
        list.setPos(last_pos);
        string last = list.getElement();
        list.erase();
        
        list.setPos(1);
        list.replace(last);
        
        bool greater = true;
        int pos = 1;
        last_pos = pos;
        
        string child_left = "";
        string child_right = "";
        int max_value_postion;
        
        while(greater)
        {
            int left_pos = pos * 2;
            if (left_pos <= list.size())
            {
                list.setPos(left_pos); 
                child_left = list.getElement();
            }
            int right_pos = (pos * 2) + 1; 
            if (right_pos <= list.size())
            {
                list.setPos(right_pos);
                child_right = list.getElement();
            }
            
            string max_value = max(child_left, child_right);
            
            if (max_value == child_left)
            {
                max_value = child_left;
                max_value_postion = left_pos;
            }
            else
            {
                max_value = child_right;
                max_value_postion = right_pos;
            }
            
            if (max_value > last)
            {
                list.setPos(last_pos);
                list.replace(max_value);
                list.setPos(max_value_postion);
                list.replace(last);
                pos = max_value_postion;
                last = max_value;
            }
            else
            {
                greater = false;
            }
        }
        list.decrement_size();
    }
    string get_heap()
    {
        list.setPos(1);
        return list.getElement();
    }
};

int main()
{
    
    HEAP h;
    
    outfile.open("outfile-heap-tree.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!";
		return 1;
	}
	
	infile.open("HeapPriortyNbrs.dat");
	if (!infile)
	{
	    outfile << "The infile did not open!";
	    return 1;
	}
    
    string line;
    int count = 0;
    while(infile >> line)
    {   
        h.insert(line);
        
    }
    
    outfile << "Print the heap: " << endl;
    h.print_heap();
    outfile << "The top of the heap is: " << h.get_heap() << endl;
    outfile << "Delete from the heap." << endl;
    h.delete_heap();
    outfile << "The new top of the heap is: " << h.get_heap() << endl;
    outfile << "Delete from the heap." << endl;
    h.delete_heap();
    outfile << "The new top of the heap is: " << h.get_heap() << endl;
    outfile << "Delete from the heap." << endl;
    h.delete_heap();
    outfile << "The new top of the heap is: " << h.get_heap() << endl;
    outfile << "Delete from the heap." << endl;
    h.delete_heap();
    outfile << "The new top of the heap is: " << h.get_heap() << endl;
    
    outfile << "Print the heap: " << endl;
    h.print_heap();
    return 0;
}