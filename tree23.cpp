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


struct tnode
{
    int left_v;
    int right_v;
    int count;
    tnode * left;
    tnode * middle;
    tnode * right;
};

class TwoThreeTree
{
private:
    tnode * root;
     
    void insert(tnode *&, int);
    bool search(tnode *);
    // void inorder(tnode *, ofstream &);
    // void preorder(tnode *, ofstream &);
    // void postorder(tnode *, ofstream &);
    // int nodes_count(tnode *);
    // int leaf_count(tnode *);
    // int data_count(tnode *);
    // int sum_values(tnode *);
    // bool search(tnode *, int, bool);
    // int duplicate_count(tnode *);
    // void deepest_value(tnode *, int, int &, int &);
    // int one_child_count(tnode *);
    // void delete_routine(tnode *);
    // void find_below_nine(tnode *);
public:
    // Constructor
    TwoThreeTree() { root = NULL; }

    // Destructor
    ~TwoThreeTree() { }
    
    // Stack store;
    // Queue printer;
    // void print_stack()
    // {
    //   store.print(); 
    // }

    void insert_node(int v)
    {
        insert(root, v);
    }
    
    
    tnode * new_node(int v)
    {
        tnode * temp = NULL;
        temp = new tnode;
        temp->left_v = v;
        temp->right_v = 0;
        temp->left = NULL;
        temp->middle = NULL;
        temp->right = NULL;
        return temp;
    }
    
    bool search(tnode * ptr, int v)
    {
        if (root == NULL) return false; // value not found
        if (v == ptr->left_v)
        { 
            return true; 
        } // Found it
        if (v == ptr->right_v)
        { 
            return true; 
        } // Found it
        if (v < ptr->left_v)
        {
            // Go left
            return search(ptr->left, v);
        }
        else if (ptr->right_v == 0)
        {
            // 2 child node
            return search(ptr->middle, v); // Go center
        }
        else if (v < ptr->right_v)
        {
            return search(ptr->middle, v); // Go center
        }
        else 
        {
            return search(ptr->right, v); // Go right
        }
    }
    
    
    // void remove_node(int);
    // void inorder(ofstream &outfile) 
    // { 
    //     inorder(root, outfile);
    //     outfile << "print inorder: ";
        
    //     for (int i = 0; i < 20; i++)
    //     {
    //         if (i % 5 == 0)
    //         {
    //             outfile << endl;
    //         }
    //         outfile << printer.top() << " ";
    //         printer.pop(); 
    //     }
    //     outfile << endl;
    //     printer.clear();
    // }
    // void preorder(ofstream &outfile)
    // { 
    //     preorder(root, outfile); 
    //     outfile << "print preorder: ";
        
    //     for (int i = 0; i < 20; i++)
    //     {
    //         if (i % 5 == 0)
    //         {
    //             outfile << endl;
    //         }
    //         outfile << printer.top() << " ";
    //         printer.pop(); 
    //     }
    //     outfile << endl;
    //     printer.clear();
    // }
    // void postorder(ofstream &outfile)
    // { 
    //     postorder(root, outfile); 
    //     outfile << "print postorder: ";
        
    //     for (int i = 0; i < 20; i++)
    //     {
    //         if (i % 5 == 0)
    //         {
    //             outfile << endl;
    //         }
    //         outfile << printer.top() << " ";
    //         printer.pop(); 
    //     }
    //     outfile << endl;
    //     printer.clear();
    // }
    // void nodes_count(ofstream &outfile)
    // {
    //     int count = 0;
    //     count = nodes_count(root);
    //     outfile << "Number of nodes: " << count << endl;
    // }
    // void leaf_count(ofstream &outfile)
    // {
    //     int count = 0;
    //     count = leaf_count(root);
    //     outfile << "Number of leaves: " << count << endl;
    // }
    // void data_count(ofstream &outfile)
    // {
    //     int count = 0;
    //     count = data_count(root);
    //     outfile << "Data count is: " << count << endl;
    // }
    // void sum_values(ofstream &outfile)
    // {
    //     double sum = 0;
    //     sum = sum_values(root);
    //     int count = 0;
    //     count = data_count(root);
        
