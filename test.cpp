#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

struct test
{
   int index;
   string data;
};

void print(test);
test send(test &);

int main()
{
    test t;
    send(t);
    print(t);
    return 1;
}

void print(test data)
{
    cout << "index " << data.index << " data " << data.data << endl;
}

test send(test &t)
{
    t.index = 1;
    t.data = "yip";
    
    return t;
}
