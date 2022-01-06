#include "big_number.h"

int big_number::chartoi( const string& str, int i)
{
    char value = str.at(i);
    return atoi(&value);
}

big_number::big_number()
{
    number = '0';
}

big_number::big_number( const int& num)
{
    number = to_string( num );
}

big_number::big_number( const long& num)
{
    number = to_string( num );
}

big_number::big_number( const big_number& num )
{
    number = num.number;
}

big_number::big_number( const char* num )
{
    number = num;
}

string &big_number::get_number()
{
    return this->number;
}

big_number& big_number::operator = ( const big_number &other )
{
    this->number = other.number;
    return *this;
}

big_number& big_number::operator = ( const int &other )
{
    this->number = to_string( other );
    return *this;
}

big_number& big_number::operator = ( const long &other )
{
    this->number = to_string( other );
    return *this;
}

big_number& big_number::operator = ( const char* other )
{
    this->number = other ;
    return *this;
}

big_number big_number::operator + ( const big_number &other )
{
    big_number value;
    value.number.clear();
    if ( this->number[0] != '-' && other.number[0] != '-' )
    {
        value = add_operation( *this, other );
    }
    else if ( this->number[0] == '-' && other.number[0] == '-' )
    {
        big_number first = *this;
        big_number second = other;
        first.number.erase(first.number.begin());
        second.number.erase(second.number.begin());
        value = first + second;
        value.number.insert(value.number.begin(),'-');
        return value;
    }
    else
    {
        if ( this->number[0] == '-' )
            printf( "first number is negative\n" );
        if ( other.number[0] == '-' )
            printf( "second number is negative\n" );
    }
    return value;
}

big_number big_number::add_operation( const big_number first, const big_number second )
{
    int buf = 0;
    big_number value;
    value.number.clear();
    for ( int t = first.number.length()-1, o = second.number.length()-1; t >= 0 || o >= 0 || buf > 0; t--, o-- )
    {
        if ( o < 0 )
            buf += chartoi(first.number,t);
        else if ( t < 0 )
            buf += chartoi(second.number,o);
        else
            buf += chartoi(first.number,t) + chartoi(second.number,o);
        if ( value.number.empty() )
            value.number=to_string( buf%10 );
        else
            value.number.insert( 0, to_string( buf%10 ) );
        buf /= 10;
    }
    return value;
}

big_number big_number::operator- ( const big_number &other )
{
    big_number value;
    value.number.clear();
    if ( this->number[0] != '-' && other.number[0] != '-' )
    {
        value = sub_operation( *this, other );
    }
    else if ( this->number[0] == '-' && other.number[0] == '-' )
    {
        big_number thisval = *this;
        big_number otheval = other;
        thisval.number.erase(thisval.number.begin());
        otheval.number.erase(otheval.number.begin());
        if ( *this > other )
            value = otheval - thisval;
        else if ( *this < other )
        {
            value = thisval - otheval;
            value.number.insert( 0, "-" );
        }
        else
            value = 0;
    }
    else
    {
        big_number negative;
        big_number subtracted;
        if ( this->number[0] == '-' )
        {
            negative = *this;
            subtracted = other;
        }
        else
        {
            negative = other;
            subtracted = *this;
        }
        negative.number.erase(negative.number.begin());
        value = negative + subtracted;
        if ( subtracted == other )
            value.number.insert( 0, "-" );
    }
    return value;
}

big_number big_number::sub_operation( const big_number first, const big_number second )
{
    big_number decreased = first, subtracted = second, value;
    int buf=0, mem=0;
    value.number.clear();
    if ( decreased < subtracted )
    {
        decreased = second;
        subtracted = first;
    }
    else
    {
        decreased = first;
        subtracted = second;
    }
    for ( int d = decreased.number.length()-1, s = subtracted.number.length()-1; d >= 0 || s >= 0 ; d--, s-- )
    {
        if ( s < 0 )
        {
            if ( chartoi(decreased.number,d) < mem )
            {
                buf = (chartoi(decreased.number,d)+10) - mem;
                mem=1;
            }
            else
            {
                buf = chartoi(decreased.number,d) - mem;
                mem=0;
            }
        }
        else
        {
            if ( chartoi(decreased.number,d) < chartoi(subtracted.number,s) + mem )
            {
                buf = (chartoi(decreased.number,d)+10) - chartoi(subtracted.number,s) - mem;
                mem=1;
            }
            else
            {
                buf = chartoi(decreased.number,d) - chartoi(subtracted.number,s) - mem;
                mem=0;
            }
        }
        if ( value.number.empty() )
            value.number = to_string(buf);
        else
            value.number.insert( 0, to_string(buf) );
    }
    if ( subtracted == first && subtracted != second )
        value.number.insert( 0, "-" );
    return value;
}

ostream& operator<< ( ostream& os, const big_number &bn )
{
    return os << bn.number;
}

bool big_number::operator< ( const big_number &other )
{
    if ( this->number[0] == '-' && other.number[0] == '-' )
    {
        big_number thisval = *this;
        big_number otheval = other;
        thisval.number.erase(thisval.number.begin());
        otheval.number.erase(otheval.number.begin());
        if ( thisval <= otheval )
            return false;
        return true;
    }
    else if ( this->number[0] == '-' )
        return true;
    else if ( other.number[0] == '-' )
        return false;
    else
    {
        if ( this->number.length() > other.number.length() )
            return false;
        else if ( this->number.length() < other.number.length() )
            return true;
        else 
        {
            if ( *this == other )
                return false;
            for ( int i = 0; i < (int)this->number.length(); i++ )
            {
                if ( chartoi(this->number,i) > chartoi(other.number,i) )
                    return false;
                else if ( chartoi(this->number,i) < chartoi(other.number,i) )
                    return true;
            }
            return true;
        }
    }
}

bool big_number::operator> ( const big_number &other )
{
    if ( *this <= other )
        return false;
    return true;
}

bool big_number::operator>= ( const big_number &other )
{
    if ( *this > other || *this == other )
        return true;
    else
        return false;
}

bool big_number::operator<= ( const big_number &other )
{
    if ( *this < other || *this == other )
        return true;
    else
        return false;
}

bool big_number::operator== ( const big_number &other )
{
    return this->number==other.number;
}

bool big_number::operator!= ( const big_number &other )
{
    return !(*this==other);
}

big_number::~big_number()
{
}