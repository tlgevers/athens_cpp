// 
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cstdlib>
using namespace std;


const int sz = 15;
float table[sz] = {70, 85, 85, 94, 87, 92, 85, 83, 85, 87, 73};

void table_print(float *, float);
void table_add1(float *, float);
void table_fill(float *, float, float);
void table_print_rev(float *, float);
void table_copy(float *, float *, float);
float table_min(float *, float);
float table_max(float *, float);


int main()
{
    float *p = new float[24];
    table_copy(p, table, 24);
    cout << "p\n";
    table_print(p, sz);
    float min;
    min = table_min(p, 11);
    cout << "min: " << min << "\n";
    table_print_rev(table, sz);
    table_add1(table, sz);
    table_print(table, sz);
    table_fill(table, sz, 50);
    table_print(table, sz);
    return 0;
}


void table_print(float *p, float sz)
{
    while(*p)
    {
        cout << *p << " ";
        p++;
    }
    cout << "\n";
}


void table_add1(float *p, float sz)
{
    while(*p)
    {
        *p = *p + 1;
        p++;
    }
}


void table_fill(float *p, float sz, float v)
{
    while(*p)
    {
        *p = v;
        p++;
    }
    
}


void table_print_rev(float *p, float sz)
{
   int count = 0;
   while(*p != 0)
   {
       p++;
   }
   p--;
   while(*p)
   {
       cout << *p << " ";
       p--;
   }
   cout << "\n";
}


void table_copy(float *r, float *s, float sz)
{
    int count = 0;
    while(count != (sz - 1))
    {
        *r = *s;
        count++;
        r++;
        s++;
    }
}


float table_min(float *p, float sz)
{
    int count = 0;
    float min = *p;
    
    while(count != sz)
    {
        if (*p < min)
        {
            min = *p;
        }
        count++;
        p++;
    }
    return min;
}


float table_max(float *p, float sz)
{
    int count = 0;
    float max = *p;
    
    while(count != sz)
    {
        if (*p > max)
        {
            max = *p;
        }
        count++;
        p++;
    }
    return max;
}