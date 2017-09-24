// LinkList.cpp : Defines the entry point for the console application.
//

#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>
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
public:
	LL()
	{
		head = NULL;
	}

	ListNode * newNode(int, string);
	void insertNode(int, string);
	void deleteNode(int);
	void displayList() const;
	ListNode * searchGrade(int);
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

		while (ptr != NULL && ptr->grade < grade)
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

	while (ptr)
	{
		cout << "Grade: " << ptr->grade << " Student: " << ptr->name << endl;
		count++;
		ptr = ptr->link;
	}
	cout << " count is: " << count << endl;
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

int main()
{
	infile.open("LinkLnamesAndGrades.txt");
	if (!infile)
	{
		cout << "The infile did not open" << endl;
	}

	outfile.open("outfile-LinkList.out");
	if (!outfile)
	{
		cout << "The outfile did not open!" << endl;
	}
	LL lk;
//	lk.insertNode(1);
//	lk.insertNode(5, "Trevor");
//	lk.insertNode(2, "George");
//	lk.insertNode(9, "Kramer");
//	lk.displayList();
//	cout << "after delete" << "\n";
//	lk.deleteNode(1);

//	lk.displayList();
	char cstr[20];
	string read = "";
	int grade = 0;
	int count = 0;
	int once = 0;
	int check = 0;
	infile >> grade;
	while (infile >> read >> grade)
	{
		lk.insertNode(grade, read);
		check++;
	}
	cout << "check is: " << check << endl;
	lk.displayList();
	//lk.deleteNode(197);
	cout << "after delete: " << "\n";
	lk.displayList();
	ListNode * temp;
	temp = lk.searchGrade(291);
	cout << temp->grade << " test" << endl;

    return 0;
}

