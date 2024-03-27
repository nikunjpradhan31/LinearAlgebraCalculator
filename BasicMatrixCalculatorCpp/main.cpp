#include <iostream>
#include "linear.h"


int main()
{
  int r,c;
  std::cout<<"Enter number of rows and columns: ";
  std::cin>>r>>c;
  Matrix one(r,c);
  one.fill_matrix();
  one.display_matrix();
  std::cout<<"Enter number of rows and columns: ";
  std::cin>>r>>c;
  Matrix two(r,c);
  two.fill_matrix();
  two.display_matrix();
  one.Gauss_Jordan(two);
return 0;
}
