#include "big_number.h"
#include <iostream>
int main( int argc, char **argv )
{
    if ( argc < 2 )
    {
        cout << "To few args\n";
        return 1;
    }
    big_number bn(argv[1]);
    string sign(argv[2]);
    big_number sec(argv[3]);
    // big_number val;
    // cout << "bn\t\t" << bn << endl;
    // cout << "sec\t\t" << sec << endl;
    if ( sign == "<" )
        cout << bn << " < " << sec << "=\t" << (bn < sec) << endl;
    else if ( sign == ">" )
        cout << bn << " > " << sec << "=\t" << (bn > sec) << endl;
    else if ( sign == "==" )
        cout << bn << " == " << sec << "=\t" << (bn == sec) << endl;
    else if ( sign == "!=" )
        cout << bn << " != " << sec << "=\t" << (bn != sec) << endl;
    else if ( sign == "+" )
        cout << bn << " + " << sec << "=\t" << (bn + sec) << endl;
    else if ( sign == "-" )
        cout << bn << " - " << sec << "=\t" << (bn - sec) << endl;
    else
        cout << "invalid second arg\n";
    return 0;
}
