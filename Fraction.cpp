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

Fraction::Fraction(const Fraction &other) {}

Fraction::Fraction(Fraction &&other) {}

Fraction::Fraction(std::string s) {
    std::string current = "";

    for(auto x : s){
        if(x == ' '){
            hasWhole = true;
            if(stoi(current) > 0){
                isPositiveNum = true;
            }
            wholeValue = abs(stoi(current));
            current = "";
        }else if(x == '/'){
            hasFraction = true;
            if(stoi(current) <= 0){
                isPositiveNum = false;
            }
            numeratorValue = abs(stoi(current));
            current = "";
        }else{
            current += x;
        }
    }

    if(hasFraction == false){
        if(stoi(current) > 0){
            isPositiveNum = true;
        }
        wholeValue = abs(stoi(current));
    }else{
        hasWhole = true;
        denominatorValue = stoi(current);
        if(denominatorValue == 0){
            throw std::invalid_argument("Negative Denominator");
        }
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

Fraction& Fraction::operator=(const Fraction &other) { return *this; }

Fraction& Fraction::operator=(Fraction &&other) { return *this; }

Fraction Fraction::operator+(int num) const { 
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

void Fraction::makeProper() {}

Fraction Fraction::toProper() const { return {}; }

void Fraction::reduce() {}

Fraction Fraction::toReduced() const { return {}; }

ostream &Fraction::writeTo(ostream &os) const { return os; }

istream &Fraction::readFrom(istream &sr) /*throw(std::invalid_argument) */ {
    return sr;
}

bool Fraction::isReduced() const { return {}; }

bool Fraction::isProper() const { return {}; }

ostream &operator<<(ostream &os, const Fraction &f) { return os; }

istream &operator>>(istream &s, Fraction &f) { return s; }

#if I_DO_EXTRA_CREDIT
optional<string> Fraction::isRepeating() const { return {}; }

string Fraction::operator()(int len) const { return {}; }
#endif