    //     outfile << "The sum is: " << (sum/100) << endl;
    //     outfile << fixed << setprecision(2) << "The average is: " << (sum/count/100) << endl;
    // }
    // int duplicate_count(ofstream &outfile)
    // {
    //     outfile << "The number of duplicates is: " << duplicate_count(root) << endl;
    // }
    // int deepest_value(ofstream &outfile)
    // {
    //     int value = -1;
    //     int level = -1;
    //     int max = 0;
    //     deepest_value(root, level, max, value);
    //     outfile << "The deepest value is: " << value << endl;
    // }
    // int one_child_count(ofstream &outfile)
    // {
    //     int count = 0;
    //     count = one_child_count(root);
    //     outfile << "The number of nodes with one child is: " << count << endl;
    // }
    // int sum_digits(int);
    // void delete_routine()
    // {
    //     delete_routine(root);
    // }
};

void TwoThreeTree::insert(tnode *&root, int n)
{
    
    // if (r == NULL)
    // {
    //     tnode * node = NULL;
    //     node = new_node(n);
    //     r = node;
    // }
    // if (r->v1 < n && r->v2 == 0)
    // {
    //     r->v2 = v1;
    //     r->v1 = n;
    // }
    // if (r->v1 < n && r->v2 != 0)
    // {
    //     tnode * node = NULL;
    //     node = new_node(n);
        
    // }
}


void insert (tnode*& root, Key K, Elem it, Key& retkey, Elem& retval, tnode*& retptr) 
{
    Elem myretv; // Local copies: return record
    Key myretk; // return key
    tnode * myretp = NULL; // return subkey
    if (root == NULL) { // Empty tree: make new node
        root = new TTNode<Key,Elem>();
        root->lval = it; root->lkey = K;
    }
    else if (root->isLeaf())
    {
        // At leaf node: insert here
        if (root->rkey == EMPTYKEY) 
        { // Only one node stored
            if (K > root->lkey) 
            { // Put it to right
                root->rval = it;
                root->rkey = K;
            }
            else 
            { // Put it to left
                root->rval = root->lval;
                root->rkey = root->lkey;
                root->lval = it;
                root->lkey = K;
            }
        }
    }
    else
    {
        splitnode(root, K, it, NULL, retkey, retval, retptr);
    }
    else if 
    {
        (K < root->lkey) // Process internal node
        inserthelp(root->left, K, it, myretk, myretv, myretp);
    }
    else if ((root->rkey == EMPTYKEY) || (K < root->rkey))
    {
        inserthelp(root->center, K, it, myretk, myretv, myretp);
    }
    else
    {
        inserthelp(root->right, K, it, myretk, myretv, myretp);
    }
    if (myretp != NULL) // Child split: receive promoted value
    {
        if (root->rkey != EMPTYKEY) // Full: split
        {
            splitnode(root, myretk, myretv, myretp,
            retkey, retval, retptr);
        }
    else 
    { // Not full: add to this node
        if (myretk < root->lkey) 
        { // Put on left side
            root->rval = root->lval;
            root->rkey = root->lkey;
            root->lval = myretv;
            root->lkey = myretk;
            Figure 10.13 The 2-3 tree insert routine.
            382 Chap. 10 Indexing
            root->right = root->center;
            root->center = myretp;
        }
        else 
        { // Put on right side
            root->rval = myretv;
            root->rkey = myretk;
            root->right = myretp;
        }
    }
}

template <typename Key, typename Elem>
void TTTree<Key,Elem>::splitnode(TTNode<Key,Elem>* root,
Key K, Elem it, TTNode<Key,Elem>*inptr,
Key& retkey, Elem& retval,
TTNode<Key,Elem>*& retptr) {
retptr = new TTNode<Key,Elem>(); // Node created by split
if (K < root->lkey) { // Add at left
retval = root->lval;
retkey = root->lkey;
root->lval = it;
retptr->lval = root->rval;
retptr->lkey = root->rkey;
retptr->left = root->center;
retptr->center = root->right;
root->center = inptr;
}
else if (K < root->rkey) { // Add at center
retval = it;
retkey = K;
retptr->lval = root->rval;
retptr->lkey = root->rkey;
retptr->left = inptr;
retptr->center = root->right;
}
else { // Add at right
retval = root->rval;
retkey = root->rkey;
retptr->lval = it;
retptr->lkey = K;
retptr->left = root->right;
retptr->center = inptr;
}
root->rkey = EMPTYKEY;
}

int main()
{
	outfile.open("outfile-btree.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!";
		return 1;
	}
	
	infile.open("TreeNbrsV2.txt");
	if (!infile)
	{
	    outfile << "The infile did not open!";
	    return 1;
	}
	return 1;
}

