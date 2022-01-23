#include "big_number.h"
#include <iostream>
int main( int argc, char **argv )
{
    if ( argc < 1 )
    {
        cout << "To few args\n";
        return 1;
    }
    big_number val_b(10);
    long long val_ll = 4;
    // char *val_c = argv[1];
    long val_l = 3;
    int val_i = 12;
    short val_s = 1;
    big_number bns(val_s);
    big_number bnl(val_l);
    big_number bnll(val_ll);
    cout << val_b + val_s << "\tshort\n";
    cout << val_b + val_i << "\tint\n";
    cout << val_b + val_l << "\tlong\n";
    cout << val_b + val_ll << "\tlong long\n";
    cout << (val_i < val_b) << "\tint<big_n\n";
    cout << (val_l < val_b) << "\tlong<big_n\n";
    cout << (val_ll < val_b) << "\tlonglong<big_n\n";
    cout << (val_s < val_b) << "\tshort<big_n\n";
    // cout << val_b.operator+( argv[1]) << "\tchar\n";
    // if ( argc < 2 )
    // {
    //     cout << "To few args\n";
    //     return 1;
    // }
    // big_number bn(argv[1]);
    // string sign(argv[2]);
    // big_number sec(argv[3]);
    // // big_number val;
    // // cout << "bn\t\t" << bn << endl;
    // // cout << "sec\t\t" << sec << endl;
    // if ( sign == "<" )
    //     cout << bn << " < " << sec << "=\t" << (bn < sec) << endl;
    // else if ( sign == ">" )
    //     cout << bn << " > " << sec << "=\t" << (bn > sec) << endl;
    // else if ( sign == "==" )
    //     cout << bn << " == " << sec << "=\t" << (bn == sec) << endl;
    // else if ( sign == "!=" )
    //     cout << bn << " != " << sec << "=\t" << (bn != sec) << endl;
    // else if ( sign == "+" )
    //     cout << bn << " + " << sec << "=\t" << (bn + sec) << endl;
    // else if ( sign == "-" )
    //     cout << bn << " - " << sec << "=\t" << (bn - sec) << endl;
    // else{
    //     cout << "invalid second arg\n"; return 0;}
    // cout << bn << " - " << "int" << "=\t" << (bn - atoi(argv[3])) << endl;
    // cout << bn << " - " << "long" << "=\t" << (bn - atol(argv[3])) << endl;
    // cout << bn << " - " << "char" << "=\t" << (bn - argv[3]) << endl;
    // cout << bn << " + " << "int" << "=\t" << (bn + atoi(argv[3])) << endl;
    // cout << bn << " + " << "long" << "=\t" << (bn + atol(argv[3])) << endl;
    // cout << bn << " + " << "char" << "=\t" << (bn + argv[3]) << endl;
    return 0;
}
