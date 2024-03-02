#include <iostream>
#include "linear.h"

Matrix::Matrix(int rows, int cols) : r(rows), c(cols)
{
  Matrix::matrix = new double*[Matrix::r];
  for(int i = 0; i < r; i++)
    Matrix::matrix[i] = new double[Matrix::c];
}

Matrix::Matrix() : r(1), c(1)
{
  Matrix::matrix = new double*[Matrix::r];
  for(int i = 0; i < r; i++)
    Matrix::matrix[i] = new double[Matrix::c];
  Matrix::matrix[Matrix::r][Matrix::c] = 1;
}

Matrix::~Matrix()
{
  for(int i = 0;i<r;i++)
  {
    delete [] matrix[i];
  }
  delete [] matrix;
  matrix = nullptr;
  r = 0;
  c = 0;
}

double** Matrix::getmatrix() const
{
 return Matrix::matrix;
}

int Matrix::getrows() const
{
 return Matrix::r;
}

int Matrix::getcols() const
{
 return Matrix::c;
}

void Matrix::fill_matrix()
{
  std::cout<<"\n";
  for(int x = 0; x < Matrix::r; x++)
  {
    for(int y = 0; y < Matrix::c; y++)
    {
      std::cin>>Matrix::matrix[x][y];
    }
  }

}

void Matrix::display_matrix()
{
  std::cout<<"\n";
  for(int x = 0; x < Matrix::r; x++)
  {
    for(int y = 0; y < Matrix::c; y++)
    {
      std::cout<<Matrix::matrix[x][y]<< " ";
    }
    std::cout<<"\n";
  }

}

void Matrix::display_matrix(Matrix const& other)
{
    std::cout<<"\n";
  for(int x = 0; x < r; x++)
  {
    for(int y = 0; y < c; y++)
    {
      std::cout<<matrix[x][y]<< " ";
    }
    std::cout<<"| "<<other.getmatrix()[x][0]<<"\n";
  }
}

void Matrix::transpose_matrix()
{
  int new_rows = c;
  int new_cols = r;
  Matrix tmp(new_rows,new_cols);
  for(int x = 0; x < new_rows; x++)
  {
    for(int y = 0; y < new_cols;y++)
    {
      tmp.getmatrix()[x][y] = matrix[y][x];
    }
  }
  *this = tmp;

}

Matrix Matrix::operator+(Matrix const& other)
{//
  if(r == other.getrows() && c == other.getcols())
  {//
    Matrix sum(r,c);
    for(int x = 0; x < r; x++)
    {//
      for(int y = 0; y < c;y++)
      {//
	sum.getmatrix()[x][y] = matrix[x][y] + other.getmatrix()[x][y];
      }//
    }//
   return sum;
  }//
  else
  {//
   std::cout<<"Error: The matrices have different dimensions, so Addition can not be performed"<<std::endl;
   return Matrix();
  }//
}//

Matrix Matrix::operator-(Matrix const& other)
{//
  if(r == other.getrows() && c == other.getcols())
  {//
    Matrix sum(r,c);
    for(int x = 0; x < r; x++)
    {//
      for(int y = 0; y < c;y++)
      {//
        sum.getmatrix()[x][y] = matrix[x][y] - other.getmatrix()[x][y];
      }//
    }//
   return sum;
  }//
  else
  {//
   std::cout<<"Error: The matrices have different dimensions, so Subtraction can not be performed"<<std::endl;
   return Matrix();
  }//
}//

Matrix Matrix::operator*(Matrix const& other)
{//
  if(c == other.getrows())
  {//
    double sum_num;
    Matrix sum(r,other.getcols());
    for(int x = 0; x < r; x++)
    {
      for(int y = 0; y < other.getcols(); y++)
      {
	sum_num = 0;
	for( int z = 0; z < c; z++)
	{
	sum_num += matrix[x][z] * other.getmatrix()[z][y];
	}
	sum.getmatrix()[x][y] = sum_num;
      }
    }
   return sum;
  }//
  else
  {//
   std::cout<<"Error: The matrices have different dimensions, so Addition can not be performed"<<std::endl;
   return Matrix();
  }//
}//

