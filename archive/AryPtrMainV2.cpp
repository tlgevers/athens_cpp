int main()
{
    const int Max = 24;
    int ary[Max];............  replace these two statements with dynamically allocated arrays.
    int bry[Max];
    int *p, *s, *tp;
    int avgValue, cnt;

    p = &ary[0];............   change &ary[0] to above used stements.
    s = &bry[0];............   change &bry[0] to above used stements.

    table_fill( p, Max, 10 );
    cout << endl << "Fill array with 20 " << endl;
    table_print( p, Max );  cout << endl << endl;


    cout << endl << "Add 1 to first 10 elements " << endl;
    table_add1( p, 10);
    table_print( p, Max );  cout << endl << endl;

    tp = s;   // save pointer
    for (int i=1; i<= Max; i++ )
    {
	table_fill( s, 1, i );
	s++;
    }
    cout << endl << "Fill array with 1 to MAX " << endl;
    s = tp;   // restore pointer
    table_print( s, Max );  cout << endl << endl;

    cout << endl << "Print reverse order " << endl;
    table_print_rev( s, Max );  cout << endl << endl;

    table_fill( p, Max, 0 );
    cout << endl << "Zero out array " << endl;
    table_print( p, Max );  cout << endl << endl;

    s = p;        // What's happening here?
    for (int i=Max; i>=0; i--)
    {
	table_add1( p, i );
	p++;
    }
    p = s;  //restore p and s
    s = tp;
    cout << endl << "Fill array with ???? " << endl;
    table_print( p, Max );  cout << endl << endl;

    cout << endl << "Print reverse order " << endl;
    table_print_rev( p, Max );  cout << endl << endl;

    cout << endl << "Copy p to s and print p and s" << endl;
    table_copy( s, p, Max);
    table_print( p, Max );  cout << endl << endl;
    table_print( s, Max );  cout << endl << endl;

    for (int i=0; i<Max/2+1; i++)
    {
	    s = p+10+i;
	    table_fill( s, 1, i*3 );
	    s = p+10-i;
	    table_fill( s, 1, i*6 );
    }

    p = s;
    s = tp;
    cout << endl << "Fill array with <-> " << endl;
    table_print( s, Max );  cout << endl << endl;

    cout << endl << "Min for previous table " << table_min( s, 15 );
    cout << endl << "Max for previous table " << table_max( s+10, 9);
    cout << endl << "Sum for previous table " << table_sum( s+11, 12);
    cout << endl << "Average for previous table " << table_avg( s+11, 12);

    avgValue = table_avg( s, Max);
    for ( int i=1; i<=Max; i++)
    {
        if ( table_contain( s, 1, avgValue) )
        {
            cnt++;
        }
        s++;
    };
    cout << "How many array values are equal to the average?" << endl;
    cout << "         cnt = " << cnt << endl << endl;

    ..........  You add code here for the two other tasks I have in the specs

    system("pause");    // code for VS only.  Delete for Codeblocks
    return 0;
}
