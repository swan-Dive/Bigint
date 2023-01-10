#ifndef HEADER_HPP
#define HEADER_HPP

#include <vector>
#include <iostream>

class BigInteger {
  private:
    const int base = 1'000'000'000;
    std::vector<int> big_int;
    
    void Swap(BigInteger& , BigInteger& );
    void GetRidOfZero(BigInteger& );
    void ShiftRight();
  public:
    BigInteger();
    BigInteger(const std::string& a);
    BigInteger(long long);

    BigInteger(const BigInteger&);  //copy

    int CountNum() const;
    void Print() const;

    BigInteger& operator+=(const BigInteger&);
    BigInteger& operator-=(const BigInteger&);
    BigInteger& operator*=(const BigInteger&);
    BigInteger& operator/=(const BigInteger&);
    BigInteger& operator%=(const BigInteger&);
    BigInteger& operator++();
    BigInteger& operator--();
    BigInteger operator++(int);
    BigInteger operator--(int);
    
    BigInteger& operator=(const BigInteger&);  //assign
    
    bool operator==(const BigInteger&) const;
    bool operator<(const BigInteger&) const;
    bool operator>(const BigInteger&) const;
    bool operator<=(const BigInteger&) const;
    bool operator>=(const BigInteger&) const;
    bool operator!=(const BigInteger&) const;

};

BigInteger operator+(const BigInteger&, const BigInteger&);
BigInteger operator-(const BigInteger&, const BigInteger&);
BigInteger operator/(const BigInteger&, const BigInteger&);
BigInteger operator*(const BigInteger&, const BigInteger&);
BigInteger operator%(const BigInteger&, const BigInteger&);

BigInteger GCD(BigInteger, BigInteger);

class BigDouble {
  private:
    BigInteger numenator;
    BigInteger denumenator;
    void Swap(BigDouble&, BigDouble&);
  public:
    BigDouble();
    BigDouble(const BigInteger&, const BigInteger&);
    BigDouble(const std::string&, const std::string&);
    BigDouble(const BigInteger&);
    BigDouble(const long long);

    BigDouble(const BigDouble&); // copy
    BigDouble& operator=(const BigDouble&);  // asign

    void Print() const;

    BigDouble operator+=(const BigDouble&);
    BigDouble operator-=(const BigDouble&);
    BigDouble operator/=(const BigDouble&);
    BigDouble operator*=(const BigDouble&);
    BigDouble& operator++();
    BigDouble& operator--();
    BigDouble operator++(int);
    BigDouble operator--(int);

};

BigDouble operator+(const BigDouble&, const BigDouble&);
BigDouble operator-(const BigDouble&, const BigDouble&);
BigDouble operator/(const BigDouble&, const BigDouble&);
BigDouble operator*(const BigDouble&, const BigDouble&);

#endif