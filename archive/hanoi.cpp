
// Hanoi Program
// Trevor Gevers / Data Structures 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;

void move(int, char, char, char);

ofstream outfile;


void move(int n, char source, char destination, char spare)
{
    if (n == 1)
    {
        outfile << "Move the top disk from " << source << " to " << destination << endl;
    }
    else
    {
        move(n-1, source, spare, destination);
        move(1, source, destination, spare);
        move(n-1, spare, destination, source);
    }
}

int main()
{
    
	outfile.open("output/outfile-hanoi.out");
	if (!cout)
	{
		cout << "The outfile did not open!";
		return 1;
	}
	
	const char PEG1 = 'A', PEG2 = 'B', PEG3 = 'C';
	
	cout << "This program solves the Hanoi Towers Puzzle.\n\n";
	            
	cout << "Enter the number of disks: ";
	int numDisks;
	cin >> numDisks;
	cout << endl;
	
	outfile << "Solving has started:\n";
	
	move(numDisks, PEG1, PEG2, PEG3);
	
	
    
    return 0;
}