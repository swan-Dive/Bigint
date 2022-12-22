#include "header.hpp"
#include <compare>
#include <cstring>
#include <iostream>
#include <vector>

BigInteger::BigInteger(){
  big_int.push_back(0);
}

BigInteger::BigInteger(const std::string& s){
   for (int i = (int)s.length(); i > 0; i -= 9)
      if (i < 9)
        big_int.push_back(atoi(s.substr(0, i).c_str()));
      else
        big_int.push_back(atoi(s.substr(i - 9, 9).c_str()));
}

BigInteger::BigInteger(long long num) {
  while (num) {
    big_int.push_back(num % base);
    num /= base;
  }
}

BigInteger::BigInteger(const BigInteger& b){  //copy
  for (int i = 0; i < b.big_int.size(); ++i) {
    big_int.push_back(b.big_int[i]);
  }
}

int BigInteger::CountNum() const {
  int result = (big_int.size() - 1) * 9;
  int temp = big_int[big_int.size() - 1];
  while (temp) {
    ++result;
    temp/=10;
  }
  return result;
}

void BigInteger::Print() const {
  printf("%d", big_int.empty() ? 0 : big_int.back());
  for (int i = (int)big_int.size() - 2; i >= 0; --i)
    printf("%09d", big_int[i]);
  std::cout << '\n';
}

BigInteger& BigInteger::operator+=(const BigInteger& add){
  int carry = 0;
  for (size_t i = 0; i < std::max(big_int.size(), add.big_int.size()) || carry;
        ++i) {
    if (i == big_int.size()) big_int.push_back(0);
    big_int[i] += carry + (i < add.big_int.size() ? add.big_int[i] : 0);
    carry = big_int[i] >= base;
    if (carry) big_int[i] -= base;
  }
  return *this;
}

BigInteger& BigInteger::operator-=(const BigInteger& sub) {
  int carry = 0;
  for (size_t i = 0; i < sub.big_int.size() || carry; ++i) {
    big_int[i] -= carry + (i < sub.big_int.size() ? sub.big_int[i] : 0);
    carry = big_int[i] < 0;
    if (carry) big_int[i] += base;
  }
  GetRidOfZero(*this);
  return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& fac) {
  std::vector<int>c(big_int.size() + fac.big_int.size());

  for (size_t i = 0; i < big_int.size(); ++i)
    for (int j = 0, carry = 0; j < (int)fac.big_int.size() || carry; ++j) {
      long long cur = c[i+j] + big_int[i] * 1ll * (j < (int)fac.big_int.size() ? fac.big_int[j] : 0) + carry;
      c[i+j] = int (cur % base);
      carry = int (cur / base);
  }
  big_int = c;
  GetRidOfZero(*this);
  return *this;
}

BigInteger& BigInteger::operator/=(const BigInteger& div) {
  if (div == BigInteger(0)){
    std::cout << "cant divide by zero";
  return *this;
  }
  BigInteger b = div;
  BigInteger current;
  for (long long i = static_cast<long long>(this->big_int.size()) - 1; i >= 0; --i){
    current.ShiftRight();
    current.big_int[0] = this->big_int[i];
    GetRidOfZero(current);
    int x = 0, l = 0, r = 1'000'000'000;
    while (l <= r) {
      int m = (l + r) / 2;
      BigInteger t = b;
      t *= m;
      if (t <= current) {
        x = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    this->big_int[i] = x;
    BigInteger min = b;
    min *= x;
    current -= min;
  }
  GetRidOfZero(*this);
  return *this;
}

BigInteger& BigInteger::operator%=(const BigInteger& divider) {
  BigInteger min = *this;
  min /= divider;
  min *= divider; 
  *this -= min;
  return *this;
}

BigInteger operator+(const BigInteger& a, const BigInteger& b) {
  BigInteger copy = a;
  copy += b;
  return copy;  // rvo
}

BigInteger operator-(const BigInteger& a, const BigInteger& b) {
  BigInteger copy = a;
  copy -= b;
  return copy;
}

BigInteger operator/(const BigInteger& a, const BigInteger& b) {
  BigInteger copy = a;
  copy /= b;
  return copy;
}

BigInteger operator*(const BigInteger& a, const BigInteger& b) {
  BigInteger copy = a;
  copy *= b;
  return copy;
}
BigInteger operator%(const BigInteger& a, const BigInteger& b) {
  BigInteger result = a;
  result %= b;
  return result;
}

BigInteger& BigInteger::operator++() {
  *this += 1;
  return *this;
}

BigInteger& BigInteger::operator--() {
  *this -= 1;
  return *this;
}

BigInteger BigInteger::operator++(int) {
  BigInteger copy = *this;
  *this += 1;
  return copy;
}

BigInteger BigInteger::operator--(int) {
  BigInteger copy = *this;
  *this -= 1;
  return copy;
}

BigInteger& BigInteger::operator=(const BigInteger& b){  //assign
  BigInteger copy = b;
  Swap(*this, copy);
  return *this;
}

bool BigInteger::operator==(const BigInteger& b) const {
  bool dif = (big_int.size() == b.big_int.size() ? 0 : 1);
  if (dif)
    return false;
  for (int i = 0; i < big_int.size(); ++i) {
    if (big_int[i] != b.big_int[i])
      return false;
  }
  return true;
}

bool BigInteger::operator<(const BigInteger& right) const {
  if (*this == right) return false;
  if (this->big_int.size() != right.big_int.size()) {
    return this->big_int.size() < right.big_int.size();
  }
  else {
    for (long long i = this->big_int.size() - 1; i >= 0; --i) {
      if (this->big_int[i] != right.big_int[i]) return this->big_int[i] < right.big_int[i];
    }
    return false;
  }
}

bool BigInteger::operator<=(const BigInteger& right) const {
  return (*this == right || *this < right);
}

bool BigInteger::operator>(const BigInteger& right) const {
  return !(*this <= right);
}

bool BigInteger::operator>=(const BigInteger& right) const {
  return !(*this < right);
}
bool BigInteger::operator!=(const BigInteger& right) const {
  return !(*this == right);
}


void BigInteger::Swap(BigInteger& a, BigInteger& b) {
  std::swap(a.big_int, b.big_int);
}

void BigInteger::GetRidOfZero(BigInteger& a) {
  while (a.big_int.size() > 1 && a.big_int.back() == 0)
	  a.big_int.pop_back();
}

void BigInteger::ShiftRight() {
  if (this->big_int.size() == 0) {
    this->big_int.push_back(0);
    return;
  }
  this->big_int.push_back(this->big_int[this->big_int.size() - 1]);
  for (size_t i = this->big_int.size() - 2; i > 0; --i) this->big_int[i] = this->big_int[i - 1];
  this->big_int[0] = 0;
}

BigInteger GCD(BigInteger a, BigInteger b) {
  if (a == 0) 
    return b;
  if (b == 0) 
    return a;
  if (a == b)
    return b;
  if (a > b) 
    return GCD(a - b, b);
  return GCD(a, b - a);
}



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