void Matrix::operator=(Matrix const& other)
{
  for(int x = 0; x<r; x++)
    delete [] matrix[x];
  delete [] matrix;
  r = other.getrows();
  c = other.getcols();
  matrix = new double*[r];
  for(int x = 0; x<r; x++)
    matrix[x] = new double[c];
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c;j++)
    {
      matrix[i][j] = other.getmatrix()[i][j];
    }
  }
}

void Matrix::Gauss_Jordan(Matrix& other) {
  double **temp;
  temp = new double*[r];
  for(int i = 0; i<r;i++)
    temp[i] = new double[c];
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
     temp[i][j] = matrix[i][j];
    }
  }
  double **temp2;
  temp2 = new double*[other.getrows()];
  for(int i = 0; i<other.getrows();i++)
    temp2[i] = new double[other.getcols()];
  for(int i = 0; i < other.getrows(); i++)
  {
    for(int j = 0; j < other.getcols(); j++)
    {
     temp2[i][j] = other.getmatrix()[i][j];
    }
  }
  double scaler;
  double row[c];
  for(int x = 0; x < r; ++x)
  {
    if(!row_consistant(x,other))
    {
      std::cout<<"\nThe system is inconsistant"<<std::endl;
      return;
    }

    if(matrix[x][x] == 0)
    {
      bool swapped = switch_rows(x, other);
      if(!swapped)
        continue;
    }
    scaler = matrix[x][x];
    if(scaler != 0)
      scale_down_row(x, scaler, other);
    for(int a = 0; a < c; ++a)
      row[a] = matrix[x][a];
    for(int i = 0; i < r; ++i)
    {
      if(x != i)
      {
        double scale = matrix[i][x];
        subtract_rows(i, x, scale, row, other);
      }
    }
    display_matrix(other);
    }
  display_matrix(other);
  std::cout<<"\n";
  for(int i = 0; i < other.getrows(); i++)
   std::cout<<"x"<<i+1<<": "<<removeNegativeZero(other.getmatrix()[i][0])<<" ";
  std::cout<<"\n"<<std::endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            matrix[i][j] = temp[i][j];
        }
    }

    for(int i = 0; i < r; i++)
        delete [] temp[i];
    delete [] temp;
    temp = nullptr;

    for(int i = 0; i < other.getrows(); i++) {
        for(int j = 0; j < other.getcols(); j++) {
            other.getmatrix()[i][j] = temp2[i][j];
        }
    }

    for(int i = 0; i < other.getrows(); i++)
        delete [] temp2[i];
    delete [] temp2;
    temp2 = nullptr;
}

void Matrix::subtract_rows(int const& targetRow, int const& pivotRow, double const& scaler, double const rowContent[], Matrix& other) {
    for(int x = 0; x < c; ++x)
        matrix[targetRow][x] -= scaler * rowContent[x];
    other.matrix[targetRow][0] -= scaler * other.matrix[pivotRow][0];
}

void Matrix::scale_down_row(int const& row, double const& scaler, Matrix& other) {
    for(int y = 0; y < c; ++y)
        matrix[row][y] /= scaler;
    other.matrix[row][0] /= scaler;
}

bool Matrix::switch_rows(int const& pivotRow, Matrix& other) {
    for(int x = pivotRow + 1; x < r; ++x) {
        if(matrix[x][pivotRow] != 0) {
            for(int i = 0; i < c; ++i) {
                std::swap(matrix[pivotRow][i], matrix[x][i]);
            }
            std::swap(other.matrix[pivotRow][0], other.matrix[x][0]);
            return true;
        }
    }
    return false;
}

bool Matrix::row_consistant(int row, Matrix const& other)
{
  if(other.getmatrix()[row][0] != 0)
  {
    for(int x = 0; x<c; x++)
    {
      if(matrix[row][x] != 0)
        return true;
    }
      return false;
  }
  return true;
}

double removeNegativeZero(double num) {
    if (num == 0) {
        return 0; // Return positive zero if input is zero
    }
    return num; // Return input number if it's not zero
}
