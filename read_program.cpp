// Read a Program & Store in Binary Tree
// Trevor Gevers / Data Structures CS 372

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

ofstream outfile;
ifstream infile;
bool activate = false;

void read_line(string, int);
string trim_whitespace(string); 
string check_line(string);
bool check_numbers(string);

struct ListNode
{
    int index;
	int line;
	string data;
	struct ListNode *link;
};

struct Row
{
    int line;
    string data;
};

class LL
{
private:
	void printReverse(ListNode *, ofstream &);
public:
	ListNode *head;
	LL()
	{
		head = NULL;
		index = 1;
		position = 1;
	}
    int index;
    int position;
	ListNode * newNode(int, string);
	void insertNode(int, string);
	void deleteNode(int);
	void displayList() const;
	void distribute();
	bool check_average();
	ListNode * searchLine(int);
	void printReverse(ofstream &outfile)
	{
		outfile << "print reverse of link list " << endl;
		printReverse(head, outfile);
	}
	int get_index();
	Row get_data(Row &);
};

ListNode * LL::newNode(int g, string n)
{
	ListNode *Node;

	Node = new ListNode;
	Node->index = index;
	Node->line = g;
	Node->data = n;
	Node->link = NULL;
    ++index;

	return Node;
}

void LL::insertNode(int line, string data = "")
{
	ListNode *Node = newNode(line, data);
	ListNode *ptr;
	ListNode *prev = NULL;

	if (!head)
	{
		head = Node;
	}
	else
	{
		ptr = head;
		prev = NULL;

		while (ptr != NULL && ptr->line <= line)
		{
			prev = ptr;
			ptr = ptr->link;
		}
		if (prev == NULL)
		{
			head = Node;
			Node->link = ptr;
		}
		else
		{
			prev->link = Node;
			Node->link = ptr;
		}
	}
}

void LL::deleteNode(int index)
{
	ListNode *ptr;
	ListNode *prev;

	prev = head;

	if (!head)
	{
		return;
	}
	if (head->index == index)
	{
		ptr = head->link;
		delete head;
		head = ptr;
	}
	else
	{
		ptr = head;

		while (ptr != NULL && ptr->index != index)
		{
			prev = ptr;
			ptr = ptr->link;
		}
		if (ptr)
		{
			prev->link = ptr->link;
			delete ptr;
		}
	}
}


void LL::displayList() const
{
	ListNode *ptr;

	ptr = head;

	while (ptr != NULL)
	{
		outfile << ptr->index << "line: " << ptr->line << " data: " << ptr->data << endl;
		ptr = ptr->link;
	}
}

void LL::distribute()
{
    ListNode *ptr;
    ptr = head;
    
    
}

ListNode * LL::searchLine(int g)
{
	ListNode * ptr;
	ptr = head;

	while (ptr != NULL)
	{
		if (ptr->line == g)
		{
			return ptr;
		}
		ptr = ptr->link;
	}
	return NULL;
}



void LL::printReverse(ListNode * ptr, ofstream &outfile)
{
	if (ptr)
	{
		printReverse(ptr->link, outfile);
		outfile << ptr->line << endl;
	}
}

int LL::get_index()
{
    return index;
}

Row LL::get_data(Row &row)
{
    ListNode *ptr;
    ptr = head;
    
    
    row.line = ptr->line;
    row.data = ptr->data;
    
    // cout << "line: " << row.line << "data: " << row.data << endl;
    
    deleteNode(position);
    position++;
    
    return row;
}

