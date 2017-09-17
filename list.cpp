// List.cpp : Defines the entry point for the console application.
//

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
    position = CAPACITY - 1;
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
    
    for (int i = 0; i < CAPACITY; i++)
    {
        if (data[i] != 0)
        {
            my_size = i + 1;
        }
        if (data[i] == 0)
        {
            break;
        }
    }
}
int main()
{
    // OPEN OUTPUT FILE
	outfile.open("outfile-List.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!";
		return 1;
	}
	
	// DR. BRADY RHIMES MAIN PROGRAM
  	List a,b;  int endit;

	for (int i=1;i<=20;i++)
	   a.insertAfter(i*2);
	outfile << "List a : " << endl;
    outfile << "  "  << a << endl;
	outfile << "Number of elements in a - " << a.size() << endl;

	for (int i=1;i<=20;i++)
	   b.insertBefore(i*2);
	outfile << "List b : " << endl;
    outfile << "  "  <<  b << endl;
	outfile << "Number of elements in b - " << b.size() << endl;

	if ( a == b )
	    outfile << "List a & b are equal" << endl;
	  else
	    outfile << "List a & b are Not equal" << endl;

	a.first();
	b.first();
	outfile << "First element in List a & b: " << a.getElement() << ", "
				       << b.getElement() << endl;
	for ( int i = 0; i < a.size(); a.next(),i++);
	for ( int i = 0; i < b.size(); b.next(),i++);
	outfile << "Last element in List a & b: " << a.getElement() << ", "
				     << b.getElement() << endl;
	outfile << endl << endl << " Start of new stuff" << endl;

	outfile << "a = " << a << endl;
	outfile << "b = " << b << endl;

	a.first();
	b.first();
	endit = a.size()/2;
	for ( int i = 1; i<endit; i++)
	{  a.next();
	   b.next();
	}
	
	a.last();
	b.last();
	a.insertAfter(100);
	a.insertBefore(99);
	outfile << " Test last " << endl;
	outfile << "a = " << a << endl;
	outfile << "b = " << b << endl;

	outfile << "New position in Obj 'a' position = " << a.size()/2 << endl;

	for ( int i=1; i<8; i++)
	{
	   a.erase();
	   b.replace(i);
	}

	outfile << "Modified Object 'a' " << endl;
    outfile << "List a: " << a << endl;

	List c(b);
	outfile << "Copy Constructor c(b)" << endl;
    outfile << "List b : " << b << endl;
    outfile << "List c : " << c << endl;

	if ( c == b )
	    outfile << "List c & b are equal" << endl;
	  else
	    outfile << "List c & b are Not equal" << endl;


	List e;
	e = c;
	outfile << "Object 'c' assigned to Object 'e':" << endl;
    outfile << "List c : " << c << endl;
    outfile << "List e : " << e << endl;

    List d;
	d=a;
	d.first();
	endit = d.size()/2;
	for (int i=1; i<=endit; i++)
	{
		d.next();
		d.erase();
	}
	outfile << "Results after some erases: Object d  " << endl;
    outfile << "List d : " << d << endl;

	d.first();
	endit = d.size();
	for ( int i = 1; i < endit; d.next(), i++)
	{
		d.insertBefore(d.getElement()*3);
		d.next();
	}
	outfile << "Results after some Replaces on d " << endl;
    outfile << "List d : " << d << endl;

	a.first();
	endit = a.size();
	for ( int i = 1; i < endit; a.next(), i++)
	{
		a.insertBefore(a.getPos()+a.getElement());
		a.next();
		a.erase();
	}
	outfile << "Results after some weird stuff on List a" << endl;
    outfile << "List a : " << a << endl;

    List aList(b);
    aList.clear();
    for (int i=1;i<=10;i++)
	   aList.insertAfter(i);
	aList.first();
	outfile << "New List aList with positions above: " << endl;
    for (int i=1;i<=10;i++) {
		outfile << setw(5) << aList.getPos();
		aList.next();
	}
	outfile << endl;
	aList.first();
	for (int i=1;i<=10;i++) {
		outfile << setw(5) << aList.getElement();
		aList.next();
	}
	outfile << endl;
	
    List newa;
    for (int i=1;i<=20;i++)
	   newa.insertAfter(i*3);
    outfile << "List aList and newa before swap " << endl;
    outfile << " " << aList << endl;
    outfile << " " << newa << endl;

	outfile << endl << "  check out boundary conditions" << endl;
	List sq;
	outfile << "number of elements in empty sq List = " << sq.size() << endl;
	sq.first();
	sq.erase();
	outfile << "empty sq values " << sq << endl;
	sq.insertBefore(999);
	outfile << "sq values " << sq << endl;
	sq.next(); sq.next();
	outfile << "sq.getElement() = " << sq.getElement() << endl;
	outfile << "sq values " << sq << endl;
// 	system("pause");   //This statement not needed in code blocks, just VS.
	return 0;
}

