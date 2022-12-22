#include "header.hpp"
#include <iostream>

int main() {
  {
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
  }
  {

  
  BigInteger a("127897438798531");
  BigInteger b("2446646843576");
  BigDouble c(a,b);
  BigDouble d(b,a);
  BigDouble x("10", "20");
  std::cout << "10 / 20 turns into :" << '\n';
  x.Print();
  c.Print();  
  c += d;
  c.Print();
  c /= d;
  c.Print();
  ++a;
  a.Print();
  BigInteger e = a++;
  e.Print();
  a.Print();
  }
  return 0;
}