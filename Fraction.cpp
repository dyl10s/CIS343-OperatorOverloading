#include "Fraction.h"
#include <algorithm>
#include <iomanip>
#include <regex>

using namespace std;

/* Friend functions */
Fraction operator+(int val, const Fraction &f) { return {}; }

Fraction operator-(int val, const Fraction &f) { return {}; }

Fraction operator*(int val, const Fraction &f) { return {}; }

Fraction::Fraction() {}

Fraction::Fraction(int v) {
    hasWhole = true;
    if(v > 0){
        isPositiveNum = true;
    }

    wholeValue = abs(v);
    numeratorValue = 0;
    denominatorValue = 1;
}

Fraction::Fraction(const Fraction &other) {
    hasWhole = other.hasWhole;
    hasFraction = other.hasFraction;
    isPositiveNum = other.isPositiveNum;
    wholeValue = other.wholeValue;
    numeratorValue = other.numeratorValue;
    denominatorValue = other.denominatorValue;
}

Fraction::Fraction(Fraction &&other) {

}

Fraction::Fraction(std::string s) {
    if(s.find('-') != std::string::npos){
        isPositiveNum = false;
    }else{
        isPositiveNum = true;
    }

    if(s.find('/') == std::string::npos){
        hasWhole = true;
        wholeValue = abs(stoi(s));
    }else if(s.find(' ') != std::string::npos){
        hasWhole = true;
        hasFraction = true;
        wholeValue = abs(stoi(s.substr(0, s.find(' '))));
        numeratorValue = abs(stoi(s.substr(s.find(' '), s.find('/') - s.find(' '))));
        denominatorValue = abs(stoi(s.substr(s.find('/') + 1, s.length() - (s.find('/') + 1))));
    }else{
        hasFraction = true;
        numeratorValue = abs(stoi(s.substr(0, s.find('/'))));
        denominatorValue = abs(stoi(s.substr(s.find('/') + 1, s.length() - (s.find('/') + 1))));
    }

    if(denominatorValue == 0){
        throw std::invalid_argument("Zero in Denominator");
    }
}

int Fraction::whole() const { 
    return wholeValue; 
}

int Fraction::numerator() const { 
    return numeratorValue; 
}

int Fraction::denominator() const { 
    if(hasFraction){
        return denominatorValue; 
    }else{
        return 1;
    }
}

bool Fraction::isPositive() const { 
    return isPositiveNum;
}

Fraction& Fraction::operator=(const Fraction &other) { 
    hasWhole = other.hasWhole;
    hasFraction = other.hasFraction;
    isPositiveNum = other.isPositiveNum;
    wholeValue = other.wholeValue;
    numeratorValue = other.numeratorValue;
    denominatorValue = other.denominatorValue;
    return *this;
}

Fraction& Fraction::operator=(Fraction &&other) { 
    hasWhole = other.hasWhole;
    hasFraction = other.hasFraction;
    isPositiveNum = other.isPositiveNum;
    wholeValue = other.wholeValue;
    numeratorValue = other.numeratorValue;
    denominatorValue = other.denominatorValue;
    return *this;
}

Fraction Fraction::operator+(int num) const { 
    Fraction f{*this};
    f.setWhole(f.whole() + num);
    return f;
}

Fraction Fraction::operator+(const Fraction &other) const { return {}; }

Fraction Fraction::operator-() const { return {}; }

Fraction Fraction::operator-(int val) const { return {}; }

Fraction Fraction::operator-(const Fraction &other) const { return {}; }

Fraction Fraction::operator*(int val) const { return {}; }

Fraction Fraction::operator*(const Fraction &other) const { return {}; }

optional<int> Fraction::operator[](int pos) const { return {}; }

bool Fraction::operator<(const Fraction &other) const { return {}; }

bool Fraction::operator==(const Fraction &other) const { return {}; }

void Fraction::makeProper() {
    int wholeChunks = numeratorValue / denominatorValue;
    numeratorValue -= wholeChunks * denominatorValue;
    if(numeratorValue == 0){
        hasFraction = false;
        denominatorValue = 1;
    }
    wholeValue += wholeChunks;
}

Fraction Fraction::toProper() const { 
    Fraction f{*this};

    int wholeChunks = numeratorValue / denominatorValue;
    f.setNumerator(f.numerator() - wholeChunks * denominatorValue);
    f.setWhole(f.whole() + wholeChunks);

    return f;
}

void Fraction::reduce() {}

Fraction Fraction::toReduced() const { return {}; }

ostream &Fraction::writeTo(ostream &os) const { return os; }

istream &Fraction::readFrom(istream &sr) /*throw(std::invalid_argument) */ {
    return sr;
}

bool Fraction::isReduced() const { return {}; }

bool Fraction::isProper() const { 
    if(hasFraction){
        if(numeratorValue >= denominatorValue){
            return false;
        }else{
            return true;
        }
    }
    return false;
}

ostream &operator<<(ostream &os, const Fraction &f) { return os; }

istream &operator>>(istream &s, Fraction &f) { return s; }

void Fraction::setNumerator(int v){
    if(v == 0){
        hasFraction = false;
        denominatorValue = 0;
    }
    numeratorValue = v;
}

void Fraction::setDenominator(int v){
    denominatorValue = v;
}

void Fraction::setWhole(int v){
    wholeValue = v;
}

#if I_DO_EXTRA_CREDIT
optional<string> Fraction::isRepeating() const { return {}; }

string Fraction::operator()(int len) const { return {}; }
#endif