#include "quadrat.cc"

// a)
bool ungerade(int zahl)
{
  return zahl%2;
}

// d)
int multsignal(int a, int b) {
  print("Weitere Multiplikation");
  return a*b;
}

// b)
// c) (exponent,#multiplikationen): (3,3), (5,4), (6,4)
int exponentation(int basis, int exponent)
{
  return cond(exponent<=0, cond(exponent==0,1,0),
    cond(ungerade(exponent),multsignal(basis,exponentation(basis, exponent-1)),
    quadrat(exponentation(basis,exponent/2))));
}
int main ()
{ 
  int a;
  a=exponentation(2,3);
  print(a);
  print("------");
  a=exponentation(2,5);
  print(a);
  print("------");
  a=exponentation(2,6);
  print(a);
  print("------");
  return 0;
}
