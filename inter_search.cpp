//******************************************************
// INTERPOLATION SEARCH PROGRAM | TREVOR GEVERS | CS 372
//
// Notes:   In order to generate a unique list of random numbers, a binary tree was
//          used to store the random numbers and delete them as they were used.          
//_________________

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
using namespace std;

//*****************
// GLOBAL VARIABLES
//_________________

struct tnode
{
    int value;
    int count;
    tnode * left;
    tnode * right;
};

struct inter_search_info
{
  int index;
  double probes;
};

ofstream outfile;
int counter = 0;

//*******************************

//********************
// FUNCTION PROTOTYPES
//____________________

int populate_tree();
int random_number(int);
bool check_value(int);
void populate_unique_random_list();
void swap(int *, int *);
int partition (int [], int, int);
void quickSort(int [], int, int);
void swap(int [], int, int);
inter_search_info interSearch(int [], int, int);
void print_list(int);

//*******************************

//******************
// ARRAY DECLARATION
//__________________

const int CAPACITY = 15000;
int list_rand_numbers[CAPACITY];
int list_probes[5000];

//*******************************

//****************************
// BINARY TREE FOR UNIQUE DATA
//_______________________________

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
    void deepest_value(tnode *, int, int &, int &);
    int one_child_count(tnode *);
public:
    // Constructor
    BTree() { root = NULL; }

    // Destructor
    ~BTree() { }
    
    void insert_node(int);
    void remove_node(int);
    void inorder(ofstream &outfile) 
    { 
        inorder(root, outfile);
    }
    void preorder(ofstream &outfile)
    { 
        preorder(root, outfile); 
    }
    void postorder(ofstream &outfile)
    { 
        postorder(root, outfile); 
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
    bool search(int v)
    {
        bool check = search(root, v, false);
        return check;
    }
    int duplicate_count(ofstream &outfile)
    {
        outfile << "The number of duplicates is: " << duplicate_count(root) << endl;
    }
    int deepest_value(ofstream &outfile)
    {
        int value = -1;
        int level = -1;
        int max = 0;
        deepest_value(root, level, max, value);
        outfile << "The deepest value is: " << value << endl;
    }
    int one_child_count(ofstream &outfile)
    {
        int count = 0;
        count = one_child_count(root);
        outfile << "The number of nodes with one child is: " << count << endl;
    }
    int sum_digits(int);
};

void BTree::insert_node(int value)
{
        tnode * node = NULL;
        node = new tnode;
        node->value = value;
        node->left = node->right = NULL;
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
        outfile << ptr->value << " count: " << ptr->count << endl;
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

void BTree::deepest_value(tnode *ptr, int l, int &max, int &result)
{
    if (ptr != NULL)
    {
        deepest_value(ptr->left, ++l, max, result);
        if (l > max)
        {
            result = ptr->value;
            max = l;
        }
        deepest_value(ptr->right, l, max, result);
    }
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
//*******************************

BTree unique_list;

int main()
{
    outfile.open("outfile-inter_searcha.txt");
    if (!outfile)
    {
        cout << "Houston, we have a problem! and it's you're programming!" << endl;
    }
    
    populate_tree();
    populate_unique_random_list();
    
    quickSort(list_rand_numbers, 0, 15000);
    
    int search_times = 0;
    int search_index;
    inter_search_info index;
    double sum_probes = 0;
    
    while(search_times != 5000)
    {
        search_index = random_number(14999);
        int find = list_rand_numbers[search_index];
        index = interSearch(list_rand_numbers, find, CAPACITY);
        list_probes[search_times] = index.probes;
        sum_probes = sum_probes + index.probes;
        cout << index.probes << endl;
        search_times++;
    }
    
    outfile << "Interpolation Search Program Output File | CS372 | Trevor Gevers" << endl;
    outfile << endl;
    outfile << "The average number of probes to find the values is: " << sum_probes / 5000 << endl;
    
    outfile.close();
    return 0;
}

void populate_unique_random_list()
{
    int index = 0;
    bool check;
    int random;
    
    for (int i = 0; i < 5000; i++)
    {
        index = i;
        for (int j = 0; j < 3; j++)
        {
            check = false;
            while (check == false)
            {
                random = random_number(20000);
                check = unique_list.search(random);
                if (check)
                {
                    unique_list.remove_node(random);
                }
            }
            if (j == 1)
            {
                index = i + 5000;
            }
            if (j == 2)
            {
                index = i + 10000;
            }
            list_rand_numbers[index] = random;
        }
    }
}

int populate_tree()
{
    int count = 1;
    
    while (count != 20001)
    {
        unique_list.insert_node(count);    
        count++;
    }
}

int random_number(int top)
{
    int random;
    random = rand() % top + 1; 
    return random;
}

bool check_value(int v)
{
    bool check;
    check = unique_list.search(v);
    return check; 
}

void quickSort(int arr[], int lower, int upper) 
{
    if (upper <= lower)
    {
        return;
    }
    
    int pivot = arr[lower];
    int start = lower;
    int stop = upper;
    
    while (lower < upper)
    {
        while (arr[lower] <= pivot && lower < upper)
        {
            lower++;
        }
        while (arr[upper] > pivot && lower <= upper)
        {
            upper--;
        }
        if (lower < upper)
        {
            swap(arr, upper, lower);
        }
    }
    swap(arr, upper, start);
    quickSort(arr, start, upper - 1);
    quickSort(arr, upper + 1, stop);
    
}

void swap(int arr[], int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

inter_search_info interSearch(int list[], int data, int MAX)
{
    inter_search_info info;
    info.probes = 0;
    info.index = -1;
    int lo = 0;
    int hi = MAX - 1;
    int mid = -1;
    int comparisons = 1;      
    
    while(lo < hi) {
      
      info.probes++;
    
      mid = lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo]));
    
      if(list[mid] == data) {
         info.index = mid;
         break;
      } 
      else 
      {
         if(list[mid] < data)
         {
            lo = mid + 1;
         } 
         else 
         {
            hi = mid - 1;
         }
      }               
    }
    return info;
}

void print_list(int CAP)
{
    for (int i = 0; i < CAP; i++)
    {
        if (i % 50 == 0)
        {
            outfile << endl;
        }
        outfile << list_rand_numbers[i] << endl;
    }
}

