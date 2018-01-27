// C++ code to demonstrate the working of 
// push_heap() and pop_heap()
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm> // for heap operations
#include<vector>
using namespace std;

ifstream infile;

int main()
{
    infile.open("HeapPriortyNbrs.dat");
    if (!infile)
    {
        cout << "the infile did not open!" << endl;
        return 1;
    }
     
    // Initializing a vector
    vector<string> v1;
    
    string line;
    
    while(infile >> line)
    {
        v1.push_back(line);
    }
    // int arr[5] = {20, 30, 40, 25, 15}; 
    // Converting vector into a heap
    // using make_heap()
     
    // Displaying the maximum element of heap
    // using front()
    cout << "The maximum element of heap is : ";
     
    // using push_back() to enter element
    // in vector
    // v1.push_back(20);
    // v1.push_back(30);
    // v1.push_back(40);
    // v1.push_back(25);
    // v1.push_back(15);
    
    make_heap(v1.begin(), v1.end());
    
    cout << v1.front() << endl;
    
    // v1.push_back("99999");
    
     
    // using push_heap() to reorder elements
    // push_heap(v1.begin(), v1.end());
     
    // Displaying the maximum element of heap
    // using front()
    cout << "The maximum element of heap after push is : ";
    // cout << v1.front() << endl;
     
     // using pop_heap() to delete maximum element
    // pop_heap(v1.begin(), v1.end());
     
    // Displaying the maximum element of heap
    // using front()
    // cout << "The maximum element of heap after pop is : ";
    // cout << v1.front() << endl;
    cout << "The back element is : ";
    
    cout << v1.back() << endl;
    
    
    cout << "print heap" << endl;
    int count = 0;
    
    for (int i = 0; i < v1.size(); i++)
    {
        if (i % 20 == 0)
        {
            cout << endl;
        }
        cout << v1[i] << " ";
    }
    
    return 0;
}