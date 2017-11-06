
        {
            dollar = !dollar;
            ++enter_data;
            if (enter_data == 2)
            {
                insert_node(func);
                enter_data = 0;
            }
        }
        
        // if (row.data == "*")
        // {
        //     star = !star;
        //     args = !args;
        // }
        
        // if (star)
        // {
        //     variable = variable + row.data + " ";
        //     ++cs;
        //     if (cs == 2)
        //     {
        //         func.insertNode(row.line, variable);
        //         cs = 0;
        //     }
        // }
        
        // if (args)
        // {
        //     arguments = arguments + row.data + " ";
        //     ++ca;
        //     if (ca == 2)
        //     {
        //         func.insertNode(row.line, arguments);
        //         ca = 0;
        //     }
        // }
        
        if (dollar)
        {
            
            // what_line = row.line;
            // int ready = row.data.find("$");
            // int check_func = row.data.find("~");
            // int arg_end = row.data.find("*");
        
        
            // outfile << "display func: " << endl;
            // func.insertNode(999, "*end*");
            // func.displayList();
            // insert_node(func);
            // outfile << "end func display." << endl;
            function = function + row.data + " ";
            ++cd;
            if (cd == 2)
            {
                func.insertNode(row.line, function);
                cd = 0;
                args = !args;
                dollar = !dollar;
            }
        }
        
        
        // // if (check_func > -1)
        // // {
        // //     cout << "begin func" << endl; 
        // //     int line = row.line;
        // //     int count = 0;
        // //     while (row.data != "*" && row.data != "*end*")
        // //     {
        // //         string add = row.data;
        // //         add =  add + " " + row.data;
        // //         cout << line << " " << add << endl;
        // //         int e = add.find("~");
        // //         if (e > -1)
        // //         {
        // //             add.erase(0,1);
        // //         }
        // //         func.insertNode(line, add);
        // //     }
            
        // //     cout << "end func" << endl; 
        // //     func.insertNode(line, "arg");
        // //     is_func = false;
        // // }
        // // else if (ready == -1)
        // // {
        // //     int line = row.line;
        // //     string add = row.data;
        // //     add = add + " " + row.data;
        // //     string check = check_line(add);
        // //     if (check == "var")
        // //     {
        // //         if (what_line == row.line)
        // //         {
        // //             func.insertNode(line, add);
        // //         }
        // //     }
        // // }