class List
{
    public:
    // TYPEDEF VALUES AND SIZE OF ARRAY VALUE
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 500; 
    
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

Stack::Stack()
{
    max = 0;      
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
    void clear();
    
    Queue();
    
    private:
    Stack auxiliary;
};

Queue::Queue():List()
{
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

void Queue::clear()
{
    List::clear();
}

struct tnode
{
    int index;
    int value;
    int count;
    string function_name;
    tnode * left;
    tnode * right;
    LL * llist;
};

class BTree
{
private:
    tnode * root;
     
    void insert(tnode *&, tnode *&);
    void delete_node(int, tnode *&);
    void deletion(tnode *&);
    void inorder(tnode *, ofstream &);
    void preorder(tnode *, ofstream &);
    void postorder(tnode *, ofstream &);
    int nodes_count(tnode *);
    int leaf_count(tnode *);
    int data_count(tnode *);
    int sum_values(tnode *);
    bool search(tnode *, int, bool);
    int duplicate_count(tnode *);
    int deepest_value(tnode *, int, int);
    int one_child_count(tnode *);
    void delete_routine(tnode *);
    void find_below_nine(tnode *);
public:
    // Constructor
    BTree() { root = NULL; }

    // Destructor
    ~BTree() { }
    
    Stack store;
    Queue printer;
    void print_stack()
    {
       store.print(); 
    }

    void insert_node(LL &);
    void remove_node(int);
    void inorder(ofstream &outfile) 
    { 
        outfile << "print inorder:\n";
        inorder(root, outfile);
        outfile << endl;
    }
    void preorder(ofstream &outfile)
    { 
        preorder(root, outfile); 
        outfile << "print preorder: ";
        
        for (int i = 0; i < 20; i++)
        {
            if (i % 5 == 0)
            {
                outfile << endl;
            }
            outfile << printer.top() << " ";
            printer.pop(); 
        }
        outfile << endl;
        printer.clear();
    }
    void postorder(ofstream &outfile)
    { 
        postorder(root, outfile); 
        outfile << "print postorder: ";
        
        for (int i = 0; i < 20; i++)
        {
            if (i % 5 == 0)
            {
                outfile << endl;
            }
            outfile << printer.top() << " ";
            printer.pop(); 
        }
        outfile << endl;
        printer.clear();
    }
    void nodes_count(ofstream &outfile)
    {
        int count = 0;
        count = nodes_count(root);
        outfile << "Number of nodes: " << count << endl;
    }
    void leaf_count(ofstream &outfile)
    {
        int count = 0;
        count = leaf_count(root);
        outfile << "Number of leaves: " << count << endl;
    }
    void data_count(ofstream &outfile)
    {
        int count = 0;
        count = data_count(root);
        outfile << "Data count is: " << count << endl;
    }
    void sum_values(ofstream &outfile)
    {
        double sum = 0;
        sum = sum_values(root);
        int count = 0;
        count = data_count(root);
        
        outfile << "The sum is: " << (sum/100) << endl;
        outfile << fixed << setprecision(2) << "The average is: " << (sum/count/100) << endl;
    }
    int duplicate_count(ofstream &outfile)
    {
        outfile << "The number of duplicates is: " << duplicate_count(root) << endl;
    }
    int deepest_value(ofstream &outfile)
    {
        int value = 0;
        value = deepest_value(root, 0, value);
        outfile << "The deepest value is: " << value << endl;
    }
    int one_child_count(ofstream &outfile)
    {
        int count = 0;
        count = one_child_count(root);
        outfile << "The number of nodes with one child is: " << count << endl;
    }
    int sum_digits(int);
    void delete_routine()
    {
        delete_routine(root);
    }
    void receive_data(LL &);
};

void BTree::insert_node(LL &func)
{
    
    Row row;
    func.get_data(row);
    
    tnode * node = NULL;
    node = new tnode;
    
    node->index = row.line;
    node->function_name = row.data;
    
    node->count = 1;
    node->left = node->right = NULL;
    node->llist = new LL;
    
    while (row.data != "*end*")
    {
        func.get_data(row);
        node->llist->insertNode(row.line, row.data);
    }
    
    
    insert(root, node);
}

void BTree::insert(tnode *&r, tnode *&t)
{
    if (r == NULL)
    {
        r = t;
    }
    else if (t->value < r->value)
    {
        insert(r->left, t);
    }
    else
    {
        insert(r->right, t);
    }
}

void BTree::remove_node(int value)
{
    delete_node(value, root);
}

void BTree::delete_node(int num, tnode *&ptr)
{
    if (num < ptr->value)
    {
        delete_node(num, ptr->left);
    }
    else if (num > ptr->value)
    {
        delete_node(num, ptr->right);
    }
    else
    {
        deletion(ptr);
    }
}

void BTree::deletion(tnode *&ptr)
{
    tnode *temp = NULL;
    
    if (ptr == NULL)
    {
        outfile << "Tree is empty" << endl;
    }
    else if (ptr->right == NULL)
    {
        temp = ptr;
        ptr = ptr->left;
        delete temp;
    }
    else if (ptr->left == NULL)
    {
        temp = ptr;
        ptr = ptr->right;
        delete temp;
    }
    else
    {
        temp = ptr->right;
        while(temp->left)
        {
            temp = temp->left;
        }
        temp->left = ptr->left;
        temp = ptr;
        ptr = ptr->right;
        delete temp;
    }
}

void BTree::inorder(tnode *ptr, ofstream &outfile)
{
    if (ptr)
    {
        inorder(ptr->left, outfile);
        outfile << " line: " << ptr->index << " data: " << ptr->function_name << endl;
        ptr->llist->displayList();
        inorder(ptr->right, outfile);
    }
}

void BTree::preorder(tnode *ptr, ofstream &outfile)
{
    if (ptr)
    {
        // outfile << ptr->value << endl;
        printer.push(ptr->value); 
        preorder(ptr->left, outfile);
        preorder(ptr->right, outfile);
    }
}

void BTree::postorder(tnode *ptr, ofstream &outfile)
{
    if (ptr)
    {
        postorder(ptr->left, outfile);
        postorder(ptr->right, outfile);
        printer.push(ptr->value); 
        // outfile << ptr->value << endl;
    }
}

int BTree::nodes_count(tnode *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    if (!ptr->left && !ptr->right)
    {
        return 1 + leaf_count(ptr->left) + leaf_count(ptr->left);
    }
    return 1 + leaf_count(ptr->left) + leaf_count(ptr->right);
}

int BTree::leaf_count(tnode *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    if (!ptr->left && !ptr->right)
    {
        return 1 + leaf_count(ptr->left) + leaf_count(ptr->right);
    }
    return leaf_count(ptr->left) + leaf_count(ptr->right);
}

int BTree::data_count(tnode *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    if (!ptr->left && !ptr->right)
    {
        return ptr->count + data_count(ptr->left) + data_count(ptr->left);
    }
    return ptr->count + data_count(ptr->left) + data_count(ptr->right);
}

int BTree::sum_values(tnode *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    if (ptr->count > 1)
    {
        return ((ptr->value*ptr->count)*100) + sum_values(ptr->left) + sum_values(ptr->right);
    }
    return (ptr->value*100) + sum_values(ptr->left) + sum_values(ptr->right);
}

bool BTree::search(tnode *ptr, int target, bool check)
{
    while (ptr != NULL)
    {
        if (ptr->value == target) 
        {
            ptr->count = ptr->count + 1;
            check = true;
        }
        if (target < ptr->value)
        {
           ptr = ptr->left;
        }
        else
        {
           ptr = ptr->right;
        }
    }
    return check;
    
}

int BTree::duplicate_count(tnode *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    if (ptr->count > 1)
    {
        return (ptr->count - 1) + duplicate_count(ptr->left) + duplicate_count(ptr->right);
    }
    else 
    {
        return (0) + duplicate_count(ptr->left) + duplicate_count(ptr->right); 
    }
}

int BTree::deepest_value(tnode *ptr, int l, int max)
{
    if (ptr == NULL)
    {
        return 0;
    }
    if (!ptr->left && !ptr->right && l > max)
    {
        max = ptr->value;
        return max;
    }
    deepest_value(ptr->left, ++l, max);
    deepest_value(ptr->right, ++l, max);
}

int BTree::one_child_count(tnode *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    if (!ptr->left && ptr->right != NULL )
    {
        return 1 + one_child_count(ptr->left) + one_child_count(ptr->right);
    }
    if (ptr->left != NULL && !ptr->right)
    {
        return 1 + one_child_count(ptr->left) + one_child_count(ptr->right);
    }
    else
    {
        return (0) + duplicate_count(ptr->left) + duplicate_count(ptr->right); 
    }
}

int BTree::sum_digits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n%10) + sum_digits(n / 10);
}

