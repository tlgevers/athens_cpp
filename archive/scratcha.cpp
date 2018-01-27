// Hash Program | CS 372 | Trevor Gevers

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;

ifstream infile;
ofstream outfile;

struct info
{
    string key;
    int index;
};

string format(string, bool);
int hash_test(string);
const int CAPACITY = 49;

struct table_row
{
    string key;
    bool used;
    string names;
    string number;
};

template<typename ListType, int CAPACITY>
class HT
{
private:
    ListType table[CAPACITY][5];
    ListType value;
    int collisions;
    int size;

public:
    HT() { initial(); collisions = 0; size = 0; }
    
    info hash_function(string c)
    {
        c = format(c, false);
        
        char * str = new char [c.length() + 1];
        strcpy(str, c.c_str());
        
        char * v = str;
        
        int index = 0;
        int count = 0;
        string key;
        
        while(count != 4)
        {
            if (isalpha(*v) && count < 1)
            {
                string con(1, *v);
                key.append(con);
                int character = (*v - 97) % CAPACITY;
                index = index + (character * character) % CAPACITY;
                count++;
            }
            else if (isalpha(*v))
            {
                string con(1, *v);
                key.append(con);
                int character = (*v - 97);
                index = index + (character * character) % 26;
                count++;
            }
            ++v;
        }
        delete [] str;
        
        info keys;
        keys.key = key;
        keys.index = (index % CAPACITY);
        
        return keys;
    }
    
    void add_entry(table_row entry)
    {
        ++size;
        info index = hash_function(entry.names);
        
        int use_index = available(index.index);
        
        table[use_index][0] = "false";
        table[use_index][1] = index.key;
        table[use_index][2] = entry.names;
        table[use_index][3] = entry.number;
        table[use_index][4] = "false";
    }
    
    int available(int check_index)
    {
        if (table[check_index][0] == "true")
        {
            return check_index;
        }
        else
        {
            ++collisions;
            table[check_index][4] = "true";
            string check = "false";
            int index = check_index;
            
            while(check == "false")
            {
                if (index == CAPACITY - 1)
                {
                    index = 0;
                }
                if (table[index][0] == "true")
                {
                    check = "true";
                }
                else
                {
                    ++index;
                }
            }
            return index;
        }
    }
    
    void initial()
    {
        for (int i = 0; i < CAPACITY; i++)
        {
            table[i][0] = "true";
        }
    }
    
    void find(string f)
    {
        info find_index = hash_function(f);
        
        if (table[find_index.index][1].compare(find_index.key) == 0)
        {
            outfile << "The phone number is: " << table[find_index.index][3] << endl;
        }
        else if (table[find_index.index][4] == "true")
        {
            int index = 0;
            index = find_index.index;
            bool found = false;
            
            while(found == false)
            {
                if (index == CAPACITY - 1)
                {
                    index = 0;
                }
                if (table[index][1].compare(find_index.key) == 0)
                {
                    found = true;    
                }
                else
                {
                    ++index;       
                }
            }
            outfile << "The phone number is: " << table[index][3] << endl;
        }
        else
        {
            outfile << "That name is not in the database." << endl;
        }
    }
    
    int get_collisions()
    {
        return collisions;    
    }
    
    void print_table()
    {
        for (int i = 0; i < CAPACITY; i++)
        {
            if (table[i][0] != "true")
                outfile << table[i][2] << " " << table[i][3] << endl;
        }
        outfile << endl;
    }

};

string format(string c, bool between)
{
    if (between)
    {
        char * str = new char [c.length() + 1];
        strcpy(str, c.c_str());
    
        char * token;
        token = strtok(str, " (;");
        
        string no_trailing_spaces;
        
        while (token != NULL)
        {
            no_trailing_spaces = no_trailing_spaces + token;
            token = strtok(NULL, " ");
            if (token != NULL)
            {
                no_trailing_spaces = no_trailing_spaces + " ";
            }
        }
        return no_trailing_spaces;
    }
    else
    {
        const char *ptr = c.c_str();
        char * str = new char [c.length() + 1];
        strcpy(str, c.c_str());
    
        char * token;
        token = strtok(str, " (;");
        
        string no_trailing_spaces;
        
        while (token != NULL)
        {
            no_trailing_spaces = no_trailing_spaces + token;
            token = strtok(NULL, " ");
            if (token != NULL)
            {
                no_trailing_spaces = no_trailing_spaces;
            }
        }
        return no_trailing_spaces;
    }
    
}


int main()
{
    
    HT<string, CAPACITY> ht;
    
    infile.open("HashNamesAndPhone.txt");
    if (!infile)
    {
        outfile << "The infile did not open!\n";
    }
    
    outfile.open("hash_table_output.txt");
    if (!outfile)
    {
        cout << "The outfile did not open!\n";
    }
    
    char one;
    bool check_digit = false;
    string names;
    string number;
    bool alternate = false;
    
    table_row entry;
    
    while(infile.get(one))
    {
        if (isalpha(one) || isspace(one) || one == '.')
        {   
            if (isalpha(one) || isspace(one))
            {
                one = (tolower(one));
                string in(1, one);
                names.append(in);
            }
            if ( alternate == true)
            {
                entry.number = number;
                number = "";
                alternate = false;
                ht.add_entry(entry);
                names = "";
            }
        }
        else {
            string in(1, one);
            alternate = true;
            entry.names = names;
            if (names.size() > 0)
            {
                names = format(names, true);
            }
            number.append(in); 
        }
    }
    outfile << "\n";
    outfile << "Print out the final database: " << endl;
    ht.print_table();
    outfile << "There were " << ht.get_collisions() << " collisions total. " << endl;
    outfile << "\n";
    outfile << "Lookup values: " << endl;
    outfile << "Find: Smelly Socks" << endl;
    ht.find("Smelly Socks");
    outfile << "Find: Mighty Mouse" << endl;
    ht.find("mighty mouse");
    outfile << "Find: Hauser" << endl;
    ht.find("hauser");
    outfile << "Find: Big" << endl;
    ht.find("big tow");
    outfile << "Find: mack russell" << endl;
    ht.find("mack russell");
    outfile << "Find: JOSH" << endl;
    ht.find("JOSH");
    return 0;
}