#include "fcpp.hh"

// Gruppe: Lowack, Meier, Jaschke


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

int quadrat(int x)
{
  return multsignal(x,x);
}

// b)
// c) (exponent, Anzahl multiplikationen):
//    Bei schneller Rekursion: (8,4), (11,6), (15,7) 
//    Bei normaler Rekursion immer n-1: (8,7), (11,10), (15,14)
// d) Abarbeitung entspricht dem Substitutionsmodell, denn ansonsten hätten wir mehr
//    Multiplikationen als in c) angegeben. Denn dann dann würde quadrat(exp(b,e/2))
//    compiliert zu exp(b,e/2)*exp(b,e/2) und exp(b,e/2) müsste 2 mal berechnet werden.
//    Es wird aber compiliert zu e=exp(b,e/2); e*e und exp muss nur einmal berechnet werden.
//    Die schnelle exponentiation nicht substitutive ausgewertet würde genauso viele
//    Multiplikationen benötigen wie die normale Rekursion.
int exponentation(int basis, int exponent)
{
  return cond(exponent<=0, cond(exponent==0,1,0),
    cond(ungerade(exponent),multsignal(basis,exponentation(basis, exponent-1)),
    quadrat(exponentation(basis,exponent/2))));
}
int main ()
{ 
  int a;
  a=exponentation(2,8);
  print(a);
  print("------");
  a=exponentation(2,11);
  print(a);
  print("------");
  a=exponentation(2,15);
  print(a);
  print("------");
  return 0;
}
