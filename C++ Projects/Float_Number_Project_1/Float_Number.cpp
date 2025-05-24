#include "Float_Number.h"
#include <stdexcept>
#include <cmath>

FloatNumber::FloatNumber(){
    integer=0;
    decimal=0;
}

FloatNumber::FloatNumber(double val){
    integer = val;
    decimal = val-integer*1000000;
}

FloatNumber::FloatNumber(long long i, long long d){
    integer = i;
    decimal = d;
}

long long FloatNumber::getInteger() const{
    return integer;
}

long long FloatNumber::getDecimal() const{
    return decimal;
}

void FloatNumber::setInteger(long long i){
    integer = i;
}

void FloatNumber::setDecimal(long long d) {
    decimal = d;
}

FloatNumber FloatNumber::operator+(const FloatNumber& rhs) const{
    long long new_int = integer+rhs.integer;
    long long new_dec = decimal+rhs.decimal;
    if (new_dec>=1000000) {
        new_int +=1;
        new_dec -=1000000;
    }

    return FloatNumber(new_int, new_dec);
}

FloatNumber FloatNumber::operator-(const FloatNumber& rhs) const{
    long long new_int = integer - rhs.integer;
    long long new_dec = decimal - rhs.decimal;
    if (new_dec<0) {
        new_int-=1;
        new_dec+=1000000;
    }

    return FloatNumber(new_int, new_dec);
}

FloatNumber FloatNumber::operator*(const FloatNumber& rhs) const{
    double result = toDouble() * rhs.toDouble();
    return FloatNumber(result);
}

FloatNumber FloatNumber::operator/(const FloatNumber& rhs) const{
    if (rhs.toDouble() == 0) {
        throw runtime_error("Invalid! divided by 0");
    }
    double result = toDouble() / rhs.toDouble();
    return FloatNumber(result);
}

bool FloatNumber::operator>(const FloatNumber& rhs) const {
    return toDouble() > rhs.toDouble();
}

bool FloatNumber::operator<(const FloatNumber& rhs) const {
    return toDouble() < rhs.toDouble();
}

bool FloatNumber::operator>=(const FloatNumber& rhs) const {
    return toDouble() >= rhs.toDouble();
}

bool FloatNumber::operator<=(const FloatNumber& rhs) const {
    return toDouble() <= rhs.toDouble();
}

bool FloatNumber::operator==(const FloatNumber& rhs) const {
    return integer== rhs.integer && decimal== rhs.decimal;
}

bool FloatNumber::operator!=(const FloatNumber& rhs) const {
    return integer != rhs.integer || decimal != rhs.decimal;
}

FloatNumber FloatNumber::operator+=(const FloatNumber& rhs) {
    return *this + rhs; 
}

FloatNumber FloatNumber::operator-=(const FloatNumber& rhs) {
    return *this - rhs; 
}

FloatNumber FloatNumber::operator*=(const FloatNumber& rhs) { 
    return *this * rhs; 
}

FloatNumber FloatNumber::operator/=(const FloatNumber& rhs) {
    return *this / rhs;
}

FloatNumber& FloatNumber::operator++() {
    integer++;
    return *this;
}

FloatNumber FloatNumber::operator++(int) {
    FloatNumber temp = *this;
    integer++;
    return temp;
}


FloatNumber& FloatNumber::operator--() {
    integer--;
    return *this;
}


FloatNumber FloatNumber::operator--(int) {
    FloatNumber temp = *this;
    integer--;
    return temp;
}

long long FloatNumber::operator[](int index){
    if (index == 0) {
        return integer;
    } else if (index == 1) {
        return decimal;
    } else {
        throw out_of_range("Index out of range");
    } 
}

double FloatNumber::toDouble() const
{
    return static_cast<double>(integer) + static_cast<double>(decimal) / 1000000.0;
}

ostream& operator<<(ostream &out, FloatNumber obj) {
    out << obj.getInteger() <<"."<< obj.getDecimal();
    return out;
}

istream& operator>>(istream &in, FloatNumber &obj) {
    cout <<"Enter integer part: ";
    in >>obj.integer;
    cout <<"Enter decimal part: ";
    in >>obj.decimal;
    return in;
}