void BTree::find_below_nine(tnode *ptr)
{
    if (ptr)
    {
        find_below_nine(ptr->left);
        int check = sum_digits(ptr->value);
        if (check < 9)
        {
            store.push(ptr->value); 
        }
        find_below_nine(ptr->right);
    }
}

void BTree::delete_routine(tnode *ptr)
{
    store.empty();
    
    find_below_nine(root);
    
    while(store.top() != 0)
    {
        remove_node(store.top());
        store.pop();
    }
}

void BTree::receive_data(LL &data)
{
    // int count = data.get_index();
    Row row;
    
    bool is_func = false;
    string join;
    LL func;
    
    // clear first $
    data.get_data(row);
    data.get_data(row);
    // ensure same line not read more than twice.
    int count_line = 0;
    int what_line;
    
    while (row.data != "*end*")
    {
        what_line = row.line;
        int ready = row.data.find("$");
        int check_func = row.data.find("~");
        
        if (ready > -1)
        {
            outfile << "display func: " << endl;
            func.insertNode(999, "*end*");
            func.displayList();
            insert_node(func);
            outfile << "end func display." << endl;
            data.get_data(row);
        }
        
        if (check_func > -1)
        {
            cout << "begin func" << endl; 
            int line = row.line;
            int count = 0;
            while (row.data != "*" && row.data != "*end*")
            {
                string add = row.data;
                data.get_data(row);
                add =  add + " " + row.data;
                cout << line << " " << add << endl;
                int e = add.find("~");
                if (e > -1)
                {
                    add.erase(0,1);
                }
                func.insertNode(line, add);
                // insert_node(line, add);
                data.get_data(row);
            }
            cout << "end func" << endl; 
            func.insertNode(line, "end arguments");
            // insert_node(line, "end arguments");
            is_func = false;
        }
        else if (ready == -1)
        {
            if (what_line = row.line)
            {
                count_line++;
            }
            int line = row.line;
            string add = row.data;
            data.get_data(row);
            add = add + " " + row.data;
            string check = check_line(add);
            if (check == "var" && count_line == 2)
            {
                func.insertNode(line, add);
                // insert_node(line, add);
            }
            else if (count_line > 2)
            {
                while (what_line == row.line)
                {
                    data.get_data(row);
                }
                count_line = 0;
            }
        }
        
        // --count;
    }
}


