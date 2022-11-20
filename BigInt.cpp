#include <algorithm>
#include <compare>
#include <cstring>
#include <iostream>
#include <vector>


class BigInteger {
  const int base = 1'000'000;

 private:
  std::vector<int> big_int;
  size_t size;
  void Swap(BigInteger& a, BigInteger& b);
  void GetRidOfZero(BigInteger & a);

 public:
  BigInteger(const BigInteger& b) {  // copy
    big_int.clear();
    for (int i = 0; i < b.big_int.size(); ++i) {
      big_int.push_back(b.big_int[i]);
    }
    std::cout << " copied! " << std::endl;
  }

  BigInteger(std::string s) {
    for (int i = (int)s.length(); i > 0; i -= 9)
      if (i < 9)
        big_int.push_back(atoi(s.substr(0, i).c_str()));
      else
        big_int.push_back(atoi(s.substr(i - 9, 9).c_str()));
  }

  BigInteger(long long num) {
    while (num) {
      big_int.push_back(num % base);
      num /= base;
    }
  }

  ~BigInteger() = default;

 
  void Print() {
    printf("%d", big_int.empty() ? 0 : big_int.back());
    for (int i = (int)big_int.size() - 2; i >= 0; --i)
      printf("%09d", big_int[i]);
    std::cout << '\n';
  }

  BigInteger& operator+=(const BigInteger& add) {
    int carry = 0;
    for (int i = 0; i < std::max(big_int.size(), add.big_int.size()) || carry;
         ++i) {
      if (i == big_int.size()) big_int.push_back(0);
      big_int[i] += carry + (i < add.big_int.size() ? add.big_int[i] : 0);
      carry = big_int[i] >= base;
      if (carry) big_int[i] -= base;
    }
    return *this;
  }

  BigInteger& operator-=(const BigInteger& sub) {
    int carry = 0;
    for (size_t i = 0; i < sub.big_int.size() || carry; ++i) {
      big_int[i] -= carry + (i < sub.big_int.size() ? sub.big_int[i] : 0);
      carry = big_int[i] < 0;
      if (carry) big_int[i] += base;
    }
    GetRidOfZero(*this);
    return *this;
  }

  BigInteger& operator*=(const BigInteger& fac) {
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

  BigInteger& operator/=(long long div) {
    int carry = 0;
    for (int i=(int)big_int.size()-1; i>=0; --i) {
	    long long cur = big_int[i] + carry * 1ll * base;
	    big_int[i] = int (cur / div);
	    carry = int (cur % div);
    }
    GetRidOfZero(*this);
    return *this;
  }
    
  BigInteger& operator=(const BigInteger& b) {  // assign
    BigInteger copy = b;
    std::cout << " присвоили " << std::endl;
    Swap(*this, copy);
    return *this;
  }

  bool operator==(const BigInteger& b) {
    bool dif = (big_int.size() == b.big_int.size() ? 0 : 1);
    if (dif)
      return false;
    for (int i = 0; i < big_int.size(); ++i) {
      if (big_int[i] != b.big_int[i])
        return false;
    }
    return true;
  }

};

void BigInteger::Swap(BigInteger& a, BigInteger& b) {
  std::swap(a.big_int, b.big_int);
}

void BigInteger::GetRidOfZero(BigInteger& a) {
  while (a.big_int.size() > 1 && a.big_int.back() == 0)
	    a.big_int.pop_back();
}

BigInteger operator+(const BigInteger& a, const BigInteger& b) {  // Возвращаем копию объекта, а не ссылку, так как мы создаем новый объект
  BigInteger copy = a;
  copy += b;
  return copy;  // rvo
}

BigInteger operator-(const BigInteger& a, const BigInteger& b) {
  BigInteger copy = a;
  copy -= b;
  return copy;
}

BigInteger operator*(const BigInteger& a, const BigInteger& b) {
  BigInteger copy = a;
  copy *= b;
  return copy;
}

BigInteger operator/(const BigInteger& a, long long b) {
  BigInteger copy = a;
  copy /= b;
  return copy;
}

int main() {
  BigInteger a = 123;
  BigInteger b = a + 5;  // works just fine
  BigInteger c = a * 5;  // 0_o 
  a = a / 2;  // works just fine
  a.Print();
  b.Print();
  c.Print();
  
  return 0;
}