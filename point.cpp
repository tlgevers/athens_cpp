// point.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

ofstream outfile;

// class point BEGIN
class point
{
public:
    point(double, double);
    // getters
    double get_x();
    double get_y();
    
    // methods
    void shift(double, double);
    void rotate90();   
    bool operator==(point &A); 
    bool operator!=(point &A);
    void operator-(point &A);
    bool operator>(point &A);
    bool operator<(point &A);
    bool operator>=(point &A);
     
	friend std::ostream &operator<<(std::ostream &out, point &S);
private:
    double x;
    double y;
};
// class point END

// non member function BEGIN
point operator+(point &A, point&B);
// non member function END

// methods class point BEGIN
point::point(double initial_x=0, double initial_y=0)
{
    x = initial_x;
    y = initial_y;
}


double point::get_x()
{
    return x;
}


double point::get_y()
{
    return y;
}


void point::shift(double x_amount, double y_amount)
{
    x += x_amount;
    y += y_amount;
}


void point::rotate90()
{
    double new_x;
    double new_y;
    
    new_x = y;
    new_y = -x;
    
    x = new_x;
    y = new_y;
}


bool point::operator==(point &A)
{
    return
        (A.get_x() == x)
        &&
        (A.get_y() == y);
}


bool point::operator!=(point &A)
{
    point B(this->get_x(), this->get_y());
    return !(B == A);
}



void point::operator-(point &A)
{
    x = x - A.get_x();
    y = y - A.get_y();
}


bool point::operator>(point &A)
{
   double x = this->x;
   double y = this->y;
   
   double dist1;
   double dist2;
   
   dist1 = sqrt(pow(x,2) + pow(y,2));
   dist2 = sqrt(pow(A.get_x(),2) + pow(A.get_y(),2));
   
   return (dist1 > dist2);
}


bool point::operator<(point &A)
{
   double x = this->x;
   double y = this->y;
   
   double dist1;
   double dist2;
   
   dist1 = sqrt(pow(x,2) + pow(y,2));
   dist2 = sqrt(pow(A.get_x(),2) + pow(A.get_y(),2));
   
   return (dist1 < dist2);
}


bool point::operator>=(point &A)
{
   double x = this->x;
   double y = this->y;
   
   double dist1;
   double dist2;
   
   dist1 = sqrt(pow(x,2) + pow(y,2));
   dist2 = sqrt(pow(A.get_x(),2) + pow(A.get_y(),2));
   
   return (dist1 >= dist2);
}


ostream & operator<<(ostream &out, point &A)
{
   out << "(" << A.get_x() << "," << A.get_y() << ")" << "\n";
   out << "\n";
   return out;
}
// methods class point END


// non member functions BEGIN
point operator+(point &A, point&B)
{
    double x,y;
    x = A.get_x() + B.get_x();
    y = A.get_y() + B.get_y();
   
    point sum_point(x, y); 
    return sum_point;
}
// non member functions END


// main program BEGIN
int main()
{
	outfile.open("outfile.out");
	if (!outfile)
	{
		outfile << "The outfile did not open!";
		return 1;
	}
    
    
    point point1(1,1);
    point point2(2,2);
    point point3(3,6);
    point point4(6,9);
    point point5(1,1);
    point point6(10,10); 
    point point8(1,1); 
    
    outfile << "Test: adding two points\n";
    outfile << "Point 1 " << point1 << "";
    outfile << "Point 2 " << point2 << ""; 
    outfile << "add two points" << "\n";
    point point7;
    point7 = point1 + point2;
    outfile << "New point after adding: " << point7 << ""; 
    
    
    outfile << "Test: subracting two points\n";
    outfile << "Point 1 " << point1 << "";
    outfile << "Point 2 " << point2 << ""; 
    
    
    outfile << "Point 1 - Point 2\n";
    point1 - point2;
    outfile << "Point 1 " << point1 << "";
    
    
    outfile << "Test: Point further than the other from the origin(0,0): \n";
    outfile << "Point 4 " << point4 << "";
    outfile << "Point 3 " << point3 << "";
    outfile << "Result: " << boolalpha << (point4 > point3) << "\n";
    outfile << "\n"; 
    
    
    outfile << "Test: Point further than the other from the origin(0,0): \n";
    outfile << "Point 3 " << point3 << "";
    outfile << "Point 4 " << point4 << "";
    outfile << "Result: " << boolalpha << (point3 > point4) << "\n";
    outfile << "\n"; 
        
        
    outfile << "Test: Point closer than the other from the origin(0,0): \n";
    outfile << "Point 3 " << point3 << "";
    outfile << "Point 4 " << point4 << "";
    outfile << "Result: " << boolalpha << (point3 < point4) << "\n";
    outfile << "\n"; 
    
    
    outfile << "Test: Point closer than the other from the origin(0,0): \n";
    outfile << "Point 4 " << point4 << "";
    outfile << "Point 3 " << point3 << "";
    outfile << "Result: " << boolalpha << (point4 < point3) << "\n";
    outfile << "\n"; 
    
    
    outfile << "Test: Point Less Than or Equal to the origin(0,0): \n";
    outfile << "Point 8 " << point8 << "";
    outfile << "Point 5 " << point5 << "";
    outfile << "Result: " << boolalpha << (point8 >= point5) << "\n";
    outfile << "\n"; 
    
    
    outfile << "Test: Point Less Than or Equal to the origin(0,0): \n";
    outfile << "Point 6 " << point6 << "";
    outfile << "Point 5 " << point5 << "";
    outfile << "Result: " << boolalpha << (point6 >= point5) << "\n";
    outfile << "\n"; 
    
   
    outfile << "Test: Point equal to another: \n";
    outfile << "Point 8 " << point8 << "";
    outfile << "Point 5 " << point5 << "";
    outfile << "Result: " << boolalpha << (point8 == point5) << "\n";
    outfile << "\n"; 
    
    outfile.close();
    return 0;
}
// main program END