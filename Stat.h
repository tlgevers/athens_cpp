#pragma once
#ifndef STAT_H
#define	STAT_H
#include <ostream>

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


#endif // !STAT_H