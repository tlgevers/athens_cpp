#include "Stat.h"


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
