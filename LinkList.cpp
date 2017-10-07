// LinkList.cpp : Defines the entry point for the console application.
//

#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ofstream outfile;
ifstream infile;

struct ListNode
{
	int grade;
	string name;
	struct ListNode *link;
};

class LL
{
private:
	ListNode *head;
	void printReverse(ListNode *, ofstream &);
public:
	LL()
	{
		head = NULL;
	}

	ListNode * newNode(int, string);
	void insertNode(int, string);
	void deleteNode(int);
	void displayList() const;
	bool check_average();
	ListNode * searchGrade(int);
	void printReverse(ofstream &outfile)
	{
		outfile << "print reverse of link list " << endl;
		printReverse(head, outfile);
	}
};

ListNode * LL::newNode(int g, string n)
{
	ListNode *Node;

	Node = new ListNode;
	Node->grade = g;
	Node->name = n;
	Node->link = NULL;

	return Node;
}

void LL::insertNode(int grade, string name = "")
{
	ListNode *Node = newNode(grade, name);
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

		while (ptr != NULL && ptr->grade > grade)
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

void LL::deleteNode(int grade)
{
	ListNode *ptr;
	ListNode *prev;

	prev = head;

	if (!head)
	{
		return;
	}
	if (head->grade == grade)
	{
		ptr = head->link;
		delete head;
		head = ptr;
	}
	else
	{
		ptr = head;

		while (ptr != NULL && ptr->grade != grade)
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
	int count = 0;

	while (ptr != NULL)
	{
		outfile << "Grade: " << ptr->grade << " Student: " << ptr->name << endl;
		count++;
		ptr = ptr->link;
	}
}


ListNode * LL::searchGrade(int g)
{
	ListNode * ptr;
	ptr = head;

	while (ptr != NULL)
	{
		if (ptr->grade == g)
		{
			return ptr;
		}
		ptr = ptr->link;
	}
	return NULL;
}

bool LL::check_average()
{
	ListNode * ptr;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->grade >= 270)
		{
			deleteNode(ptr->grade);
		}
		ptr = ptr->link;
	}
}


void LL::printReverse(ListNode * ptr, ofstream &outfile)
{
	if (ptr)
	{
		printReverse(ptr->link, outfile);
		outfile << ptr->grade << endl;
	}
}

int main()
{
	infile.open("LinkLnamesAndGrades.txt");
	if (!infile)
	{
		outfile << "The infile did not open" << endl;
	}

	outfile.open("outfile-LinkList.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!" << endl;
	}
	LL lk;
	
	string read = "";
	int grade = 0;
	int once = 0;
	int check = 0;
	infile >> grade;
	
	while (infile >> read >> grade)
	{
		lk.insertNode(grade, read);
		check++;
	}
	outfile << "Before deleting A averages:\n";
	lk.displayList();
	
	lk.printReverse(outfile);
	
	lk.check_average();
	outfile << "after deleting A students: " << "\n";
	lk.displayList();
	ListNode * temp;
	temp = lk.searchGrade(291);
	
	infile.close();
	outfile.close();
    return 0;
}

