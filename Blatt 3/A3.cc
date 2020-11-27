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
// d) Abarbeitung entspricht dem Substitutionsmodell, denn ansonsten hätten wir mehr
//    Multiplikationen als in c) angegeben. Denn dann dann würde quadrat(exp(b,e))
//    compiliert zu exp(b,e)*exp(b,e) und exp(b,e) müsste 2 mal berechnet werden.
//    Es wird aber compiliert zu e=exp(b,e); e*e und exp muss nur einmal berechnet werden.
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
