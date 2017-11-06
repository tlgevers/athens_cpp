#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

// struct test
// {
//   int index;
//   string data;
// };

// void print(test);
// test send(test &);

struct node
{
    int value;
    node * link;
};

class LList
{
private:
    node * head;
public:
    LList()
    {
        head = NULL;
    }
    void insert(int v)
    {
        
    	node *Node;
        Node->value = v;
        Node->link = NULL;
        
    	node *ptr;
    	node *prev = NULL;
    
    	if (head == NULL)
    	{
    		head = Node;
    	}
    	else
    	{
    		ptr = head;
    		prev = NULL;
    
    		while (ptr != NULL && ptr->value > v)
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

};

int main()
{
    
    LList ll;
    ll.insert(1);
    
    return 0;
}

// void print(test data)
// {
//     cout << "index " << data.index << " data " << data.data << endl;
// }

// test send(test &t)
// {
//     t.index = 1;
//     t.data = "yip";
    
//     return t;
// }
