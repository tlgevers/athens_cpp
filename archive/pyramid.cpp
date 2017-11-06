
// recursive pyramid.cpp : Defines the entry point for the console application.
// Trevor Gevers / Data Structures 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;


void printForward(char,int,int);
void printReverse(char);
void writeChar(char*,char);
void buildPyramid(char,int);

ofstream outfile;

void printForward(char c, int begin, int spaces)
{
    if (begin == 0)
    {
        return;
    }
    if (spaces != 0)
    {
        outfile << " ";
        --spaces;
    }
    if (spaces == 0)
    {
        char print = c - begin;
        outfile << (char)print;
        begin = begin - 1;
    }
    printForward(c, begin, spaces);
    
}


void printReverse(char r)
{
    if (r == '@')
    {
        return;
    }
    outfile << r;
    printReverse(--r);
}


void buildPyramid(char c, int begin, int spaces)
{
    if (spaces == 0)
    {
        return;
    }
    printForward(c , begin, spaces); 
    if (begin > 1)
    {
        printReverse(c - 2);
    }
    outfile << endl;
    buildPyramid(++c, ++begin, --spaces);
}


int main()
{
    
	outfile.open("output/outfile-pyramid.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!";
		return 1;
	}
	
	char m;
	outfile << "Please enter a letter between A & M" << endl;
    cin >> m;
    outfile << "You entered the letter " << m << endl;
    outfile << endl;
	char a = '@';
	
	int spaces = m - a;
    buildPyramid(m - spaces + 2, 1, spaces);
    
    outfile.close();
    
    return 0;
}