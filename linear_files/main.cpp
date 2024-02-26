#include <iostream>
#include "linear.h"


int main()
{
  int r,c;
  std::cout<<"Enter number of rows and columns: "<<std::endl;
  std::cin>>r>>c;
  Matrix one(r,c);
  one.fill_matrix();
  one.display_matrix();
  std::cout<<"Enter number of rows and columns: "<<std::endl;
  std::cin>>r>>c;
  Matrix two(r,c);
  two.fill_matrix();
  two.display_matrix();
  one.rref(two);
  one.display_matrix();
  two.display_matrix();
return 0;
}
