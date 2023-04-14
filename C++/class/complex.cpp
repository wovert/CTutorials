#include <iostream>

using namespace std;

template<typename T>
class Complex {
private:
  T re, im;
  //friend Complex& __doapl(complex*, const complex&);
public:
  Complex(T r=0, T i=0) : re(r), im(i) {}
  Complex& operator += (const Complex&);
  T real() const { return re; }
  T imag() const { return im; }
};


int main() {
  Complex<double> c1(2.5, 1.5);
  Complex<int> c2(2, 6);

  return 0;
}
