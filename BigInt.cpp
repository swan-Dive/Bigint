#include <algorithm>
#include <compare>
#include <cstring>
#include <iostream>
#include <vector>


class BigInteger {
  const int base = 1'000'000'000;

 private:
  std::vector<int> big_int;
  void Swap(BigInteger& a, BigInteger& b);
  void GetRidOfZero(BigInteger& a);

 public:
  BigInteger(const BigInteger& b) {  // copy
    for (int i = 0; i < b.big_int.size(); ++i) {
      big_int.push_back(b.big_int[i]);
    }
  }
  BigInteger() {
    big_int.push_back(0);
  };
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

  int CountNum() {
    int result = (big_int.size() - 1) * 9;
    int temp = big_int[big_int.size() - 1];
    while (temp) {
      ++result;
      temp/=10;
    }
    return result;
  }

  void Print() {
    printf("%d", big_int.empty() ? 0 : big_int.back());
    for (int i = (int)big_int.size() - 2; i >= 0; --i)
      printf("%09d", big_int[i]);
    std::cout << '\n';
  }

  BigInteger& operator+=(const BigInteger& add) {
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


  BigInteger operator%=( const BigInteger& divider) {
    if (*this == divider || (divider.big_int[0] == 0 && divider.big_int.size() == 1)) {
      return BigInteger(0);
    }

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

class BigDouble {
private:
  BigInteger numenator;
  BigInteger denumenator;

  void Swap(BigDouble& a, BigDouble& b) {
    std::swap(a.numenator, b.numenator);
    std::swap(a.denumenator, b.denumenator);
  }  
public:
  BigDouble(BigInteger numenator_, BigInteger denumenator_) : numenator(numenator_), denumenator(denumenator_) {};
  BigDouble(std::string numenator_, std::string denumenator_) {
    BigInteger num(numenator_);
    BigInteger denum(denumenator_);
    numenator = num;
    denumenator = denum;
  };
  BigDouble(BigInteger numenator_) : numenator(numenator_), denumenator(1) {};
  BigDouble(long long num) : numenator(num), denumenator(1) {};
  BigDouble(const BigDouble& num) { // copy
    numenator = num.numenator;
    denumenator = num.denumenator;
  }
  BigDouble& operator=(const BigDouble& b) {  // assign
    BigDouble copy = b;
    Swap(*this, copy);
    return *this;
  }


  ~BigDouble() = default;

  void Print();

  BigDouble& operator+=(const BigDouble& num) {
    numenator *= num.denumenator;
    numenator += (denumenator * num.numenator);
    denumenator *= num.denumenator;
    return *this;
  }

  BigDouble& operator-=(const BigDouble& num) {
    numenator *= num.denumenator;
    denumenator *= num.denumenator;
    numenator -= (denumenator * num.numenator);
    return *this;
  }

  BigDouble& operator*=(const BigDouble& num) {
    numenator *= num.numenator;
    denumenator *= num.denumenator;
    return *this;
  }

  BigDouble& operator/=(const BigDouble& num) {
    numenator *= num.denumenator;
    denumenator *= num.numenator;
    return *this;
  }

  
};


void BigDouble::Print() {
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

BigDouble operator+(const BigDouble& a, const BigDouble& b) {  // Возвращаем копию объекта, а не ссылку, так как мы создаем новый объект
  BigDouble copy = a;
  copy += b;
  return copy;  // rvo
}

BigDouble operator-(const BigDouble& a, const BigDouble& b) {
  BigDouble copy = a;
  copy -= b;
  return copy;
}

BigDouble operator*(const BigDouble& a, const BigDouble& b) {
  BigDouble copy = a;
  copy *= b;
  return copy;
}

BigDouble operator/(const BigDouble& a, const BigDouble& b) {
  BigDouble copy = a;
  copy /= b;
  return copy;
}



int main() {
  BigInteger a("12345678901234567890");
  BigInteger b = 123456789; 
  BigInteger c = a + b;
  std::cout << "a = ";
  a.Print();
  std::cout << "b = ";
  b.Print();
  std::cout << "a + b = c = ";
  c.Print(); 
  c -= b;
  std::cout << "c - b = ";
  c.Print();
  std::cout << "assigning c - 4000000000000" << '\n' << "c = ";
  c = 4000000000000;
  c.Print();
  c *= 20;
  std::cout << "c * 20 = ";
  c.Print();
  std::cout << "initial c = ";
  c = c / 20;
  c.Print();
  std::cout << " c - 123456789 = ";
  BigInteger d = c - 123456789;
  d.Print();
  std::cout << '\n' << '\n' << '\n' << '\n';

  { // BigDouble
  BigDouble a("55124121","1124812094186193489125071326");
  BigDouble b("6592193414","1254897351531537834");
  a /= b;
  a.Print();
  }
  return 0;
}
