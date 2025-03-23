#include <iostream>
#include "ComplexClass.h"
using namespace std;


int main()
{
  TComplex a (1,4);
  TComplex b (2,7);
  a+=b;
  a*=b;
  cin >> b;
  a/=b;
  cout << a;
  return 0;
}
