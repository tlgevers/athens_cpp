// 
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cstdlib>
using namespace std;


const int sz = 11;
float table[sz] = {70, 85, 85, 94, 87, 92, 85, 83, 85, 87, 73};

void table_print(float *, float);
void table_add1(float *, float);
void table_fill(float *, float, float);
void table_print_rev(float *, float);
void table_copy(float *, float *, float);
float table_min(float *, float);
float table_max(float *, float);
float table_sum(float *, float);
float table_avg(float *, float);
float * table_contain(float *, float, float);

ofstream outfile;

int main()
{
    	outfile.open("outfile-Table.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!";
		return 1;
	}
    const float Max = 24;
    // float ary[Max];............  replace these two statements with dynamically allocated arrays.
    // float bry[Max];
    
    float *ary = new float[24];
    float *bry = new float[24];
    
    float *p, *s, *tp;
    float avgValue, cnt;

    p = &ary[0];
    s = &bry[0];

    table_fill( p, Max, 10 );
    outfile << endl << "Fill array with 20 " << endl;
    table_print( p, Max );  outfile << endl << endl;


    outfile << endl << "Add 1 to first 10 elements " << endl;
    table_add1( p, 10);
    table_print( p, Max );  outfile << endl << endl;

    tp = s;   // save pointer
    for (int i=1; i<= Max; i++ )
    {
	table_fill( s, 1, i );
	s++;
    }
    outfile << endl << "Fill array with 1 to MAX " << endl;
    s = tp;   // restore pointer
    table_print( s, Max );  outfile << endl << endl;

    outfile << endl << "Print reverse order " << endl;
    table_print_rev( s, Max );  outfile << endl << endl;

    table_fill( p, Max, 0 );
    outfile << endl << "Zero out array " << endl;
    table_print( p, Max );  outfile << endl << endl;

    s = p;        // What's happening here?
    for (int i=Max; i>=0; i--)
    {
	table_add1( p, i );
	p++;
    }
    p = s;  //restore p and s
    s = tp;
    outfile << endl << "Fill array with ???? " << endl;
    table_print( p, Max );  outfile << endl << endl;

    outfile << endl << "Print reverse order " << endl;
    table_print_rev( p, Max );  outfile << endl << endl;

    outfile << endl << "Copy p to s and print p and s" << endl;
    table_copy( s, p, Max);
    table_print( p, Max );  outfile << endl << endl;
    table_print( s, Max );  outfile << endl << endl;

    for (int i=0; i<Max/2+1; i++)
    {
	    s = p+10+i;
	    table_fill( s, 1, i*3 );
	    s = p+10-i;
	    table_fill( s, 1, i*6 );
    }

    p = s;
    s = tp;
    outfile << endl << "Fill array with <-> " << endl;
    table_print( s, Max );  outfile << endl << endl;

    outfile << endl << "Min for previous table " << table_min( s, 15 );
    outfile << endl << "Max for previous table " << table_max( s+10, 9);
    outfile << endl << "Sum for previous table " << table_sum( s+11, 12);
    outfile << endl << "Average for previous table " << table_avg( s+11, 12);

    avgValue = table_avg( s, Max);
    for ( int i=1; i<=Max; i++)
    {
        if ( table_contain( s, 1, avgValue) )
        {
            cnt++;
        }
        s++;
    };
    outfile << "How many array values are equal to the average?" << endl;
    outfile << "         cnt = " << cnt << endl << endl;

    // ..........  You add code here for the two other tasks I have in the specs
    
    float * gp;
    float * fgp;
    float * ap;
    ap = table;
    gp = table;
    fgp = table;
    
    float av = table_avg(ap, sz);
    float sum;
    float total;
    float value;
    int count_less_av;
    
    
    outfile << "The average is: " << av << endl;
    
    for (int i = 1; i <= sz; i++)
    {
        sum = table_sum(gp, i);
        if (i == 1)
        {
            value = sum;
            total = sum;
            if (value < av)
            {
                count_less_av++;
            }
        }
        else {
            value = sum - total;
            total = sum;
            if (value < av)
            {
                count_less_av++;
            }
        }
    }
    
    outfile << "There are " << count_less_av << " values less than the average in the table." << endl;
    
    float prev_sum = 0;
    float grades_total = 0;
    float sum_grades = 0;
    float v = 0;
    
    for (int i = 1; i <= sz; i++)
    {
        sum_grades = table_sum(fgp, i);
        if (i == 1)
        {
            grades_total = sum_grades;
            prev_sum = sum_grades;
            outfile << "i == 1" << endl;
        }
        else if (i == 5 || i == 8)
        {
            v = (sum_grades - prev_sum) * 2;
            grades_total = grades_total + v;
            prev_sum = sum_grades;
            outfile << "i == 5 & 8" << endl;
        }
        else if (i == 11)
        {
            v = (sum_grades - prev_sum) * 3;
            grades_total = grades_total + v;
            prev_sum = sum_grades;
            outfile << "i == 11" << endl;
        }
        else {
            v = sum_grades - prev_sum;
            grades_total = grades_total + v;
            prev_sum = sum_grades;
        }
    }
    outfile << table_sum(table, sz) << "\n";
    outfile << "The grades total is: " << grades_total << endl;
    outfile << "The students overall average is " << grades_total /15 << endl;
    
    // system("pause");    // code for VS only.  Delete for Codeblocks
    return 0;
}

// int main()
// {
//     float *p = new float[24];
//     table_copy(p, table, 24);
//     outfile << "p\n";
//     table_print(p, sz);
//     float min;
//     min = table_min(p, 11);
//     outfile << "min: " << min << "\n";
//     table_print_rev(table, sz);
//     table_add1(table, sz);
//     table_print(table, sz);
//     table_fill(table, sz, 50);
//     table_print(table, sz);
//     float sum;
//     sum =table_sum(p, 11);
//     outfile << sum << "\n"; 
//     table_print(p, 11);
//     float avg;
//     avg = table_avg(p, 11);
//     outfile << "avg: " << avg << "\n";
    
//     float * check;
//     check = table_contain(p, 11, 85);
//     outfile << *check << endl;
//     return 0;
// }


void table_print(float *p, float sz)
{
    int count = 0;
    while(count != sz)
    {
        outfile << *p << " ";
        count++;
        p++;
    }
    outfile << "\n";
}


void table_add1(float *p, float sz)
{
    int count = 0;
    while(count != sz)
    {
        *p = *p + 1;
        count++;
        p++;
    }
}


void table_fill(float *p, float sz, float v)
{
    int count = 0;
    while(count != sz)
    {
        *p = v;
        count++;
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
       outfile << *p << " ";
       p--;
   }
   outfile << "\n";
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


float table_sum(float *p, float sz)
{
    float sum = 0;
    int count = 0;
    
    while(count != sz)
    {
        sum = sum + *p;
        count++;
        p++;
    }
    
    return sum;
}


float table_avg(float *p, float sz)
{
    float sum = 0;
    float average = 0;
    sum = table_sum(p, sz);
    
    return (average = sum / sz);
    
}


float * table_contain(float *p, float sz, float v)
{
    int count = 0;
    while (count != sz)
    {
         if (*p == v)
         {
             return p;
         }
         count++;
         p++;
    }
    return NULL;
}