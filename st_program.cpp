// st_program.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ofstream outfile;

class Stat
{
public:
	Stat();
	~Stat();
	Stat(Stat &C);
	void add(double val);
	double get_length();
	double get_sum();
	double get_average();
	double get_largest();
	double get_smallest();
	double get_count();
	bool get_isset();
	void set_length(double);
	void set_sum(double);
	void set_average(double);
	void set_isset(bool);
	void set_smallest(double);
	void set_largest(double);
	void init_stat();
	friend std::ostream &operator<<(std::ostream &out, Stat &S);
	bool operator==(Stat &A);
	bool operator!=(Stat &A);
private:
	double sum, smallest, largest, count;
	double average;
	bool isset;
};

Stat operator+(Stat &A, Stat &B);


Stat::Stat()
{
	isset = false;
	sum = 0;
	average = 0;
	count = 0;
}

Stat::~Stat()
{

}
Stat::Stat(Stat &C)
{
	isset = C.get_isset();
	sum = C.get_sum();
	average = C.get_average();
	count = C.get_count();
	smallest = C.get_smallest();
	largest = C.get_largest();
}
void Stat::add(double val)
{
	sum += val;
	if (isset == false)
	{
		isset = true;
		smallest = val;
		largest = val;
	}
	count = count + 1;

	if (smallest > val)
	{
		smallest = val;
	}
	if (largest < val)
	{
		largest = val;
	}
	average = sum / count;
}

double Stat::get_length()
{
	return count;
}

double Stat::get_sum()
{
	return sum;
}

double Stat::get_average()
{
	return average;
}

double Stat::get_largest()
{
	return largest;
}

double Stat::get_smallest()
{
	return smallest;
}

double Stat::get_count()
{
	return count;
}

bool Stat::get_isset()
{
	return isset;
}

void Stat::set_length(double l)
{
	count = l;
}

void Stat::set_sum(double s)
{
	sum = s;
}

void Stat::set_average(double a)
{
	average = a;
}

void Stat::set_isset(bool i)
{
	isset = i;
}

void Stat::set_smallest(double s)
{
	smallest = s;
}

void Stat::set_largest(double l)
{
	largest = l;
}

void Stat::init_stat()
{
	sum = 0;
	count = 0;
	average = 0;
	isset = false;
}

bool Stat::operator==(Stat & A)
{
	return
		(sum == A.get_sum());
}

bool Stat::operator!=(Stat & A)
{
	return !(sum == A.get_sum());
}

std::ostream & operator<<(std::ostream &out, Stat &S)
{
	out << "sum " << S.get_sum() << "\n";
	out << "length " << S.get_length() << "\n";
	out << "average " << S.get_average() << "\n";
	if (S.get_isset() == true)
	{
		out << "largest " << S.get_largest() << "\n";
		out << "smallest " << S.get_smallest() << "\n";
	}
	else
	{
		out << "Largest and smallest have not yet been assigned" << "\n";
	}
	out << "\n";
	return out;
}

Stat operator+(Stat &A, Stat &B)
{
	Stat statistician3;
	statistician3.add(A.get_sum());
	statistician3.add(B.get_sum());
	statistician3.set_length(A.get_length() + B.get_length());
	return statistician3;
}

int main()
{

	outfile.open("outfile.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!";
		return 1;
	}

	Stat statistician1;
	statistician1.add(5.5);
	statistician1.add(6.6);
	statistician1.add(9.8);
	statistician1.add(-4.4);
	statistician1.add(-3.5);
	statistician1.add(8.7);
	statistician1.add(9.1);

	outfile << "Statistician 1" << endl;
	outfile << "sum ";
	outfile << statistician1.get_sum() << endl;
	outfile << "length ";
	outfile << setprecision(0) << statistician1.get_length() << endl;
	outfile << "average ";
	outfile << fixed << internal << setprecision(2) << statistician1.get_average() << endl;
	outfile << "largest ";
	outfile << setprecision(1) << statistician1.get_largest() << endl;
	outfile << "smallest ";
	outfile <<  statistician1.get_smallest() << endl;
	outfile << "\n";

	statistician1.add(7.2);
	statistician1.add(-3.3);
	statistician1.add(-9.5);
	statistician1.add(7.2);
	statistician1.add(8.5);

	outfile << "Statistician 1 Revised" << endl;
	outfile << statistician1;
	
	Stat statistician2(statistician1);
	
	outfile << "Statistician1" << "\n";
	outfile << statistician1;
	
	outfile << "Statistician2" << "\n";
	outfile << statistician2;

	outfile << "Adding to Statistician2" << "\n";
	statistician2.add(13);
	statistician2.add(21);
	statistician2.add(71);
	statistician2.add(37);
	statistician2.add(12);
	statistician2.add(35);
	statistician2.add(24);
	statistician2.add(43);
	statistician2.add(24);
	statistician2.add(32);

	outfile << "Statistician 2" << endl;
	outfile << "sum ";
	outfile << statistician2.get_sum() << endl;
	outfile << "length ";
	outfile << setprecision(0) << statistician2.get_length() << endl;
	outfile << "average ";
	outfile << fixed << internal << setprecision(2) << statistician2.get_average() << endl;
	outfile << "\n";

	outfile << "Statistician 1 with << operator" << "\n";
	outfile << statistician1;

	
	outfile << "Statistician 2 with << operator" << "\n";
	outfile << statistician2;

	Stat statistician3;
	statistician3 = statistician1 + statistician2;


	outfile << "Statistician 1 with << operator" << "\n";
	outfile << statistician1;
	outfile << "\n";
	outfile << "Statistician 2 with << operator" << "\n";
	outfile << statistician2;
	outfile << "\n";
	outfile << "Statistician 3 with << operator" << "\n";
	outfile << statistician3;
	

	statistician2.init_stat();

	outfile << "Erased statistician2" << "\n";
	outfile << "Statistician 1 with << operator" << "\n";
	outfile << statistician1;
	outfile << "\n";
	outfile << "Statistician 2 with << operator" << "\n";
	outfile << statistician2;
	outfile << "\n";
	outfile << "Statistician 3 with << operator" << "\n";
	outfile << statistician3;

    return 0;

}

