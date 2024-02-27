#ifndef LINEAR_H
#define LINEAR_H

class Matrix
{
  public:
	Matrix(int r, int c);
	Matrix();
	~Matrix();
	void fill_matrix();
	void display_matrix();
	void transpose_matrix();
	double** getmatrix() const;
	int getrows() const;
	int getcols() const;
        void operator=(Matrix const& other);
	Matrix operator+(Matrix const& other);
        Matrix operator-(Matrix const& other);
        Matrix operator*(Matrix const& other);
	bool switch_rows(int const& pivotRow, Matrix& other);
	void rref(Matrix& other);
	void subtract_rows(int const& targetRow, int const& pivotRow, double const& scaler, double const rowContent[], Matrix& other);
	void scale_down_row(int const& row, double const& scaler, Matrix& other);
  private:
	int r;
	int c;
	double **matrix;
};
	double removeNegativeZero(double num);
#endif

