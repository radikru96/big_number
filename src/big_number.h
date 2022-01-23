#ifndef BIG_NUMBER
#define BIG_NUMBER
#include <ostream>
#include <string>
#include <cmath>
#include <typeinfo>
// #include <stdlib.h>
using namespace std;
class big_number
{
private:
    string number;
    int chartoi( const string& str, int i);
    big_number add_operation( const big_number first, const big_number second );
    big_number sub_operation( const big_number first, const big_number second );
protected:
    string &get_number();
public:
    big_number();
    big_number( const big_number& num );
    big_number( const char* num );
    template <class T>
    big_number( const T &num );
    // big_number( const short& num);
    // big_number( const int& num);
    // big_number( const long& num);
    // big_number( const long long& num);
    big_number &operator= ( const big_number &other );
    big_number &operator= ( const short &other );
    big_number &operator= ( const int &other );
    big_number &operator= ( const long &other );
    big_number &operator= ( const long long &other );
    big_number &operator= ( const char* other );
    big_number operator+ ( const big_number &other );
    big_number operator+ ( const short &other );
    big_number operator+ ( const int &other );
    big_number operator+ ( const long &other );
    big_number operator+ ( const long long &other );
    big_number operator+ ( const char* other );
    big_number operator- ( const big_number &other );
    big_number operator- ( const short &other );
    big_number operator- ( const int &other );
    big_number operator- ( const long &other );
    big_number operator- ( const long long &other );
    big_number operator- ( const char* other );
    friend ostream &operator<< ( ostream& os, const big_number &bn );
    bool operator< ( const big_number &other );
    bool operator< ( const short &other );
    bool operator< ( const int &other );
    bool operator< ( const long &other );
    bool operator< ( const long long &other );
    bool operator< ( const char* other );
    bool operator<= ( const big_number &other );
    bool operator<= ( const short &other );
    bool operator<= ( const int &other );
    bool operator<= ( const long &other );
    bool operator<= ( const long long &other );
    bool operator<= ( const char* other );
    bool operator> ( const big_number &other );
    bool operator> ( const short &other );
    bool operator> ( const int &other );
    bool operator> ( const long &other );
    bool operator> ( const long long &other );
    bool operator> ( const char* other );
    bool operator>= ( const big_number &other );
    bool operator>= ( const short &other );
    bool operator>= ( const int &other );
    bool operator>= ( const long &other );
    bool operator>= ( const long long &other );
    bool operator>= ( const char* other );
    bool operator== ( const big_number &other );
    bool operator== ( const short &other );
    bool operator== ( const int &other );
    bool operator== ( const long &other );
    bool operator== ( const long long &other );
    bool operator== ( const char* other );
    bool operator!= ( const big_number &other );
    bool operator!= ( const short &other );
    bool operator!= ( const int &other );
    bool operator!= ( const long &other );
    bool operator!= ( const long long &other );
    bool operator!= ( const char* other );
    // template <class T>
    // friend inline bool operator< ( const T &left_val, const big_number &other );
    friend bool operator< ( const short &short_this, const big_number &other );
    friend bool operator< ( const int &int_this, const big_number &other );
    friend bool operator< ( const long &long_this, const big_number &other );
    friend bool operator< ( const long long &long_long_this, const big_number &other );
    ~big_number();
};

#endif