// Read a Program & Store in Binary Tree & Linked List
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
	    if (ptr->data == "end args")
	    {
	        if (ptr->data == "end args")
	        {
                outfile << "Function Variables:" << endl;
	        }
	        else
	        {
	           // do nothing
	        }
	    }
	    else if (ptr->data == "end function")
	    {
	        outfile << "END FUNCTION\n" << endl;
	    }
	    else
	    {
            outfile << "line: " << ptr->line << " data: " << ptr->data << endl;
	    }
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
    
    if (ptr != NULL)
    {
        row.line = ptr->line;
        row.data = ptr->data;
        deleteNode(position);
        position++;
        
        return row;
    }
    else
    {
        row.line = 9999;
        row.data = "NULL";
        return row;
    }
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
    
    void insert_node(LL &);
    void remove_node(int);
    void inorder(ofstream &outfile) 
    { 
        outfile << "Print Binary Tree Inorder\n";
        inorder(root, outfile);
        outfile << endl;
    }
    void preorder(ofstream &outfile)
    { 
        preorder(root, outfile); 
        outfile << "print preorder: ";
        
    }
    void postorder(ofstream &outfile)
    { 
        postorder(root, outfile); 
        outfile << "print postorder: ";
        
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
    
    while (row.data != "end function")
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
        outfile << "FUNCTION NAME: " << endl;
        outfile << "line: " << ptr->index << " data: " << ptr->function_name << endl;
        outfile << "Function Arguments" << endl;
        ptr->llist->displayList();
        // outfile << "END OF FUNCTION" << endl;
        inorder(ptr->right, outfile);
    }
}

void BTree::preorder(tnode *ptr, ofstream &outfile)
{
    if (ptr)
    {
        outfile << ptr->value << endl;
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
        outfile << ptr->value << endl;
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

void BTree::receive_data(LL &data)
{
    Row row;
    
    bool is_func = false;
    string join;
    LL func;
    
    // clear first $
    // ensure same line not read more than twice.
    int count_line = 0;
    int what_line;
    
    bool dollar = false;
    bool star = false;
    bool args = false;
    
    int cd = 0;
    int cs = 0;
    int ca = 0;
    int enter_data = 0;
    
    string function = "";
    string arguments = "";
    string variable = "";
    
    row.line = 9999;
    row.data = "";
    data.get_data(row);
    
    while (row.data != "NULL")
    {
        string h;
        
        data.get_data(row);
        if (row.data == "*")
        {
            func.insertNode(row.line, "end args");
            data.get_data(row);
        }
        if (row.data == "$")
        {
            func.insertNode(row.line, "end function");
            insert_node(func);
            data.get_data(row);
        }
        
        h = row.data + " ";
        data.get_data(row);
        h = h + row.data;
        func.insertNode(row.line, h);
        
        
    }
}


LL p_data;

void read_line(string c, int index)
{
    c = trim_whitespace(c);
    // const char *ptr = c.c_str();
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
        
        token = strtok(NULL, "(,);= + ");
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
    string important[7] = {"int ", "char ", "float ", "double ", "string ", "struct ", "void"}; 
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
    int index = 1;
    string check;
    int open = 0;
    
    while(infile.good())
    {
	    getline(infile, line); 
	    int find_misc = line.find("_float =");
	    if (find_misc > -1)
	    {
	        cout << index << " " << line << endl;
	        getline(infile, line);
	    }
	    check = check_line(line);
	    if (check == "void")
	    {
	        read_line("$", index);
    	    read_line(line + "*", index);
	        
	    }
	    else if (check == "var")
	    {
	        int find_paren = line.find("(");
	        int find_plus = line.find("+");
	        int find_equal = line.find("=");
	        
	        if (find_plus > -1)
	        {
	            line.erase(find_plus, line.size() - find_plus);
	        }
	        if (find_equal > -1)
	        {
	            line.erase(find_equal, line.size() - find_equal);
	        }
	        if (find_paren > -1)
	        {
    	        read_line(line, index);
	        }
	        else
	        {
    	        read_line(line, index);
	        }
	    }
	    ++index;
    }
    read_line("$",9999);
    
    p_data.displayList();    
    outfile << "Trevor Gevers: The following program reads a program and stores \n";
    outfile << "it in a Binary Tree & Linked List\n" << endl;
    t.receive_data(p_data);
    t.inorder(outfile);
    outfile << "demo" << endl;
    return 0;
}