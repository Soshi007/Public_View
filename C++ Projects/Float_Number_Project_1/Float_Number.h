#include <iostream>
using namespace std;

class FloatNumber{
private: 
    long long integer;
    long long decimal;
public:
    long long getInteger() const {return integer;}
    long long getDecimal() const {return decimal;}

    void setInteger(long long i);
    void setDecimal(long long d);

    FloatNumber();
    FloatNumber(double val);
    FloatNumber(long long i, long long d);

    friend ostream& operator<<(ostream &out, const FloatNumber&);
    friend istream& operator>>(istream &in, FloatNumber&);

    FloatNumber operator+(const FloatNumber&) const;
    FloatNumber operator-(const FloatNumber&) const;
    FloatNumber operator*(const FloatNumber&) const;
    FloatNumber operator/(const FloatNumber&) const;

    bool operator>(const FloatNumber&) const;
    bool operator<(const FloatNumber&) const;
    bool operator>=(const FloatNumber&) const;
    bool operator<=(const FloatNumber&) const;
    bool operator==(const FloatNumber&) const;
    bool operator!=(const FloatNumber&) const;

    FloatNumber operator+=(const FloatNumber&);
    FloatNumber operator-=(const FloatNumber&);
    FloatNumber operator*=(const FloatNumber&);
    FloatNumber operator/=(const FloatNumber&);

    long long operator[](int);
    double toDouble() const;

    FloatNumber& operator++();    
    FloatNumber operator++(int);  
    FloatNumber& operator--();    
    FloatNumber operator--(int);

};

