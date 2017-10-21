
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
    
    
	friend std::ostream &operator<<(std::ostream &, ListFloat &);
    bool operator==(ListFloat &); 
    void operator+(ListFloat &);
    void operator=(ListFloat &);
	
    private:
    
    char data[CAPACITY];
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


void ListFloat::insertBefore(int value)
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


void ListFloat::insertAfter(int value)
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


int ListFloat::getElement()
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
        cout << data[i] << " ";
    }
    cout << "\n";
}
// JUST FOR INITIAL TESTING

std::ostream & operator<<(std::ostream &out, ListFloat &A)
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
    void push(int);
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
    cout << "StackFloat Constructed\n";
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


void StackFloat::push(int value)
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