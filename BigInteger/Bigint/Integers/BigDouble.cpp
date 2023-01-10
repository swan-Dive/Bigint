#include "../header_folder/header.hpp"
#include <compare>
#include <cstring>
#include <iostream>
#include <vector>


void BigDouble::Swap(BigDouble& a, BigDouble& b) {
  std::swap(a.numenator, b.numenator);
  std::swap(a.denumenator, b.denumenator);
}
BigDouble::BigDouble() = default;

BigDouble::BigDouble(const BigInteger& numenator_, const BigInteger& denumenator_) : numenator(numenator_), denumenator(denumenator_) {
  BigInteger divider = GCD(numenator, denumenator);
  while (divider != 1) {
    numenator /= divider;
    denumenator /= divider;
    divider = GCD(numenator, denumenator);
  }
}

BigDouble::BigDouble(const std::string& numenator_, const std::string& denumenator_) {
  BigInteger num(numenator_);
  BigInteger denum(denumenator_);
  numenator = num;
  denumenator = denum;
  BigInteger divider = GCD(numenator, denumenator);
  while (divider != 1) {
    numenator /= divider;
    denumenator /= divider;
    divider = GCD(numenator, denumenator);
  }
}
BigDouble::BigDouble(const BigInteger& numenator_) : numenator(numenator_), denumenator(1) {}
BigDouble::BigDouble(const long long num) : numenator(num), denumenator(1) {}

BigDouble::BigDouble(const BigDouble& num){ // copy
  numenator = num.numenator;
  denumenator = num.denumenator;
}
BigDouble& BigDouble::operator=(const BigDouble& b){  // asign
  BigDouble copy = b;
  Swap(*this, copy);
  return *this;
}

void BigDouble::Print() const {
  int dashes = std::max(numenator.CountNum(), denumenator.CountNum());
  for (int i = (dashes - numenator.CountNum()) / 2; i > 0; --i ) {
    std::cout << " ";
  }
  numenator.Print();
  for (int i = 0; i < dashes; ++i) {
    std::cout << "-";
  }
  std::cout << std::endl;
  for (int i = (dashes - denumenator.CountNum()) / 2; i > 0; --i ) {
    std::cout << " ";
  }
  denumenator.Print();
  std::cout << std::endl;
}

BigDouble BigDouble::operator+=(const BigDouble& num) {
  numenator *= num.denumenator;
  numenator += (denumenator * num.numenator);
  denumenator *= num.denumenator;
  BigInteger divider = GCD(numenator, denumenator);
  while (divider != 1) {
    numenator /= divider;
    denumenator /= divider;
    divider = GCD(numenator, denumenator);
  }
  return *this;
}
BigDouble BigDouble::operator-=(const BigDouble& num) {
  numenator *= num.denumenator;
  denumenator *= num.denumenator;
  numenator -= (denumenator * num.numenator);
  BigInteger divider = GCD(numenator, denumenator);
  while (divider != 1) {
    numenator /= divider;
    denumenator /= divider;
    divider = GCD(numenator, denumenator);
  }
  return *this;
}
BigDouble BigDouble::operator/=(const BigDouble& num) {
  numenator *= num.numenator;
  denumenator *= num.denumenator;
  BigInteger divider = GCD(numenator, denumenator);
  while (divider != 1) {
    numenator /= divider;
    denumenator /= divider;
    divider = GCD(numenator, denumenator);
  }
  return *this;
}
BigDouble BigDouble::operator*=(const BigDouble& num) {
  numenator *= num.denumenator;
  denumenator *= num.numenator;
  BigInteger divider = GCD(numenator, denumenator);
  while (divider != 1) {
    numenator /= divider;
    denumenator /= divider;
    divider = GCD(numenator, denumenator);
  }
  return *this;
}

BigDouble operator+(const BigDouble& a, const BigDouble& b) {
  BigDouble copy = a;
  copy += b;
  return copy;  // rvo
}
BigDouble operator-(const BigDouble& a, const BigDouble& b) {
  BigDouble copy = a;
  copy -= b;
  return copy;
}
BigDouble operator/(const BigDouble& a, const BigDouble& b) {
  BigDouble copy = a;
  copy /= b;
  return copy;
}
BigDouble operator*(const BigDouble& a, const BigDouble& b) {
  BigDouble copy = a;
  copy *= b;
  return copy;
}