LL p_data;

void read_line(string c, int index)
{
    // outfile << endl;
    c = trim_whitespace(c);
    const char *ptr = c.c_str();
    char * str = new char [c.length() + 1];
    strcpy(str, c.c_str());
    
    
    int find_void = c.find("void");
    int find_semic = c.find(";");
    int find_hash = c.find("#");
    int find_if = c.find("if");
    int find_for = c.find("for ");
    int find_const = c.find("const");
    
    int test = 0;
    
    
    if (find_void > -1 && find_semic > -1 || find_const > -1)
    {
        test = 1;
        // cout << test << endl;
    }
    
    char * token;
    token = strtok(str, " (;");
    while (activate == true && token != 0 && token >= 0 && c.empty() == 0 && test != 1 && find_hash == -1 && find_if == -1 && find_for == -1)
    {
        
        string tk = token;
        tk = trim_whitespace(tk);
        bool contains_num = check_numbers(tk);
        
        if (!contains_num)
        {
            p_data.insertNode(index, tk);
        }
        
        token = strtok(NULL, "(,);= ");
    }
}


string trim_whitespace(string c)
{
    string::iterator b = c.begin();
    string::iterator e = c.end();
    while (isspace(*b))
    {
        if (isspace(*b))
        {
            c.erase(c.begin());
        }
        
    } 
    while(isspace(*e))
    {
        if (isspace(*e))
        {
            c.erase(c.end());
        }
    }
    return c;
}

string check_line(string v)
{
    int find_return = v.find("return");
    if (find_return > -1)
    {
        activate = true;
    }
    string t;
    int test;
    string important[7] = {"int ", "char ", " float ", "double ", "string ", "struct ", "void"}; 
    for (int i = 0; i < 7; i++)
    {
        test = v.find(important[i]);
        if (test > -1 && i != 6)
        {
            t = "var";
        }
        if(test > -1 && i == 6) 
        {
            t = "void";
        }
    }
    return t;
}

bool check_numbers(string c)
{
    string nums[10] = {"0","1","2","3","4","5","6","7","8","9"};
    bool is_num = false;
    int test;
    for (int i = 0; i < 10; i++)
    {
        test = c.find(nums[i]);
        if (test > -1)
        {
            is_num = true;
        }
    }
    return is_num;
}


int main()
{
	outfile.open("outfile-readingC-program.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!";
		return 1;
	}
	
	infile.open("molecularWeight.dat");
	if (!infile)
	{
	    outfile << "The infile did not open!";
	    return 1;
	}
	
    BTree t;
    
    string line;	
    int index = 0;
    string check;
    int open = 0;
    
    while(infile.good())
    {
	    getline(infile, line); 
	    check = check_line(line);
	    
	    if (check == "void")
	    {
	       // cout << "void" << endl;
	        read_line("$", index);
    	    read_line("~" + line + "*", index);
	        
	    }
	    else if (check == "var")
	    {
	       // cout << "var" << endl;
	        int find_paren = line.find("(");
	        if (find_paren > -1)
	        {
    	        read_line("~" + line, index);
	       
	        }
	        else
	        {
    	        read_line(line, index);
	        }
	    }
	   // cout << index << " : " << line << endl;
	    ++index;
    }
    read_line("*end*",9999);
    
    // p_data.displayList();
    // p_data.distribute();
    p_data.displayList();
    t.receive_data(p_data);
    t.inorder(outfile);
    
    return 0;
}