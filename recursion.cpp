// Trevor Gevers - Recursion Routines

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int array[10] = {1,2,3,4,5,6,7,8,9,10};
int arrFill[20];
int arrF11[11];
int hail_size = 0;
ofstream outfile;

int f(int n);
int F(char, char);
void g(char, int);
void printNum(int);
unsigned t(double, unsigned);
unsigned a1(unsigned);
unsigned a2(unsigned);
unsigned a3(int);
int numDigits(int);
void revDigits(int);
void reverseArray(int *, int, int);
int sumArray(int *, int);
int location(int *, int, int, int);
int GCD(int, int);
void hailstones(int);
void fillArray1(int *, int, int);
void fillArray2(int *, int, int);
void fillArray3(int *, int, int, int);
void printArray(int *);
void running(double, double);


int main()
{
    outfile.open("outfile-Recursion.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!" << endl;
	}
	
    int * ArrayType = NULL;
    int * printBefore = NULL;
    int * printAfter = NULL;
    int * fill = NULL;
    
    ArrayType = array;
    printBefore = array;
    printAfter = array;
    fill = arrFill;
    
    int number_of_digits = numDigits(19999786);
    outfile << "Return number of digits: " << number_of_digits << endl;
    
    outfile << "Print before reverse" << endl;
    printArray(ArrayType); 
    
    outfile << "Print after reverse" << endl;
    printArray(ArrayType); 
    
    reverseArray(ArrayType, 0, 8);
    int sum;
    sum = sumArray(ArrayType, 10);
    outfile << "Sum is: " << sum << endl;
    
    int pos;
    pos = location(ArrayType, 0, 10, 3);
    outfile << "position: " << pos << endl;
    
    int gcd = GCD(4, 6);
    outfile << "Greatest Common Divisor: " << gcd << endl;
    
    hailstones(1859);
    outfile << "Hailstone size is: " << hail_size << endl;
    
    hail_size = 0;
    hailstones(119570);
    outfile << "Hailstone size is: " << hail_size << endl;
    
    outfile << "Fill array with 1 - 20 no.4" << endl;
    fillArray1(arrFill, 1, 20);
    printArray(arrFill);
    
    outfile << "Fill array with 20 - 1 no.5" << endl;
    fillArray2(arrFill, 20, 20);
    printArray(arrFill);
    
    outfile << "Fill array with 11 values no.6" << endl;
    fillArray3(arrF11, 1, 1, 1);
    for (int i = 0; i < 11; i++)
    {
        outfile << arrF11[i] << endl;
    }
    
    cout << "running: " << endl;
    running(0, 0);
    
    return 0;
}


// q.21 from handout exercises
int numDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 1 + numDigits(n / 10);
}


// q.23 from handout exercises
void revDigits(int n)
{
    if (n == 0)
    {
        return;
    }
    outfile << n % 10 << endl;
    revDigits(n / 10);
}


// q.27 from handout exercises
void reverseArray(int *ptr, int first, int last)
{
    if (first > last)
    {
        return;
    }
    
    int temp = ptr[first];
    ptr[first] = ptr[last];
    ptr[last] = temp;
    
    reverseArray(ptr, first + 1, last - 1);
}


// q.28 from handout exercises
int sumArray(int *ptr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    return *ptr + sumArray(++ptr, n-1);
}


// q.29 from handout exercises
int location(int *ptr, int first, int last, int elm)
{
    if (first > last)
    {
        return 0;
    }
    if (ptr[first] == elm)
    {
        return first;
    }
    if (ptr[last] == elm)
    {
        return last;
    }
    return location(ptr, first + 1, last - 1, elm); 
}


// q.33 from handout exercise
int GCD(int a, int b)
{
    if (a < b)
    {
        return (GCD(b, a));
    }
    if (a % b == 0)
    {
        return (b);
    }
    return (GCD(b, a % b));
}


// Recursion programs main handout, hailstones
void hailstones(int n)
{
    if (n == 1)
    {
        return;
    }
    if ((n % 2) == 0)
    {
       hail_size++;
       hailstones(n / 2);
    }
    if ((n % 2) != 0)
    {
        hail_size++;
        hailstones(((n * 3) + 1));
    }
}


// Recursion programs main handout, no. 4
void fillArray1(int * ptr, int v, int size)
{
    if (v == 21)
    {
        return;
    }
    *ptr = v;
    return fillArray1(++ptr, ++v, --size);
}


// Recursion programs main handout, no. 5
void fillArray2(int * ptr, int v, int size)
{
    if (v == 0)
    {
        return;
    }
    *ptr = v;
    return fillArray2(++ptr, --v, --size);
}


// Recursion programs main handout, no. 6
void fillArray3(int * ptr, int v, int left, int right)
{
    int position = 5;
    
    if (v == 12)
    {
        return;
    }
    if (v == 1)
    {
        ptr[position] = v;
        return fillArray3(ptr, ++v, left, right);
    }
    if (v % 2 == 0)
    {
        ptr[position + right] = v;
        return fillArray3(ptr, ++v, left, ++right);
    }
    if (v % 2 != 0 && v != 1)
    {
        ptr[position - left] = v;
        return fillArray3(ptr, ++v, ++left, right);
    }
}


void printArray(int * ptr)
{
    int count = 0;
    while(*ptr && count != 20)
    {
        outfile << *ptr << endl;
        ptr++;
        count++;
    }
}

void running(double mins, double miles)
{
    if (mins == 55)
    {
        return;
    }
    if (mins > 5)
    {
        miles = miles - 0.05;
    }
    cout << "mins: " << mins << " miles: " << miles << endl;
    running(5 + mins, 0.67 + miles);
}